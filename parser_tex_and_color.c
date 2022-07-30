#include "cub3d.h"

void parser_for_text(t_data *data, char *name)
{
	int i;
	int counter = 0;
	int count[5]; // 0 - NO; 1 - SO; 2 - WE; 3 - EA; 4 - F; 5 - C
	char *line;
	int fd = open(name, O_RDONLY);
	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	count[3] = 0;
	if (fd == -1)
		error_message("Wow i can't open this conf :'c\n");
	line = get_next_line(fd);
	while (counter != 5)
	{
		i = 0;
		if (count[0] > 1 || count[1] > 1 || count[2] > 1 || count[3] > 1)
			error_message("parsing error!\nBad text.");
		while (line[i] != '\n')
		{
			if (line[i] == ' ')
				i++;
			else if (line[i] == 'N' && line[i + 1] == 'O')
			{
				pars_textures(data, line, i + 2, 0);
				count[0] += 1;
				counter += 1;
				break;
			}
			else if (line[i] == 'S' && line[i + 1] == 'O')
			{
				pars_textures(data, line, i + 2, 1);
				count[1] += 1;
				counter += 1;
				break;
			}
			else if (line[i] == 'W' && line[i + 1] == 'E')
			{
				pars_textures(data, line, i + 2, 2);
				count[2] += 1;
				counter += 1;
				break;
			}
			else if(line[i] == 'E' && line[i + 1] == 'A')
			{
				pars_textures(data, line, i + 2, 3);
				count[3] += 1;
				counter += 1;
				break;
			}
			else if(line[i] == 'F' && line[i + 1] == ' ')
			{
				pars_color(data, line, i + 2, 0);
				count[4] += 1;
				counter += 1;
				// printf("\n\n%d\n\n", counter);
				break;
			}
		}
		line = get_next_line(fd);
	}
	if (count[0] != 1 || count[1] != 1 || count[2] != 1 || count[3] != 1)
		error_message("parsing error!");
}

void pars_color(t_data *data, char *line, int counter, int path)
{
	int i = counter;
	int j;
	int count = 0;
	char col[3];

	if (path == 0)
	{
		while(line[i] == ' ')
			i++;
		while (count != 2)
		{
			j = 0;
			while (j != 3)
			{
				col[j] = line[i];
				j++;
				i++;
			}
			if (count == 0)
				data->colors.floor_red = ft_atoi(col);
			else if (count == 1)
				data->colors.floor_green = ft_atoi(col);
			else
				data->colors.floor_blue = ft_atoi(col);
			/*
			добавить проверку на трехзначность числа(на моменте парсинга char*)
			*/
			if (data->colors.floor_red >= 256 || data->colors.floor_red < 0)
				error_message("error\ncolor: 0 >= c <= 255\n");
			else if (data->colors.floor_green >= 256 || data->colors.floor_green < 0)
				error_message("error\ncolor: 0 >= c <= 255\n");
			else if (data->colors.floor_blue >= 256 || data->colors.floor_blue < 0)
				error_message("error\ncolor: 0 >= c <= 255\n");
			count++;
			i++;
		}
	}
	else
	{
		while (line[i] == ' ')
			i++;
		while (count != 2)
		{
			j = 0;
			while (j != 3)
			{
				col[j] = line[i];
				j++;
				i++;
			}
			if (count == 0)
				data->colors.celling_red = ft_atoi(col);
			else if (count == 1)
				data->colors.celling_green = ft_atoi(col);
			else
				data->colors.celling_blue = ft_atoi(col);
			/*
			добавить проверку на трехзначность числа(на моменте парсинга char*)
			*/
			if (data->colors.celling_red >= 256 || data->colors.celling_red < 0)
				error_message("error\ncolor: 0 >= c <= 255");
			else if (data->colors.celling_green >= 256 || data->colors.celling_green < 0)
				error_message("error\ncolor: 0 >= c <= 255");
			else if (data->colors.celling_blue >= 256 || data->colors.celling_blue < 0)
				error_message("error\ncolor: 0 >= c <= 255");
			count++;
			i++;
		}
	}
	// printf("red:%d\nblue:%d\ngreen:%d\n", data->colors.floor_red, data->colors.floor_blue, data->colors.floor_green);
}

void pars_textures(t_data *data, char *line, int counter, int path)
{
	int length = 0;
	int height = 0;
	if(line[counter] == ' ')
		while(line[counter] == ' ')
			counter++;
	if (ft_strnstr(&line[ft_strlen(line) - 5], ".xpm", 5) == NULL)
		error_message("map is not .xpm\n");

	/*
	как запустить mlx???????????????????
	*/
	
	// int fd;
	// // fd = open(line, O_RDONLY);
	// // if (fd == -1)
	// // 	error_message("file not exist!\n");
	// if (path == 0)
	// 	printf("%s\n\n", line);
	// 	// data->imgs->textures_north = mlx_xpm_file_to_image(data->mlx, line, &length, &height);
	// else if (path == 1)
	// 	printf("%s\n\n", line);
	// 	// data->imgs->textures_south = mlx_xpm_file_to_image(data->mlx, line, &length, &height);
	// else if (path == 2)
	// 	printf("%s\n\n", line);
	// 	// data->imgs->textures_west = mlx_xpm_file_to_image(data->mlx, line, &length, &height);
	// else if (path == 3)
	// 	printf("%s\n\n", line);
	// 	// data->imgs->textures_east = mlx_xpm_file_to_image(data->mlx, line, &length, &height);
}