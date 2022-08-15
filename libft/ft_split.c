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

static char	**free_my_arr_pls(char **arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	return ((void *)0);
}

static int	check_size(char const *s, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static char	*my_small_arr(char const *s, char c)
{
	int		i;
	char	*small_arr;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	small_arr = (char *)malloc(sizeof(char) * (i + 1));
	if (!small_arr)
		return (NULL);
	ft_strlcpy(small_arr, s, i + 1);
	return (small_arr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		len;
	char	**arr;

	if (!s)
		return (NULL);
	len = check_size(s, c);
	arr = (char **)malloc(sizeof(char *) * (len + 1));
	if (!arr)
		return (NULL);
	i = -1;
	while (++i < len)
	{
		while (*s == c)
			s++;
		arr[i] = my_small_arr(s, c);
		if (!(arr[i]))
		{
			free_my_arr_pls(arr, len - i - 1);
			return (NULL);
		}
		s = s + ft_strlen(arr[i]);
	}
	arr[i] = 0;
	return (arr);
}
