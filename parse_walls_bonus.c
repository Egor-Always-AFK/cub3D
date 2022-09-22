/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_walls_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:13:45 by ocapers           #+#    #+#             */
/*   Updated: 2022/09/16 19:49:34 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	bzero_for_array(int *array, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		array[i] = 0;
		i++;
	}
}

void	error_for_text(int *count)
{
	if (count[0] != 1 || count[1] != 1 || count[2] != 1 || \
		count[3] != 1)
		error_message("Error!\nUse only once NO, WE, EA, SO, F, C!", NULL);
}

void	pars_wall(t_data *data, char *line, t_imgs *wall)
{
	int	i;

	i = ft_strlen(line);
	line[i - 1] = '\0';
	wall->pixel.img = mlx_xpm_file_to_image(data->win->mlx,
			line, &wall->width, &wall->height);
	if (!wall->pixel.img)
		error_message("error of xpm\n", data);
	wall->pixel.addr = (unsigned int *)mlx_get_data_addr(wall->pixel.img,
			&wall->pixel.bits_pixel, &wall->pixel.bits_line, &wall->pixel.end);
	if (!wall->pixel.addr)
		error_message("error of addr wall\n", data);
}

void	pars_fire_walls(t_data *data, char *line, t_imgs *wall)
{
	wall->pixel.img = mlx_xpm_file_to_image(data->win->mlx,
			line, &wall->width, &wall->height);
	if (!wall->pixel.img)
		error_message("error of xpm wall\n", data);
	wall->pixel.addr = (unsigned int *)mlx_get_data_addr(wall->pixel.img,
			&wall->pixel.bits_pixel, &wall->pixel.bits_line, &wall->pixel.end);
	if (!wall->pixel.addr)
		error_message("error of addr wall\n", data);
}

char	*skip_for_map(int fd)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		if (line[i] == ' ')
		{
			while (line[i] == ' ')
				i++;
		}
		if (line[i] == '1' || line[i] == '0')
		{
			break ;
		}
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}
