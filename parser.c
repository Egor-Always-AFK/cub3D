#include "cub3d.h"

int lenght_count(int fd)
{
	char	buffer[1];
	int		length;
	int		bytes;

	buffer[0] = '\0';
	bytes = 1;
	length = 0;
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (buffer[0] != '\n')
			length++;
		else
			break ;
	}
	return (length);
}

int height_count(int fd, int map_lenght)
{
	char *line;
	int lines;
	int out;

	lines = 1;
	out = 0;
	while (TRUE)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		if (ft_strlen(line) < map_lenght
			|| (ft_strlen(line) == 1 && *line != '\n'))
		{
			free (line);
			error_message("Error!\n");
		}
		else
		{
			free(line);
			lines++;
		}
	}
	return (lines);
}

void parse_input(t_data *data, char **argv)
{
	int		fd;
	int		i;
	int		bytes;
	char	buffer[2];

	i = 0;
	bytes = 1;
	buffer[1] = '\0';
	fd = open(argv[1], O_RDONLY);
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (bytes != 1)
			break ;
		if (buffer[0] != '\n' && buffer[0] != '\0')
		{
			data->map->map[i] = ft_strjoin(data->map->map[i], buffer);
		}
		else
			i++;
	}
	check_content(data);
	check_border(data);
}

void check_contentidk(t_data *data)
{
	int i;
	int player;

	i = 0;
	player = 0;
	while (data->map->map != NULL && data->map->map[i] != NULL)
	{
		player += counter_for_map(data->map->map[i], 'N');
		player += counter_for_map(data->map->map[i], 'S');
		player += counter_for_map(data->map->map[i], 'E');
        player += counter_for_map(data->map->map[i], 'W');
		i++;
	}
	if (player != 1)
		error_message("Error!\nYour map is not valid!");
}

void check_border(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->height)
	{
		// if (ft_strlen(data->map->map[i]) != data->length)
		// 	error_message("Error!\nYour map is not rectangular!");
		j = 0;
		while (j < data->length)
		{
			if (data->map->map[i][j] != '0' && data->map->map[i][j] != '1' &&
				data->map->map[i][j] != 'N' && data->map->map[i][j] != 'S' &&
				data->map->map[i][j] != 'E' && data->map->map[i][j] != 'W')
				error_message("Error!\nUse for your map: '0', '1', 'N', 'S', 'E', 'W'");
			else if ((i == 0 || j == 0) && data->map->map[i][j] != '1')
				error_message("Error!\nYour map has to be surrounded by walls\n");
			else if ((j == data->length - 1) && data->map->map[i][j] != '1')
				error_message("Error!\nYour map has to be surrounded by walls\n");
			else if((i == data->height - 1) && data->map->map[i][j] != '1')
				error_message("Error!\nYour map has to be surrounded by walls\n");
			j++;
		}
		i++;
	}
}