#include "cub3d.h"

void    set_player_napr_pos(t_data *data)
{
    data->plr.pos.y += 0.5;
    data->plr.pos.x += 0.5;
    if (data->plr.start_dir == 'N')
    {
        data->plr.dir.y = 1;
    }
    else if (data->plr.start_dir == 'S')
    {
        data->plr.dir.y = -1;
        data->plane.x = FOV;
    }
    else if (data->plr.start_dir == 'E')
    {
        data->plr.dir.x = -1;
        data->plane.x = 0;
        data->plane.y = -FOV;
    }
    else if (data->plr.start_dir == 'W')
    {
        data->plr.dir.x = 1;
        data->plane.x = 0;
        data->plane.y = FOV;
    }
}