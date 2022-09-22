/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:28:06 by ocapers           #+#    #+#             */
/*   Updated: 2022/09/03 17:53:34 by sdavos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast_three(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_x = data->plr.pos.y + ray->perp_wall_dist * ray->ray_dir.y;
	else
		ray->wall_x = data->plr.pos.x + ray->perp_wall_dist * ray->ray_dir.x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (double)ray->wall.width);
	if (ray->side == 0 && ray->ray_dir.x > 0)
		ray->tex_x = ray->wall.width - ray->tex_x - 1;
	if (ray->side == 1 && ray->ray_dir.y < 0)
		ray->tex_x = ray->wall.width - ray->tex_x - 1;
	ray->step = 1.0 * ray->wall.height / ray->line_height;
	ray->tex_pos = (ray->draw_start - WIN_HEIGHT \
	/ 2 + ray->line_height / 2) * ray->step;
}

void	raycast_four(t_data *data, t_ray *ray)
{
	while (ray->draw_start < ray->draw_end)
	{
		ray->tex_y = (int)ray->tex_pos & (ray->wall.height - 1);
		ray->tex_pos += ray->step;
		ray->color = *(unsigned int *)(ray->wall.pixel.addr \
		+ (ray->tex_x * ray->wall.pixel.bits_pixel \
		/ 8 + ray->tex_y * ray->wall.pixel.bits_line));
		put_pixel(&data->win->pixel, ray->x * 2, ray->draw_start, ray->color);
		put_pixel(&data->win->pixel, ray->x * 2 + 1, \
		ray->draw_start, ray->color);
		ray->draw_start++;
	}
}

void	init_raycast_help(t_data *data, t_ray *ray)
{
	ray->camera_x = 2 * ray->x / (double) RAYS - 1;
	ray->ray_dir.x = data->plr.dir.x + data->plr.plane.x * ray->camera_x;
	ray->ray_dir.y = data->plr.dir.y + data->plr.plane.y * ray->camera_x;
	ray->map_x = (int)data->plr.pos.x;
	ray->map_y = (int)data->plr.pos.y;
	ray->delta_dist.x = fabs(1 / ray->ray_dir.x);
	ray->delta_dist.y = fabs(1 / ray->ray_dir.y);
	ray->hit = 0;
}

void	init_raycast(t_data	*data, t_ray *ray)
{
	init_raycast_help(data, ray);
	if (ray->ray_dir.x < 0)
	{
		ray->step_x = -1;
		ray->side_dist.x = (data->plr.pos.x - ray->map_x) * ray->delta_dist.x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist.x = (ray->map_x + 1.0 - \
		data->plr.pos.x) * ray->delta_dist.x;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step_y = -1;
		ray->side_dist.y = (data->plr.pos.y - ray->map_y) * ray->delta_dist.y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist.y = (ray->map_y + 1.0 - \
		data->plr.pos.y) * ray->delta_dist.y;
	}
}
