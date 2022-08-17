#include "cub3d.h"

void	move_up_down(int key, t_data *data)
{
	if (key == UP_KEY)
	{
		if (data->map->map[(int)(data->plr.pos.y)]
			[(int)(data->plr.pos.x + data->plr.dir.x * SPEED_P)] == '0')
			data->plr.pos.x += data->plr.dir.x * SPEED_P;
		if (data->map->map[(int)(data->plr.pos.y + data->plr.dir.y * SPEED_P)]
			[(int)(data->plr.pos.x)] == '0')
			data->plr.pos.y += data->plr.dir.y * SPEED_P;
	}
	if (key == DOWN_KEY)
	{
		if (data->map->map[(int)(data->plr.pos.y)]
			[(int)(data->plr.pos.x - data->plr.dir.x * SPEED_P)] == '0')
			data->plr.pos.x -= (data->plr.dir.x * SPEED_P);
		if (data->map->map[(int)(data->plr.pos.y - data->plr.dir.y * SPEED_P)]
			[(int)(data->plr.pos.x)] == '0')
			data->plr.pos.y -= (data->plr.dir.y * SPEED_P);
	}
	drow_game(data);
}

void	move_left_right(int key, t_data *data)
{
	if (key == RIGHT_KEY)
	{
		if (data->map->map[(int)(data->plr.pos.y)]
			[(int)(data->plr.pos.x + data->plane.x * SPEED_P)] == '0')
			data->plr.pos.x += data->plane.x * SPEED_P;
		if (data->map->map[(int)(data->plr.pos.y + data->plane.y * SPEED_P)]
			[(int)(data->plr.pos.x)] == '0')
			data->plr.pos.y += data->plane.y * SPEED_P;
	}
	if (key == LEFT_KEY)
	{
		if (data->map->map[(int)(data->plr.pos.y)]
			[(int)(data->plr.pos.x - data->plane.x * SPEED_P)] == '0')
			data->plr.pos.x -= data->plane.x * SPEED_P;
		if (data->map->map[(int)(data->plr.pos.y - data->plane.y * SPEED_P)]
			[(int)(data->plr.pos.x)] == '0')
			data->plr.pos.y -= data->plane.y * SPEED_P;
	}
	drow_game(data);
}

void	rotation(int key, t_data *data)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = data->plr.dir.x;
	old_planex = data->plane.x;
	if (key == LEFT)
	{
		data->plr.dir.x = data->plr.dir.x * cos(-SPEED_R) - data->plr.dir.y * sin(-SPEED_R);
		data->plr.dir.y = old_dirx * sin(-SPEED_R) + data->plr.dir.y * cos(-SPEED_R);
		data->plane.x = data->plane.x * cos(-SPEED_R) - data->plane.y * sin(-SPEED_R);
		data->plane.y = old_planex * sin(-SPEED_R) + data->plane.y * cos(-SPEED_R);
	}
	if (key == RIGHT)
	{
		data->plr.dir.x = data->plr.dir.x * cos(SPEED_R) - data->plr.dir.y * sin(SPEED_R);
		data->plr.dir.y = old_dirx * sin(SPEED_R) + data->plr.dir.y * cos(SPEED_R);
		data->plane.x = data->plane.x * cos(SPEED_R) - data->plane.y * sin(SPEED_R);
		data->plane.y = old_planex * sin(SPEED_R) + data->plane.y * cos(SPEED_R);
	}
	drow_game(data);
}