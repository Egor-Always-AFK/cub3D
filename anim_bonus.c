/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:12:24 by ocapers           #+#    #+#             */
/*   Updated: 2022/09/09 14:18:09 by sdavos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	anims_parse_two(t_data *data, char *guns[12])
{
	int	i;

	i = 0;
	while (i < 20)
	{
		data->anims.guns_imgs[i] = mlx_xpm_file_to_image(data->win->mlx,
				guns[i], &data->anims.x[i], &data->anims.y[i]);
		i++;
	}
}

void	init_anims(char *guns[12])
{
	guns[0] = "anim/00.xpm";
	guns[1] = "anim/01.xpm";
	guns[2] = "anim/02.xpm";
	guns[3] = "anim/03.xpm";
	guns[4] = "anim/04.xpm";
	guns[5] = "anim/05.xpm";
	guns[6] = "anim/06.xpm";
	guns[7] = "anim/07.xpm";
	guns[8] = "anim/08.xpm";
	guns[9] = "anim/09.xpm";
	guns[10] = "anim/10.xpm";
	guns[11] = "anim/11.xpm";
	guns[12] = "anim/12.xpm";
	guns[13] = "anim/13.xpm";
	guns[14] = "anim/14.xpm";
	guns[15] = "anim/15.xpm";
	guns[16] = "anim/16.xpm";
	guns[17] = "anim/17.xpm";
	guns[18] = "anim/18.xpm";
	guns[19] = "anim/19.xpm";
}

void	anims_parse(t_data *data)
{
	char	guns[20][11];

	init_anims((char **)guns);
	anims_parse_two(data, (char **)guns);
}
