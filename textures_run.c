#include "cub3d.h"

void	find_tex_x(t_data *data)
{
	double	wall_x;

	if (!data->ray.hit)
		wall_x = data->plr.pos.y + data->wall.dist * data->ray.dir.y;
	else
		wall_x = data->plr.pos.x + data->wall.dist * data->ray.dir.x;
	wall_x -= floor(wall_x);
	data->wall.tex_x = (int)(wall_x * 64.0);
	if ((!data->ray.hit && data->ray.dir.x > 0) || (data->ray.hit && data->ray.dir.y < 0))
		data->wall.tex_x = 64 - data->wall.tex_x - 1;
}

int	find_texel(t_data *data, int x, int y)
{
	int	*tex;

	// tex = malloc(1000);
	if (!data->ray.hit)
	{
		if (data->ray.dir.x >= 0)
			tex = data->imgs->textures_east;
		else
			tex = data->imgs->textures_west;
	}
	else
	{
		if (data->ray.dir.y >= 0)
			tex = data->imgs->textures_south;
		else
			tex = data->imgs->textures_north;
	}
	return (tex[64 * y + x]);
}

// void	put_pixel(t_data *data, int x, int y, int color)
// {
// 	char    *put;

// 	if (x >= 0 && x < WIN_LENGHT && y >= 0 && y < WIN_HEIGHT)
// 	{
// 		put = data->addr + (y * data->bits_to_line + x * (data->bits_to_color / 8));
// 		*(unsigned int *)put = color;
// 	}
// }

// void	set_direction(t_all *all, char pov, double i, double k)
// {
// 	all->plr.pos.x = k + 0.5;
// 	all->plr.pos.y = i + 0.5;
// 	if (pov == 'E')
// 	{
// 		all->plr.dir.x = 1;
// 		all->plane.x = 0;
// 		all->plane.y = FOV;
// 	}
// 	else if (pov == 'W')
// 	{
// 		all->plr.dir.x = -1;
// 		all->plane.x = 0;
// 		all->plane.y = -FOV;
// 	}
// 	else if (pov == 'S')
// 	{
// 		all->plr.dir.y = 1;
// 		all->plane.x = -FOV;
// 	}
// 	else if (pov == 'N')
// 		all->plr.dir.y = -1;
// }

// int	set_position(t_all *all)
// {
// 	double		i;
// 	double		k;
// 	char		pov;
// 	int			count;

// 	i = -1;
// 	count = 0;
// 	while (all->map.map[(int)++i])
// 	{
// 		k = -1;
// 		while (all->map.map[(int)i][(int)++k])
// 		{
// 			pov = all->map.map[(int)i][(int)k];
// 			if (pov == 'N' || pov == 'S' || pov == 'W' || pov == 'E')
// 			{
// 				if (count++)
// 					return (-1);
// 				ft_set_direction(all, pov, i, k);
// 				all->map.map[(int)i][(int)k] = '0';
// 			}
// 		}
// 	}
// 	if (!count)
// 		return (-1);
// 	return (0);
// }

void	draw_vert_line(t_data *data)
{
	double	scale;
	int		color;
	int		i;
    char    *put;

	scale = 64.0 / (double)data->wall.height;
	data->wall.tex_y = 0;
	i = 0;
	// printf("%d\n", data->wall.height);
	while (i < data->wall.height)
	{
		color = find_texel(data, data->wall.tex_x, (int)data->wall.tex_y);
		// put_pixel(data, data->ray.i, data->wall.top + i, color);
        if (data->ray.i >= 0 && data->ray.i < WIN_LENGHT && (data->wall.top + i) >= 0 && (data->wall.top + i) < WIN_HEIGHT)
	    {
		    put = data->addr + ((data->wall.top + i) * data->bits_to_line + data->ray.i * (data->bits_to_color / 8));
		    *(unsigned int *)put = color;
	    }
		data->wall.tex_y += scale;
		i++;
	}
}