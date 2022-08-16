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
	// data->map->map = ft_calloc(100000, sizeof(char *));
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
	for (int i = 0; i < max_h; i++)
		for (int j = 0; j < ft_strlen(data->map->map[i]); j++)
			printf("%c", data->map->map[i][j]);
}