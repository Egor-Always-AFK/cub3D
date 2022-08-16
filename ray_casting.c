#include "cub3d.h"

void	ray_init(t_data *data)
{
	double	camera_x;

	camera_x = data->ray.i * 2.0 / (double)WIN_LENGHT - 1.0;
	data->ray.dir.x = data->plr.dir.x + data->plane.x * camera_x;
	data->ray.dir.y = data->plr.dir.y + data->plane.y * camera_x;
	data->map->x_ray = (int)data->plr.pos.x;
	data->map->y_ray = (int)data->plr.pos.y;
	data->ray.delta.x = fabs(1.0 / data->ray.dir.x);
	data->ray.delta.y = fabs(1.0 / data->ray.dir.y);
	data->ray.step_x = 1;
    data->ray.step_y = 1;
	data->ray.side.x = (data->map->x_ray + 1.0 - data->plr.pos.x) * data->ray.delta.x;
	data->ray.side.y = (data->map->y_ray + 1.0 - data->plr.pos.y) * data->ray.delta.y;
	if (data->ray.dir.x < 0)
	{
		data->ray.step_x = -1;
		data->ray.side.x = (data->plr.pos.x - data->map->x_ray) * data->ray.delta.x;
	}
	if (data->ray.dir.y < 0)
	{
		data->ray.step_y = -1;
		data->ray.side.y = (data->plr.pos.y - data->map->y_ray) * data->ray.delta.y;
	}
}

void	ray_run(t_data *data)
{
	int	collision;

	collision = 0;
	while (!collision)
	{
		if (data->ray.side.x < data->ray.side.y)
		{
			data->ray.side.x += data->ray.delta.x;
			data->map->x_ray += data->ray.step_x;
			data->ray.hit = 0;
		}
		else
		{
			data->ray.side.y += data->ray.delta.y;
			data->map->y_ray += data->ray.step_y;
			data->ray.hit = 1;
		}
		if (data->map->map[data->map->y_ray][data->map->x_ray] == '1')
			collision = 1;
	}
}

void	dist_wall_hit(t_data *data)
{
	if (!data->ray.hit)
		data->wall.dist = data->ray.side.x - data->ray.delta.x;
	else
		data->wall.dist = data->ray.side.y - data->ray.delta.y;
	data->wall.height = (int)(WIN_HEIGHT / data->wall.dist);
	data->wall.top = -data->wall.height / 2 + WIN_HEIGHT / 2;
}