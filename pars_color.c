/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:13:45 by ocapers           #+#    #+#             */
/*   Updated: 2022/09/16 19:03:13 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pars_floor(t_data *data, char *line)
{
	char	**dst;
	int		i;
	int		count;

	count = 0;
	i = 0;
	dst = ft_split(line, ',');
	while (count <= 2)
	{
		while (dst[count][i] != '\0')
		{
			error_for_color_2(dst, count, i);
			i++;
		}
		if (count == 0)
			data->colors.floor_red = ft_atoi(dst[count]);
		else if (count == 1)
			data->colors.floor_green = ft_atoi(dst[count]);
		else
			data->colors.floor_blue = ft_atoi(dst[count]);
		free(dst[count]);
		count++;
	}
	data->floor = (data->colors.floor_red << 16 | \
		data->colors.floor_green << 8 | data->colors.floor_blue);
}

void	pars_celling(t_data *data, char *line)
{
	char	**dst;
	int		i;
	int		count;

	count = 0;
	i = 0;
	dst = ft_split(line, ',');
	while (count <= 2)
	{
		while (dst[count][i] != '\0')
		{
			error_for_color_2(dst, count, i);
			i++;
		}
		if (count == 0)
			data->colors.celling_red = ft_atoi(dst[count]);
		else if (count == 1)
			data->colors.celling_green = ft_atoi(dst[count]);
		else
			data->colors.celling_blue = ft_atoi(dst[count]);
		free(dst[count]);
		count++;
	}
	data->ceil = (data->colors.celling_red << 16 | \
		data->colors.celling_green << 8 | data->colors.celling_blue);
}

void	pars_color(t_data *data, char *line, int path)
{
	char	*copy;

	copy = line;
	copy[0] = ' ';
	if (path == 0)
		pars_floor(data, copy);
	else
		pars_celling(data, copy);
	free(copy);
	error_for_color(data);
}
