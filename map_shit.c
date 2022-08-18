#include "cub3d.h"

void map_shit(t_data *data, char *config)
{
	int fd = open(config, O_RDONLY);
	int max_l = 0;
	int max_h = 0;
	char *line = get_next_line(fd);
	while (1)
	{
		int i = 0;
		while (line[i] == ' ')
			i++;
		if (line[i] == '1' || line[i] == '0')
			break;
		else
			;
		line = get_next_line(fd);
	}
	// printf("%s\n\n", line);
	int i = 0;
	while (1)
	{
		max_h++;
		if (ft_strlen(line) >= max_l)
			max_l = ft_strlen(line);
		int j = 0;
		data->map->map[i] = ft_substr(line, 0, ft_strlen(line));
		line = get_next_line(fd);
		i++;
		if (!line)
			break;
	}
	data->map->max_y = max_h;
	check_content(data);
	// for (int i = 0; i < max_h; i++)
	// 	for (int j = 0; j < ft_strlen(data->map->map[i]); j++)
	// 		printf("%c", data->map->map[i][j]);
}

void check_content(t_data *data)
{
	int i;
	int j;
	int content[4]; //N - c[0] S - c[1] W - c[2] E - c[3] !(1 or 0) - c[4]
	
	i = 0;
	while (i <= 4)
	{
		content[i] = 0;
		i++;
	}
	i = 0;
	while (i < data->map->max_y)
	{
		j = 0;
		while (j < ft_strlen(data->map->map[i]))
		{
			if (data->map->map[i][j] == 'N')
			{
				data->plr.pos.x = (double)j;
				data->plr.pos.y = (double)i;
				data->plr.start_dir = 'N';
				content[0] = content[0] + 1;
				data->map->map[i][j] == '0';
			}
			else if (data->map->map[i][j] == 'S')
			{
				data->plr.pos.x = (double)j;
				data->plr.pos.y = (double)i;
				data->plr.start_dir = 'S';
				data->map->map[i][j] == '0';
				content[1] += 1;
			}
			else if (data->map->map[i][j] == 'W')
			{
				data->plr.pos.x = (double)j;
				data->plr.pos.y = (double)i;		
				data->plr.start_dir = 'W';
				data->map->map[i][j] == '0';
				content[2] += 1;
			}
			else if (data->map->map[i][j] == 'E')
			{
				data->plr.pos.x = (double)j;
				data->plr.pos.y = (double)i;
				data->plr.start_dir = 'E';
				data->map->map[i][j] == '0';
				content[3] += 1;
			}
			else if (data->map->map[i][j] == '1' || data->map->map[i][j] == '0' || data->map->map[i][j] == ' ' || data->map->map[i][j] == '\n' || data->map->map[i][j] == '\0')
				;
			else
				content[4] += 1;
			j++;
		}
		i++;
	}
	// printf("%d\n", data->plr.pos.y);
	// printf("%d\n", data->plr.pos.x);
	if (content[4] != 0)
		error_message("Error!\nUse for ur map: N, S, W, E, 1, 0\n");
	else if (content[0] == 1 && (content[1] != 0 || content[2] != 0 || content[3] != 0))
		error_message("Error!\nkill yourself\n");
	else if (content[1] == 1 && (content[0] != 0 || content[2] != 0 || content[3] != 0))
		error_message("Error!\nkill yourself\n");
	else if (content[2] == 1 && (content[0] != 0 || content[1] != 0 || content[3] != 0))
		error_message("Error!\nkill yourself\n");
	else if (content[3] == 1 && (content[0] != 0 || content[1] != 0 || content[2] != 0))
		error_message("Error!\nkill yourself\n");
	set_player_napr_pos(data);
	// printf("%d\n", data->plr.pos.y);
	// printf("%d\n", data->plr.pos.x);
}

void check_border(t_data *data)
{
	
}