#include "cub3d.h"

void	draw_sprites(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
	// mlx_put_image_to_window(data->mlx, data->window, data->minimap.img, 0, WIN_HEIGHT - MMAP_HEIGH * SCALE);
	mlx_put_image_to_window(data->mlx, data->window, data->spr.sprite_imgs[data->spr.sprite / 2], WIN_LENGHT * 0.5 - (data->spr.sprite_x[data->spr.sprite / 2] / 2), WIN_HEIGHT - data->spr.sprite_y[data->spr.sprite / 2]);
	data->spr.sprite++;
	if (data->spr.sprite == 40)
		data->spr.sprite = 0;
}

int	handler_keys(int key, t_data *data)
{
	if (key == ESC)
		exit(0);
		// free_exit(NULL, data);
	else if (key == UP_KEY || key == DOWN_KEY)
		move_up_down(key, data);
	else if (key == LEFT_KEY || key == RIGHT_KEY)
		move_left_right(key, data);
	else if (key == LEFT || key == RIGHT)
		rotation(key, data);
	// if (key == SPACE || data->spr.sprite != 0)
	// 	draw_sprites(data);
	return (0);
}

int	mouse(int x, int y, t_data *data)
{
	double	old_plane;

	(void)y;
	if (x > data->mouse_x)
	{
		old_plane = data->plane.x;
		data->plane.x = data->plane.x * cos(SPEED_R_M) - data->plane.y * sin(SPEED_R_M);
		data->plane.y = old_plane * sin(SPEED_R_M) + data->plane.y * cos(SPEED_R_M);
		data->plr.rot += SPEED_R_M;
	}
	if (x < data->mouse_x)
	{
		old_plane = data->plane.x;
		data->plane.x = data->plane.x * \
		cos(-SPEED_R_M) - data->plane.y * sin(-SPEED_R_M);
		data->plane.y = old_plane * sin(-SPEED_R_M) + \
		data->plane.y * cos(-SPEED_R_M);
		data->plr.rot -= SPEED_R_M;
	}
	data->mouse_x = x;
	return (0);
}

void	init_sprites(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 20)
	{
		ft_strlcpy(data->spr.sprite_names[i], "./text/00.xpm", 26);
		if (i < 10)
			data->spr.sprite_names[i][20] = '0' + i;
		else
		{
			data->spr.sprite_names[i][19] = 1 + '0';
			data->spr.sprite_names[i][20] = '0' + i - 10;
		}
		i++;
	}
	while (j < 20)
	{
		data->spr.sprite_imgs[j] = mlx_xpm_file_to_image(data->mlx, data->spr.sprite_names[j], &data->spr.sprite_x[j], &data->spr.sprite_y[j]);
		j++;
	}
}

int main(int argc, char **argv)
{
	t_data data;
	t_map map;

	if (argc != 2)
		error_message("Error!\nFew arguments :c\n");
	if (ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])) != NULL)
	{
		map.map = ft_calloc(100, sizeof(t_map *));
		data.map = &map;
		init_data(&data);
		map_shit(&data, argv[1]);
		init_mlx(&data);
		parser_for_text(&data, argv[1]);
		// printf("aaaa\n");
	}
	else
		error_message("Error!");
	// init_sprites(&data);
	drow_game(&data);
	// data.mouse_x = 0;
	mlx_hook(data.window, 2, 0, &handler_keys, &data);
	mlx_hook(data.window, 17, 0, &close, &data);
	// mlx_hook(data.window, 6, 0, &mouse, &data);
	mlx_loop(data.mlx);
	free_exit(NULL, &data);
	return(0);
}