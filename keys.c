/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:55:07 by ocapers           #+#    #+#             */
/*   Updated: 2022/09/16 18:58:50 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handler_keys(int key, t_data *data)
{
	if (key == UP_KEY)
		data->key.up_key = TRUE;
	else if (key == DOWN_KEY)
		data->key.down_key = TRUE;
	else if (key == LEFT_KEY)
		data->key.left_key = TRUE;
	else if (key == RIGHT_KEY)
		data->key.right_key = TRUE;
	else if (key == LEFT)
		data->key.left = TRUE;
	else if (key == RIGHT)
		data->key.right = TRUE;
	else if (key == ESC)
		data->key.esc = TRUE;
	return (0);
}

int	non_handler_keys(int key, t_data *data)
{
	if (key == UP_KEY)
		data->key.up_key = FALSE;
	else if (key == DOWN_KEY)
		data->key.down_key = FALSE;
	else if (key == LEFT_KEY)
		data->key.left_key = FALSE;
	else if (key == RIGHT_KEY)
		data->key.right_key = FALSE;
	else if (key == LEFT)
		data->key.left = FALSE;
	else if (key == RIGHT)
		data->key.right = FALSE;
	else if (key == ESC)
		data->key.esc = FALSE;
	return (0);
}

int	keys(t_data *data)
{
	t_ray	ray;

	ray.x = 0;
	data->plr.dir.x = cos(data->plr.rot);
	data->plr.dir.y = sin(data->plr.rot);
	ft_memcpy(data->win->pixel.addr, data->floor_ceil.addr, \
	WIN_HEIGHT * WIN_LENGHT * (data->win->pixel.bits_pixel / 8));
	keys_help(ray, data, 0);
	mlx_clear_window(data->win->mlx, data->win->window);
	mlx_put_image_to_window(data->win->mlx, data->win->window, \
	data->win->pixel.img, 0, 0);
	keys_help(ray, data, 1);
	keys_help(ray, data, 2);
	move_up_down(data);
	move_left_right(data);
	rotation(data);
	return (0);
}

void	keys_help(t_ray ray, t_data *data, int path)
{
	if (path == 0)
	{
		while (ray.x < RAYS)
		{
			init_raycast(data, &ray);
			while (!ray.hit)
				raycast(data, &ray);
			raycast_two(&ray);
			raycast_three(data, &ray);
			raycast_four(data, &ray);
			ray.x++;
		}
	}
	else if (path == 1)
	{
		if (data->key.space == TRUE)
		{
			mlx_put_image_to_window(data->win->mlx, data->win->window, \
			data->win->pixel.img, 0, 0);
			mlx_put_image_to_window(data->win->mlx, data->win->window, \
			data->minimap.img, 0, WIN_HEIGHT - MMAP_HEIGH * 77.5);
		}
	}
	else if (path == 2)
		key_help_2(data);
}
