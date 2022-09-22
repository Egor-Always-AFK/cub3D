/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:13:45 by ocapers           #+#    #+#             */
/*   Updated: 2021/11/18 14:13:52 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

char	*ft_strjoin(char *all_text, char *tmp)
{
	size_t	i;
	size_t	j;
	char	*dst;

	if (!all_text)
	{
		all_text = (char *)malloc(1 * sizeof(char));
		all_text[0] = '\0';
	}
	if (!all_text || !tmp)
		return (NULL);
	dst = malloc(sizeof(char) * ((ft_strlen(all_text) + ft_strlen(tmp)) + 1));
	if (dst == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (all_text)
		while (all_text[++i] != '\0')
			dst[i] = all_text[i];
	while (tmp[j] != '\0')
		dst[i++] = tmp[j++];
	dst[ft_strlen(all_text) + ft_strlen(tmp)] = '\0';
	free(all_text);
	all_text = NULL;
	return (dst);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (0);
}
