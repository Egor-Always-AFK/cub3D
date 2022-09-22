/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:19:38 by ocapers           #+#    #+#             */
/*   Updated: 2022/09/09 14:24:31 by sdavos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	open_door(t_data *data)
{
	if (data->map.map[(int)data->plr.pos.y][(int) \
		(data->plr.pos.x + data->plr.dir.x * 1)] == '5')
		data->map.map[(int)data->plr.pos.y][(int) \
			(data->plr.pos.x + data->plr.dir.x * 1)] = '6';
	else if (data->map.map[(int)(data->plr.pos.y + data->plr.dir.y * 1)] \
		[(int)data->plr.pos.x] == '5')
		data->map.map[(int)(data->plr.pos.y + data->plr.dir.y * 1)] \
			[(int)data->plr.pos.x] = '6';
	data->key.space = TRUE;
}

void	close_door(t_data *data)
{
	if (data->map.map[(int)data->plr.pos.y] \
	[(int)(data->plr.pos.x + data->plr.dir.x * 1)] == '6' && data->map.map \
	[(int)data->plr.pos.y][(int)data->plr.pos.x] != '6')
		data->map.map[(int)data->plr.pos.y][(int)(data->plr.pos.x + \
			data->plr.dir.x * 1)] = '5';
	else if (data->map.map[(int)(data->plr.pos.y + data->plr.dir.y * 1)] \
	[(int)data->plr.pos.x] == '6' && data->map.map[(int)data->plr.pos.y] \
	[(int)data->plr.pos.x] != '6')
		data->map.map[(int)(data->plr.pos.y + data->plr.dir.y * 1)] \
		[(int)data->plr.pos.x] = '5';
}

void	main_2(t_window win, t_data data)
{
	mlx_mouse_move(win.window, 960, 540);
	new_drow_floor_ceil(&data);
	mlx_do_key_autorepeatoff(win.mlx);
	data.anims.anim_wall = 0;
	data.mouse = 0;
	mlx_mouse_hide();
	mlx_hook(win.window, 2, 0, &handler_keys, &data);
	mlx_hook(win.window, 3, 0, &non_handler_keys, &data);
	mlx_hook(win.window, 17, 0, &ft_close, &data);
	mlx_hook(win.window, 6, 0, &mouse_rotation, &data);
	mlx_loop_hook(win.mlx, &keys, &data);
	mlx_loop(win.mlx);
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_window	win;

	if (argc != 2)
		error_message("Error!\nFew arguments :c\n", &data);
	if (ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])) != NULL)
	{
		data = (t_data){0};
		win.mlx = mlx_init();
		win.window = mlx_new_window(win.mlx, WIN_LENGHT, WIN_HEIGHT, "cub3D");
		win.pixel.img = mlx_new_image(win.mlx, WIN_LENGHT, WIN_HEIGHT);
		win.pixel.addr = mlx_get_data_addr(win.pixel.img, \
		&win.pixel.bits_pixel, &win.pixel.bits_line, &win.pixel.end);
		data.win = &win;
		anims_parse(&data);
		map_shit(&data, argv[1]);
		parser_for_text(&data, argv[1]);
		get_img_minimap(&data);
	}
	else
		error_message("Error!", &data);
	main_2(win, data);
	return (0);
}
