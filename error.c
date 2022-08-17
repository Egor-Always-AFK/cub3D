#include "cub3d.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
		arr = NULL;
	}
}

void	fatal_error(char *msg)
{
	if (!msg)
		exit(EXIT_FAILURE);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

void	free_exit(char *msg, t_data *data)
{
	free_arr(data->map->map);
	if (data->imgs->textures_north)
		free(data->imgs->textures_north);
	if (data->imgs->textures_south)
		free(data->imgs->textures_south);
	if (data->imgs->textures_west)
		free(data->imgs->textures_west);
	if (data->imgs->textures_east)
		free(data->imgs->textures_east);
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	if (msg)
		fatal_error(msg);
	else
		exit(EXIT_SUCCESS);
}

int	ft_close(t_data *data)
{
	free_exit(NULL, data);
	return (0);
}