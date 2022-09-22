/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:13:45 by ocapers           #+#    #+#             */
/*   Updated: 2022/09/09 14:12:49 by sdavos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_h(t_data *data, char *config)
{
	int		fd;
	char	*line;

	fd = open(config, O_RDONLY);
	line = get_next_line(fd);
	free(line);
	line = skip_for_map(fd);
	while (line)
	{
		data->map.height++;
		free(line);
		line = get_next_line(fd);
		if (!line || *line == '\n' || *line == '\0')
		{
			free(line);
			close(fd);
			break ;
		}
	}
	close(fd);
	free(line);
}

void	get_l(t_data *data, char *config, char *line)
{
	int		i;
	int		fd;

	i = 0;
	fd = open(config, O_RDONLY);
	line = skip_for_map(fd);
	while (1)
	{
		data->map.map[i] = ft_substr(line, 0, ft_strlen(line));
		free(line);
		line = get_next_line(fd);
		i++;
		if (!line || *line == '\n' || *line == '\0')
		{
			free(line);
			close(fd);
			break ;
		}
	}
	free(line);
}

const char	*f_strchr(const char *s, int c)
{
	c = (unsigned char)c;
	while (*s != c)
	{
		if (*s == '\0')
			return ((void *)0);
		s++;
	}
	return ((char *)s);
}

int	set_pos(t_data *data, int i, int j, int content)
{
	data->plr.pos.x = (double)j + 0.5;
	data->plr.pos.y = (double)i + 0.5;
	data->map.map[i][j] = '0';
	content += 1;
	return (content);
}

void	set_dir_rot_plane(t_data *data, int i, int j)
{
	char	*sim;

	sim = "ESWN";
	data->plr.rot = M_PI_2 * (f_strchr(sim, data->map.map[i][j]) - sim);
	data->plr.dir.x = cos(data->plr.rot);
	data->plr.dir.y = sin(data->plr.rot);
	data->plr.plane.x = -FOV * (int)data->plr.dir.y;
	data->plr.plane.y = FOV * (int)data->plr.dir.x;
}
