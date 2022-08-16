#include "cub3d.h"

void init_data(t_data *data)
{
    t_imgs *govno;

    govno = malloc(sizeof(t_imgs));
    // data->map = map;
    data->imgs = govno;
    data->mlx = NULL;
    data->window = NULL;
    data->addr = NULL;
    data->img = NULL;
    data->end = 0;
    data->length = 0;
    data->height = 0;
    data->counter = 0;
    // data->map->map = (char **)malloc(17);
    // for (int i = 0; i < 3; i++)
    // {
    //     data->map->map[i] = (char *)malloc(16);
    // }
    // data->map->map = ft_split("111111111111111\n100000000000001\n111111111111111", '\n');
    data->ceil = -1;
    data->floor = -1;
    data->map->col = 0;
    data->map->exit = 0;
    data->map->collect = 0;
    // data->map->ceil = -1;
    // data->map->floor = -1;
    data->imgs->textures_east = NULL;
    data->imgs->textures_north = NULL;
    data->imgs->textures_south = NULL;
    data->imgs->textures_west = NULL;
    data->imgs->background = NULL;
    data->imgs->wall = NULL;
    data->plane.x = FOV;
    data->plane.y = 0;
    data->plr.pos.x = 0;
    data->plr.pos.y = 0;
    data->ray.dir.x = 0;
    data->ray.dir.y = 0;
    data->ray.delta.x = 0;
    data->ray.delta.y = 0;
    data->ray.side.x = 0;
    data->ray.side.y = 0;
    data->ray.step_x = 0;
    data->ray.step_y = 0;
    data->ray.hit = 0;
    data->wall.height = 0;
    data->wall.top = 0;
    data->wall.tex_x = 0;
    data->wall.tex_y = 0;
    data->wall.dist = 0;
}

void    init_mlx(t_data *data)
{
    data->mlx = mlx_init();
    data->window = mlx_new_window(data->mlx, WIN_LENGHT, WIN_HEIGHT, "cub3D");
    data->img = mlx_new_image(data->mlx, WIN_LENGHT, WIN_HEIGHT);
    data->addr = mlx_get_data_addr(data->img, &data->bits_to_color, &data->bits_to_line, &data->end);
}