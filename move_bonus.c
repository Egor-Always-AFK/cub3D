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

void	move_left_right_two(t_data *data, double sin_cub, double cos_cub)
{
	if (data->key.right_key == TRUE)
	{
		if (data->map.map[(int)data->plr.pos.y]
			[(int)(data->plr.pos.x - data->plr.dir.y * SPEED_P)] == '0'
				|| data->map.map[(int)data->plr.pos.y][(int)(data->plr.pos.x
					- data->plr.dir.y * SPEED_P)] == '6')
			data->plr.pos.x += -SPEED_P * sin_cub;
		if (data->map.map[(int)(data->plr.pos.y + data->plr.dir.x * SPEED_P)]
			[(int)data->plr.pos.x] == '0'
				|| data->map.map[(int)(data->plr.pos.y
					+ data->plr.dir.x * SPEED_P)]
				[(int)data->plr.pos.x] == '6')
			data->plr.pos.y += SPEED_P * cos_cub;
	}
}

void	move_left_right(t_data *data)
{
	double	sin_cub;
	double	cos_cub;

	sin_cub = sin(data->plr.rot);
	cos_cub = cos(data->plr.rot);
	if (data->key.left_key == TRUE)
	{
		if (data->map.map[(int)data->plr.pos.y]
			[(int)(data->plr.pos.x + data->plr.dir.y * SPEED_P)] == '0'
				|| data->map.map[(int)data->plr.pos.y]
					[(int)(data->plr.pos.x + data->plr.dir.y * SPEED_P)] == '6')
			data->plr.pos.x += SPEED_P * sin_cub;
		if (data->map.map[(int)(data->plr.pos.y - data->plr.dir.x * SPEED_P)]
			[(int)data->plr.pos.x] == '0' || data->map.map[(int)(data->plr.pos.y
				- data->plr.dir.x * SPEED_P)][(int)data->plr.pos.x] == '6')
			data->plr.pos.y += -SPEED_P * cos_cub;
	}
	move_left_right_two(data, sin_cub, cos_cub);
}

void	rotation(t_data *data)
{
	double	old_plane;

	if (data->key.right == TRUE)
	{
		old_plane = data->plr.plane.x;
		data->plr.plane.x = data->plr.plane.x * \
		cos(SPEED_R) - data->plr.plane.y * sin(SPEED_R);
		data->plr.plane.y = old_plane * sin(SPEED_R) + \
		data->plr.plane.y * cos(SPEED_R);
		data->plr.rot += SPEED_R;
	}
	if (data->key.left == TRUE)
	{
		old_plane = data->plr.plane.x;
		data->plr.plane.x = data->plr.plane.x * \
		cos(-SPEED_R) - data->plr.plane.y * sin(-SPEED_R);
		data->plr.plane.y = old_plane * sin(-SPEED_R) + \
		data->plr.plane.y * cos(-SPEED_R);
		data->plr.rot -= SPEED_R;
	}
}

void	mouse_rotation_two(int x, t_data *data)
{
	double	old_plane;

	if (x > data->mouse)
	{
		old_plane = data->plr.plane.x;
		data->plr.plane.x = data->plr.plane.x * cos(SPEED_R_M)
			- data->plr.plane.y * sin(SPEED_R_M);
		data->plr.plane.y = old_plane * sin(SPEED_R_M)
			+ data->plr.plane.y * cos(SPEED_R_M);
		data->plr.rot += SPEED_R_M;
	}
	if (x < data->mouse)
	{
		old_plane = data->plr.plane.x;
		data->plr.plane.x = data->plr.plane.x * cos(-SPEED_R_M)
			- data->plr.plane.y * sin(-SPEED_R_M);
		data->plr.plane.y = old_plane * sin(-SPEED_R_M)
			+ data->plr.plane.y * cos(-SPEED_R_M);
		data->plr.rot -= SPEED_R_M;
	}
	data->mouse = x;
}

int	mouse_rotation(int x, int y, t_data *data)
{
	if (x < 0)
	{
		x = 0;
		mlx_mouse_show();
	}
	else if (x > WIN_LENGHT)
	{
		x = WIN_LENGHT;
		mlx_mouse_show();
	}
	else if (y < -15)
		mlx_mouse_show();
	else if (y > 1064)
		mlx_mouse_show();
	else
		mlx_mouse_hide();
	if (y >= 2 && y <= 1064 && x >= 0 && x <= WIN_LENGHT)
		mouse_rotation_two(x, data);
	return (0);
}
