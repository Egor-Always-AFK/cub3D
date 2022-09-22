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

void	move_up_down_two(t_data *data, double sin_cub, double cos_cub)
{
	if (data->key.up_key == TRUE)
	{
		if (data->map.map[(int)data->plr.pos.y]
			[(int)(data->plr.pos.x + data->plr.dir.x * SPEED_P)] == '0'
			|| data->map.map[(int)data->plr.pos.y]
				[(int)(data->plr.pos.x + data->plr.dir.x * SPEED_P)] == '6')
			data->plr.pos.x += SPEED_P * cos_cub;
		if (data->map.map[(int)(data->plr.pos.y + data->plr.dir.y * SPEED_P)]
			[(int)data->plr.pos.x] == '0' ||
			data->map.map[(int)(data->plr.pos.y + data->plr.dir.y * SPEED_P)]
				[(int)data->plr.pos.x] == '6')
			data->plr.pos.y += SPEED_P * sin_cub;
	}
}

void	move_up_down(t_data *data)
{
	double	sin_cub;
	double	cos_cub;

	sin_cub = sin(data->plr.rot);
	cos_cub = cos(data->plr.rot);
	if (data->key.down_key == TRUE)
	{
		if (data->map.map[(int)data->plr.pos.y]
			[(int)(data->plr.pos.x - data->plr.dir.x * SPEED_P)]
			== '0' || data->map.map[(int)data->plr.pos.y]
			[(int)(data->plr.pos.x - data->plr.dir.x * SPEED_P)] == '6')
			data->plr.pos.x += -SPEED_P * cos_cub;
		if (data->map.map[(int)(data->plr.pos.y - data->plr.dir.y * SPEED_P)]
			[(int)data->plr.pos.x] == '0' ||
				data->map.map[(int)(data->plr.pos.y
				- data->plr.dir.y * SPEED_P)]
			[(int)data->plr.pos.x] == '6')
			data->plr.pos.y += -SPEED_P * sin_cub;
	}
	move_up_down_two(data, sin_cub, cos_cub);
}
