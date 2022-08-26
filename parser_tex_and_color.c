#include "cub3d.h"

void parser_for_text(t_data *data, char *name)
{
	int i;
	int counter = 0;
	int count[6]; // 0 - NO; 1 - SO; 2 - WE; 3 - EA; 4 - F; 5 - C; 6 - other
	char *line;
	int fd = open(name, O_RDONLY);
	i = 0;
	while (i <= 6)
	{
		count[i] = 0;
		i++;
	}
	if (fd == -1)
		error_message("Wow i can't open this conf :'c\n");
	line = get_next_line(fd);
	// printf("aaaa\n");
	while (count[6] == 0)
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
				// pars_textures(data, line, i + 2, 0);
				parse_texture_2(data, &data->imgs->textures_north, line + 2, counter + 2);
				count[0] += 1;
				counter += 1;
				break;
			}
			else if (line[i] == 'S' && line[i + 1] == 'O')
			{
				// pars_textures(data, line, i + 2, 1);
				parse_texture_2(data, &data->imgs->textures_south, line + 2, counter + 2);
				count[1] += 1;
				counter += 1;
				break;
			}
			else if (line[i] == 'W' && line[i + 1] == 'E')
			{
				// pars_textures(data, line, i + 2, 2);
				parse_texture_2(data, &data->imgs->textures_west, line + 2, counter + 2);
				count[2] += 1;
				counter += 1;
				break;
			}
			else if (line[i] == 'E' && line[i + 1] == 'A')
			{
				// pars_textures(data, line, i + 2, 3);
				parse_texture_2(data, &data->imgs->textures_east, line + 2, counter + 2);
				count[3] += 1;
				counter += 1;
				break;
			}
			else if (line[i] == 'F' && line[i + 1] == ' ')
			{
				pars_color(data, line, i + 2, 0);
				count[4] += 1;
				counter += 1;
				break;
			}
			else if (line[i] == 'C' && line[i + 1] == ' ')
			{
				pars_color(data, line, i + 2, 1);
				count[5] += 1;
				counter += 1;
				break;
			}
			else if (line[i] == '1')
			{
				count[6] += 1;
				break;
			}
		}
		line = get_next_line(fd);
	}
	if (count[0] != 1 || count[1] != 1 || count[2] != 1 || count[3] != 1)
		error_message("parsing error!");
	/*
	раписать каждую ошибку(когда ошибка кол-ва цвета или текстур)
	*/
}

void pars_color(t_data *data, char *line, int counter, int path)
{
	char **dst;
	char *copy;
	int count = 0;
	int i = 0;

	copy = line;
	copy[0] = ' ';
	if (path == 0)
	{
		dst = ft_split(copy, ',');
		while (count <= 2)
		{
			while (dst[count][i] != '\0')
			{
				if ((dst[count][i] >= 48 && dst[count][i] <= 57) || dst[count][i] == ' ' || dst[count][i] == '\n')
					;
				else
					error_message("format digit!");
				i++;
			}
			if (count == 0)
				data->colors.floor_red = ft_atoi(dst[count]);
			else if (count == 1)
				data->colors.floor_green = ft_atoi(dst[count]);
			else
				data->colors.floor_blue = ft_atoi(dst[count]);
			count++;
		}
		if (data->colors.floor_red >= 256 || data->colors.floor_red < 0)
			error_message("error\nfloor_red_color: 0 >= c <= 255\n");
		else if (data->colors.floor_green >= 256 || data->colors.floor_green < 0)
			error_message("error\nfloor_green_color: 0 >= c <= 255\n");
		else if (data->colors.floor_blue >= 256 || data->colors.floor_blue < 0)
			error_message("error\nfloor_blue_color: 0 >= c <= 255\n");
		// data->map->floor = (data->colors.floor_red << 16 | data->colors.floor_green << 8 | data->colors.floor_blue);
		data->floor = (data->colors.floor_red << 16 | data->colors.floor_green << 8 | data->colors.floor_blue);
	}
	else
	{
		dst = ft_split(copy, ',');
		while (count <= 2)
		{
			while (dst[count][i] != '\0')
			{
				if ((dst[count][i] >= 48 && dst[count][i] <= 57) || dst[count][i] == ' ' || dst[count][i] == '\n')
					;
				else
				{
					printf("%d\n\n\n\n\n", dst[count][i]);
					error_message("format digit!");
					;
				}
				i++;
			}
			if (count == 0)
				data->colors.celling_red = ft_atoi(dst[count]);
			else if (count == 1)
				data->colors.celling_green = ft_atoi(dst[count]);
			else
				data->colors.celling_blue = ft_atoi(dst[count]);
			count++;
		}
		if (data->colors.celling_red >= 256 || data->colors.celling_red < 0)
			error_message("error\ncelling_red_color: 0 >= c <= 255\n");
		else if (data->colors.celling_green >= 256 || data->colors.celling_green < 0)
			error_message("error\ncelling_green_color: 0 >= c <= 255\n");
		else if (data->colors.celling_blue >= 256 || data->colors.celling_blue < 0)
			error_message("error\ncelling_blue_color: 0 >= c <= 255\n");
		// data->map->ceil = (data->colors.celling_red << 16 | data->colors.celling_green << 8 | data->colors.celling_blue);
		data->ceil = (data->colors.celling_red << 16 | data->colors.celling_green << 8 | data->colors.celling_blue);
	}
}

void	copy(int **addr, void *img)
{
	int	arg[3];
	int	*tmp;
	int	i;

	i = 0;
	// printf("==%p\n", img);
	tmp = (int *)mlx_get_data_addr(img, &arg[0], &arg[1], &arg[2]);
	*addr = (int *)malloc(sizeof(int) * 16384);
	while (i < 16384)
	{
		(*addr)[i] = tmp[i];
		i++;
	}
}

int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

char	*isspaces(char *line, int i)
{
	while (ft_isspace(*++line))
		i++;
	while (line[i])
		i++;
	while (ft_isspace(line[i - 1]))
		i--;
	if (line[i] != '\0')
		line[i] = '\0';
	return (line);
}

void	parse_texture_2(t_data *data, int **addr, char *line, int i)
{
	void	*img;
	int		arg[2];
	
	line = isspaces(line, i);
	img = mlx_xpm_file_to_image(data->mlx, line, &arg[0], &arg[1]);
	// if (arg[0] != 64 || arg[1] != 64 || !img)
	if (!img)
	{
		if (img)
			mlx_destroy_image(data->mlx, img);
		// free_exit(NULL, data);
		// error_message("errorrrrrrr\n");
	}
	copy(addr, img);
	mlx_destroy_image(data->mlx, img);
}

// void pars_textures(t_data *data, char *line, int counter, int path)
// {
// 	// int length = 0;
// 	// int height = 0;
// 	int *adr;
// 	// int i = 0;
// 	printf("_%s\n_", line);
// 	if (line[counter] == ' ')
// 		while (line[counter] == ' ')
// 			counter++;
// 	if (ft_strnstr(&line[ft_strlen(line) - 5], ".xpm", 5) == NULL)
// 		error_message("map is not .xpm\n");
// 	// int fd;
// 	// printf("%s\n", ft_substr(line, counter, ft_strlen(line) - counter));

// 	if (path == 0)
// 		parse_texture_2(data, &data->imgs->textures_north, line, counter + 2);
// 	else if (path == 1)
// 		parse_texture_2(data, &data->imgs->textures_south, line, counter + 2);
// 	else if (path == 2)
// 		parse_texture_2(data, &data->imgs->textures_west, line, counter + 2);
// 	else if (path == 3)
// 		parse_texture_2(data, &data->imgs->textures_east, line, counter + 2);

// 	// if (path == 0)
// 	// {
// 	// 	line[0] = ' ';
// 	// 	line[1] = ' ';
// 	// 	char *tmp = ft_substr(line, counter, ft_strlen(line) - counter);
// 	// 	// free(tmp[ft_strlen(tmp)]);
// 	// 	// char *tmp = "./text/wall.xpm";
// 	// 	// printf("%s\n", tmp);
// 	// 	data->imgs->textures_north = mlx_xpm_file_to_image(data->mlx, "text/0.xpm", &length, &height);
// 	// 	// printf("\n\n%p\n\n", data->imgs->textures_north);
// 	// 	// int *tmp = (int *)malloc(sizeof(int) * 4096);
// 	// 	// tmp = (int *)mlx_get_data_addr(data->imgs->textures_north, &data->bits_to_color, &data->bits_to_line, &data->end);
// 	// 	// while (i < 4096)
// 	// 	// {
// 	// 	// 	tmp[i] = adr[i];
// 	// 	// 	i++;
// 	// 	// }
// 	// }
// 	// else if (path == 1)
// 	// {
// 	// 	char *tmp = ft_substr(line, counter, ft_strlen(line) - counter);
// 	// 	data->imgs->textures_south = mlx_xpm_file_to_image(data->mlx, "text/0.xpm", &length, &height);
// 	// 	// adr = (int *)mlx_get_data_addr(data->imgs->textures_south, &data->bits_to_color, &data->bits_to_line, &data->end);
// 	// }
// 	// else if (path == 2)
// 	// {
// 	// 	data->imgs->textures_west = mlx_xpm_file_to_image(data->mlx, "text/0.xpm", &length, &height);
// 	// 	// adr = (int *)mlx_get_data_addr(data->imgs->textures_west, &data->bits_to_color, &data->bits_to_line, &data->end);
// 	// }
// 	// else if (path == 3)
// 	// {
// 	// 	data->imgs->textures_east = mlx_xpm_file_to_image(data->mlx, "text/0.xpm", &length, &height);
// 	// 	// adr = (int *)mlx_get_data_addr(data->imgs->textures_east, &data->bits_to_color, &data->bits_to_line, &data->end);
// 	// }
// }