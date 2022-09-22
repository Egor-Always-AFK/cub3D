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

char	*copy_from_txt(int fd, char *all_text)
{
	char	*tmp;
	int		read_len;

	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	read_len = 1;
	while (read_len != 0 && !ft_strchr(all_text, '\n'))
	{
		read_len = read(fd, tmp, BUFFER_SIZE);
		if (read_len == -1)
		{
			free (tmp);
			return (NULL);
		}
		tmp[read_len] = '\0';
		all_text = ft_strjoin(all_text, tmp);
	}
	free (tmp);
	tmp = NULL;
	return (all_text);
}

char	*get_line(char *all_text)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!all_text[i])
		return (NULL);
	while (all_text[i] && all_text[i] != '\n')
			i++;
	tmp = (char *)malloc(sizeof(char) * i + 2);
	if (!tmp)
		return (NULL);
	i = 0;
	while (all_text[i] && all_text[i] != '\n')
	{
		tmp[i] = all_text[i];
		i++;
	}
	if (all_text[i] == '\n')
	{
		tmp[i] = all_text[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*skip_before_new_line(char *all_text)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (all_text[i] && all_text[i] != '\n')
			i++;
	if (!all_text[i])
	{
		free (all_text);
		return (NULL);
	}
	tmp = (char *)malloc(sizeof(char *) * (ft_strlen(all_text) - i + 1));
	i++;
	j = 0;
	while (all_text[i])
		tmp[j++] = all_text[i++];
	tmp[j] = '\0';
	free (all_text);
	all_text = NULL;
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*dst;
	static char	*all_text;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	all_text = copy_from_txt(fd, all_text);
	if (!all_text)
		return (NULL);
	dst = get_line(all_text);
	all_text = skip_before_new_line(all_text);
	return (dst);
}
