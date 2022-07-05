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

void	*ft_calloc(size_t count, size_t size)
{
	char	*trash;

	trash = malloc(count * size);
	if (trash == NULL)
		return (NULL);
	ft_bzero(trash, count * size);
	return (trash);
}
