/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:13:45 by ocapers           #+#    #+#             */
/*   Updated: 2021/11/18 14:13:52 by sdavos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast_help(t_data *data, t_ray *ray)
{
	ray->hit = 1;
	if (ray->side == 0 && ray->ray_dir.x > 0)
		ray->wall = data->walls[3];
	else if (ray->side == 0 && ray->ray_dir.x <= 0)
		ray->wall = data->walls[2];
	else if (ray->side == 1 && ray->ray_dir.y > 0)
		ray->wall = data->walls[1];
	else if (ray->side == 1 && ray->ray_dir.y <= 0)
		ray->wall = data->walls[0];
}

void	raycast(t_data *data, t_ray *ray)
{
	if (ray->side_dist.x < ray->side_dist.y)
	{
		ray->side_dist.x += ray->delta_dist.x;
		ray->map_x += ray->step_x;
		ray->side = 0;
	}
	else
	{
		ray->side_dist.y += ray->delta_dist.y;
		ray->map_y += ray->step_y;
		ray->side = 1;
	}
	if (data->map.map[ray->map_y][ray->map_x] == '1')
		raycast_help(data, ray);
}

void	raycast_two(t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist.x - ray->delta_dist.x;
	else
		ray->perp_wall_dist = ray->side_dist.y - ray->delta_dist.y;
	ray->line_height = (int)WIN_HEIGHT / ray->perp_wall_dist;
	ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
}
