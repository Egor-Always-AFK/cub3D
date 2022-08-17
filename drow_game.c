#include "cub3d.h"

void    create_ceil(t_data *data)
{
    int i;
    int j;
    char *put;

    i = 0;
    while (i < WIN_HEIGHT / 2)
    {
        j = 0;
        while (j < WIN_LENGHT)
        {
            if (j >= 0 && j < WIN_LENGHT && i >= 0 && i < WIN_HEIGHT)
	        {
		        put = data->addr + (i * data->bits_to_line + j * (data->bits_to_color / 8));
		        // *(unsigned int *)put = data->map->ceil;
                *(unsigned int *)put = data->ceil;
	        }
            j++;
        }
        i++;
    }
}

void    create_floor(t_data *data)
{
    int i;
    int j;
    char *put;
    int y;

    y = WIN_HEIGHT / 2;
    i = 0;
    while (i < WIN_HEIGHT / 2)
    {
        j = 0;
        while (j < WIN_LENGHT)
        {
            if (j >= 0 && j < WIN_LENGHT && (i + y) >= 0 && (i + y) < WIN_HEIGHT)
	        {
		        put = data->addr + ((i + y) * data->bits_to_line + j * (data->bits_to_color / 8));
		        // *(unsigned int *)put = data->map->floor;
                *(unsigned int *)put = data->floor;
	        }
            j++;
        }
        i++;
    }
}

void    drow_game(t_data *data)
{
    data->ray.i = 0;
    create_ceil(data);
    create_floor(data);
    while (data->ray.i < WIN_LENGHT)
	{
		ray_init(data);
		ray_run(data);
		dist_wall_hit(data);
		find_tex_x(data);
		draw_vert_line(data);
		data->ray.i++;
	}
    drow_game_two(data);
	mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
}