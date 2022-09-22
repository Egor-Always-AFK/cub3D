/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:35:48 by ocapers           #+#    #+#             */
/*   Updated: 2022/09/16 19:04:49 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pars_color_help(t_data *data, char *line, int i, int *count)
{
	if (line[i] == 'F' && line[i + 1] == ' ')
	{
		pars_color(data, line, 1);
		count[4] += 1;
		return ;
	}
	else if (line[i] == 'C' && line[i + 1] == ' ')
	{
		pars_color(data, line, 0);
		count[5] += 1;
		return ;
	}
}

void	key_help_2(t_data *data)
{
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
