#include "cub3d.h"

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
	return (0);
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
	}
	else
		error_message("Error!");
	drow_game(&data);
	mlx_hook(data.window, 2, 0, &handler_keys, &data);
	mlx_hook(data.window, 17, 0, &close, &data);
	mlx_loop(data.mlx);
	// free_exit(NULL, &data);
	return(0);
}