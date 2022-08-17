#include "cub3d.h"

void	draw_point(t_data *data, int color, int x, int y)
{
	int	start_x;
	int	start_y;
    char *put;

	start_y = y;
	while (start_y < POINT_SIZE + y)
	{
		start_x = x;
		while (start_x < POINT_SIZE + x)
		{
            if (start_x >= 0 && start_x < WIN_LENGHT && start_y >= 0 && start_y < WIN_HEIGHT)
	        {
		        put = data->addr + (start_y * data->bits_to_line + start_x * (data->bits_to_color / 8));
		        *(unsigned int *)put = color;
	        }
			start_x++;
		}
		start_y++;
	}
}

void	drow_game_two(t_data *data)
{
	int	i;
	int	k;
	int	color;

	i = -1;
	while (data->map->map[++i])
	{
		k = -1;
		while (data->map->map[i][++k])
		{
			if (data->map->map[i][k] == '0')
			{
				color = SPACE_COLOR;
				draw_point(data, color, k * POINT_SIZE, i * POINT_SIZE);
			}
			if (data->map->map[i][k] == '1')
			{
				color = WALL_COLOR;
				draw_point(data, color, k * POINT_SIZE, i * POINT_SIZE);
			}
		}
	}
	draw_point(data, PLAYER_COLOR, (int)data->plr.pos.x * POINT_SIZE, (int)data->plr.pos.y * POINT_SIZE);
}