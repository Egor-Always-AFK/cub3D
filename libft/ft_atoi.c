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

int	check_space(char c)
{
	if ((c == ' ') || (c == '\n') || (c == '\a')
		|| (c == '\b') || (c == '\t') || (c == '\v')
		|| (c == '\f') || (c == '\r'))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if ((c >= '0' ) && (c <= '9' ))
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int		n;
	int		mn;
	int		i;
	long	check_maxmin;

	i = 0;
	n = 0;
	mn = 1;
	check_maxmin = 0;
	while (check_space(str[i]))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
		if (str[i++] == '-')
			mn = -1;
	while (ft_isdigit(str[i]) && *str)
	{
		if (mn == 1 && check_maxmin > 10)
			return (-1);
		else if (mn == -1 && check_maxmin > 10)
			return (0);
		n = (n * 10) + (str[i] - '0');
		i++;
		check_maxmin++;
	}
	return (n * mn);
}
