/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:14:21 by ocapers           #+#    #+#             */
/*   Updated: 2022/09/16 15:06:42 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	error_message(char *message, t_data *data)
{
	(void)data;
	ft_putstr_fd(message, 1);
	exit(EXIT_FAILURE);
}

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

void	free_exit(t_data *data)
{
	free_arr(data->map.map);
	(void)data;
	exit(EXIT_SUCCESS);
}

int	ft_close(t_data *data)
{
	(void)data;
	exit(EXIT_SUCCESS);
}
