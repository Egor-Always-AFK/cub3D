/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:13:45 by ocapers           #+#    #+#             */
/*   Updated: 2022/09/16 19:41:16 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	map_shit(t_data *data, char *config)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	get_h(data, config);
	fd = open(config, O_RDONLY);
	line = skip_for_map_1(fd);
	data->map.map = (char **)malloc(sizeof(char *) * data->map.height);
	while (i < data->map.height)
	{
		if (ft_strlen(line) >= data->map.length)
			data->map.length = ft_strlen(line);
		data->map.map[i] = ft_substr(line, 0, ft_strlen(line));
		line = get_next_line(fd);
		i++;
		free(line);
	}
	close(fd);
	free(line);
	check_content(data);
	check_border(data);
}

void	check_content_two(t_data *data, int i, int j, int *content)
{
	if (f_strchr("ESWN", data->map.map[i][j]))
	{
		set_dir_rot_plane(data, i, j);
		if (data->map.map[i][j] == 'N')
			content[0] = set_pos(data, i, j, content[0]);
		else if (data->map.map[i][j] == 'S')
			content[1] = set_pos(data, i, j, content[1]);
		else if (data->map.map[i][j] == 'W')
			content[2] = set_pos(data, i, j, content[2]);
		else if (data->map.map[i][j] == 'E')
			content[3] = set_pos(data, i, j, content[3]);
	}
	else if (data->map.map[i][j] == '1' || data->map.map[i][j] == '0' \
		|| data->map.map[i][j] == '5' || data->map.map[i][j] == ' ' \
		|| data->map.map[i][j] == '\n' || data->map.map[i][j] == '\0')
		;
	else
		content[4] += 1;
}

void	check_content(t_data *data)
{
	int	i;
	int	j;
	int	content[5];

	i = 0;
	while (i <= 5)
	{
		content[i] = 0;
		i++;
	}
	i = 0;
	data->plr.rot = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (j < ft_strlen(data->map.map[i]))
		{
			check_content_two(data, i, j, content);
			j++;
		}
		i++;
	}
	errors_map(content);
}

void	check_border_two(t_data *data, int i, int j)
{
	if (data->map.map[i - 1][j] == ' '\
	|| data->map.map[i + 1][j] == ' ' \
	|| j > ft_strlen(data->map.map[i - 1]) - 1 \
	|| data->map.map[i][j + 1] == ' ' \
	|| data->map.map[i][j - 1] == ' ' \
	|| j > ft_strlen(data->map.map[i + 1]) - 1 \
	||data->map.map[i][j + 1] == '\n' \
	|| data->map.map[i + 1][j + 1] == ' ' \
	|| data->map.map[i + 1][j + 1] == '\n' \
	|| data->map.map[i + 1][j - 1] == ' ' \
	|| data->map.map[i + 1][j - 1] == '\n' \
	|| data->map.map[i - 1][j + 1] == ' ' \
	|| data->map.map[i - 1][j + 1] == '\n' \
	|| data->map.map[i - 1][j - 1] == ' ' \
	|| data->map.map[i - 1][j - 1] == '\n')
		error_message("Error!\nMap must be closed\n", data);
}

void	check_border(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (i == 0 || i == (data->map.height - 1))
			{
				if (data->map.map[i][j] != '1' && data->map.map[i][j] != ' ' \
				&& data->map.map[i][j] != '\0' && data->map.map[i][j] != '\n')
					error_message("Error!\nMap must be closed\n", data);
			}
			else if (data->map.map[i][j] == '0')
			{
				check_border_two(data, i, j);
			}
			j++;
		}
		i++;
	}
}
