/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:13:45 by ocapers           #+#    #+#             */
/*   Updated: 2022/09/16 19:05:25 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_for_color_2(char **dst, int count, int i)
{
	if ((dst[count][i] >= 48 && dst[count][i] <= 57) || \
		dst[count][i] == ' ' || dst[count][i] == '\n')
		;
	else
		error_message("format digit!");
}

void	error_for_color(t_data *data)
{
	if (data->colors.celling_red >= 256 || data->colors.celling_red < 0)
		error_message("Error\ncelling_red_color: 0 >= c <= 255\n");
	else if (data->colors.celling_green >= 256 || \
		data->colors.celling_green < 0)
		error_message("Error\ncelling_green_color: 0 >= c <= 255\n");
	else if (data->colors.celling_blue >= 256 || data->colors.celling_blue < 0)
		error_message("Error\ncelling_blue_color: 0 >= c <= 255\n");
	if (data->colors.floor_red >= 256 || data->colors.floor_red < 0)
		error_message("Error\nfloor_red_color: 0 >= c <= 255\n");
	else if (data->colors.floor_green >= 256 || data->colors.floor_green < 0)
		error_message("Error\nfloor_green_color: 0 >= c <= 255\n");
	else if (data->colors.floor_blue >= 256 || data->colors.floor_blue < 0)
		error_message("Error\nfloor_blue_color: 0 >= c <= 255\n");
}

void	errors_map(int *content)
{
	if (content[4] != 0)
		error_message("Error!\nUse for ur map: N, S, W, E, 1, 0\n");
	else if (content[0] == 1 && (content[1] != 0 \
	|| content[2] != 0 || content[3] != 0))
		error_message("Error!\nkill yourself\n");
	else if (content[1] == 1 && (content[0] != 0 \
	|| content[2] != 0 || content[3] != 0))
		error_message("Error!\nkill yourself\n");
	else if (content[2] == 1 && (content[0] != 0 \
	|| content[1] != 0 || content[3] != 0))
		error_message("Error!\nkill yourself\n");
	else if (content[3] == 1 && (content[0] != 0 \
	|| content[1] != 0 || content[2] != 0))
		error_message("Error!\nkill yourself\n");
}
