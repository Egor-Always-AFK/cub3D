/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:14:21 by ocapers           #+#    #+#             */
/*   Updated: 2022/07/05 17:29:29 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	error_message(char *message)
{
	ft_putstr_fd(message, 1);
	exit (1);
}

int	counter_for_map(char *s, char c)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (s && s[i])
		if (s[i++] == c)
			ret++;
	return (ret);
}

int	exit_function(t_data *data)
{
	// mlx_destroy_window(data->mlx, data->window);
	ft_putstr_fd("DELETE THE GAME!\nWork harder!\n", 1);
	exit(0);
}

int	win_message(t_data *data)
{
	// mlx_destroy_window(data->mlx, data->window);
	ft_putstr_fd("You won!!\nCongratulations\n", 1);
	exit (0);
}
