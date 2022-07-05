/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:13:45 by ocapers           #+#    #+#             */
/*   Updated: 2021/10/22 14:13:52 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	trash;

	trash = n;
	if (trash < 0)
	{
		ft_putchar_fd('-', fd);
		trash *= -1;
	}
	if (trash <= 9)
		ft_putchar_fd(trash + '0', fd);
	else
	{
		ft_putnbr_fd(trash / 10, fd);
		ft_putnbr_fd(trash % 10, fd);
	}
}
