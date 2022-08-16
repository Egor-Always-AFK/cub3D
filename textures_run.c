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

int	ft_find_texel(t_data *data, int x, int y)
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
	return ((int)tex[64 * y + x]);
}

void	ft_draw_vert_line(t_data *data)
{
	double	scale;
	int		color;
	int		i;
    char    *put;

	scale = 64.0 / (double)data->wall.height;
	data->wall.tex_y = 0;
	i = 0;
	while (i < data->wall.height)
	{
		color = ft_find_texel(data, data->wall.tex_x, (int)data->wall.tex_y);
        if (data->ray.i >= 0 && data->ray.i < WIN_LENGHT && (data->wall.top + i) >= 0 && (data->wall.top + i) < WIN_HEIGHT)
	    {
		    put = data->addr + ((data->wall.top + i) * data->bits_to_line + data->ray.i * (data->bits_to_color / 8));
		    *(unsigned int *)put = color;
	    }
		data->wall.tex_y += scale;
		i++;
	}
}