/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:35:48 by ocapers           #+#    #+#             */
/*   Updated: 2022/09/03 18:42:27 by sdavos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	pars_color_help(t_data *data, char *line, int i, int *count)
{
	if (line[i] == 'F' && line[i + 1] == ' ')
	{
		pars_color(data, line, i + 2, 0);
		count[4] += 1;
		return ;
	}
	else if (line[i] == 'C' && line[i + 1] == ' ')
	{
		pars_color(data, line, i + 2, 1);
		count[5] += 1;
		return ;
	}
}

void	pars_anim_wall_xpm(t_data *data, int counter)
{
	pars_fire_walls(data, "anim/fire2.xpm", &data->walls[5]);
	pars_fire_walls(data, "anim/fire3.xpm", &data->walls[6]);
	counter += 1;
}

void	key_help_2(t_data *data)
{
	if (data->key.gun == TRUE)
	{
		mlx_put_image_to_window(data->win->mlx, data->win->window, \
		data->minimap.img, 0, WIN_HEIGHT - MMAP_HEIGH * 77.5);
		mlx_put_image_to_window(data->win->mlx, data->win->window, \
		data->anims.guns_imgs[data->anims.anim_gun / 2], WIN_LENGHT * 0.4 + 5, \
		WIN_HEIGHT - data->anims.y[data->anims.anim_gun / 2]);
		data->anims.anim_gun++;
		if (data->anims.anim_gun == 25)
			data->anims.anim_gun = 0;
	}
	if (data->key.esc == TRUE)
		ft_close(data);
}

char	*skip_for_map_1(int fd)
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
			free(line);
			break ;
		}
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}
