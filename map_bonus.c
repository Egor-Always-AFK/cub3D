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

#include "cub3d_bonus.h"

void	get_img_minimap(t_data *data)
{
	data->minimap.img = mlx_new_image(data->win->mlx,
			MMAP_WIDTH * SCALE, MMAP_HEIGH * SCALE);
	data->minimap.addr = mlx_get_data_addr(data->minimap.img,
			&data->minimap.bits_pixel,
			&data->minimap.bits_line, &data->minimap.end);
}

void	draw_point(t_data *data, int color, int x, int y)
{
	int		start_x;
	int		start_y;
	char	*put;

	start_y = y;
	while (start_y < POINT_SIZE + y)
	{
		start_x = x;
		while (start_x < POINT_SIZE + x)
		{
			if (start_x >= 0 && start_x < WIN_LENGHT && \
				start_y >= 0 && start_y < WIN_HEIGHT)
			{
				put = data->minimap.addr + (start_y * data->minimap.bits_line \
				+ start_x * (data->minimap.bits_pixel / 8));
				*(unsigned int *)put = color;
			}
			start_x++;
		}
		start_y++;
	}
}

void	ft_minimap_two(t_data *data, int y, int x)
{
	int	color;

	if (data->map.map[y][x] == '1')
	{
		color = WALL_COLOR;
		draw_point(data, color, x * POINT_SIZE, y * POINT_SIZE);
	}
	if (data->map.map[y][x] == '0')
	{
		color = SPACE_COLOR;
		draw_point(data, color, x * POINT_SIZE, y * POINT_SIZE);
	}
	if (data->map.map[y][x] == '5')
	{
		color = GREEN;
		draw_point(data, color, x * POINT_SIZE, y * POINT_SIZE);
	}
}

void	ft_minimap(t_data *data)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < (unsigned int)data->map.height)
	{
		x = 0;
		while (x < (unsigned int)data->map.length)
		{
			ft_minimap_two(data, y, x);
			x++;
		}
		y++;
	}
	draw_point(data, PLAYER_COLOR,
		(int)data->plr.pos.x * POINT_SIZE, (int)data->plr.pos.y * POINT_SIZE);
	mlx_put_image_to_window(data->win->mlx, data->win->window,
		data->minimap.img, 0,
		WIN_HEIGHT - MMAP_HEIGH * 77.5);
}
