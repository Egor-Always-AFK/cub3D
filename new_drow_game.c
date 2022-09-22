/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_drow_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:13:45 by ocapers           #+#    #+#             */
/*   Updated: 2022/09/16 19:00:28 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(t_pixel *pix, int x, int y, int color)
{
	char	*put;

	if (x >= 0 && x < WIN_LENGHT && y >= 0 && y < WIN_HEIGHT)
	{
		put = pix->addr + (y * pix->bits_line + x * (pix->bits_pixel / 8));
		*(unsigned int *)put = color;
	}
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (dst);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

void	floor_ceil_set_imgs(t_data *data)
{
	data->floor_ceil.img = mlx_new_image(data->win->mlx,
			WIN_LENGHT, WIN_HEIGHT);
	if (!data->floor_ceil.img)
		error_message("Error floor ceil\n");
	data->floor_ceil.addr = mlx_get_data_addr(data->floor_ceil.img,
			&data->floor_ceil.bits_pixel,
			&data->floor_ceil.bits_line, &data->floor_ceil.end);
	if (!data->floor_ceil.addr)
		error_message("Error floor ceil\n");
}

void	new_drow_floor_ceil(t_data *data)
{
	int	i;
	int	j;
	int	y;

	floor_ceil_set_imgs(data);
	j = 0;
	while (j < WIN_HEIGHT)
	{
		i = 0;
		while (i < WIN_LENGHT)
		{
			y = WIN_HEIGHT - j - 1;
			put_pixel(&data->floor_ceil, i, j, data->ceil);
			put_pixel(&data->floor_ceil, i, y, data->floor);
			i++;
		}
		j++;
	}
	ft_memcpy(data->win->pixel.addr, data->floor_ceil.addr,
		WIN_HEIGHT * WIN_LENGHT * (data->win->pixel.bits_pixel / 8));
}
