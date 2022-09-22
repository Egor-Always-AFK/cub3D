/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:13:45 by ocapers           #+#    #+#             */
/*   Updated: 2022/09/03 18:50:52 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int				ft_strlen(const char *str);

char			*ft_strnstr(const char *haystack, \
						const char *needle, size_t len);

void			ft_bzero(void *s, size_t n);

void			*ft_memset(void *b, int c, size_t len);

void			*ft_calloc(size_t count, size_t size);

void			ft_putchar_fd(char c, int fd);

void			ft_putstr_fd(char *s, int fd);

void			ft_putnbr_fd(int n, int fd);

char			*ft_strjoin(char *all_text, char *tmp);

int				ft_atoi(char *str);

int				check_space(char c);

int				ft_isdigit(int c);

char			**ft_split(char const *s, char c);

size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);

char			*ft_substr(char const *s, unsigned int start, size_t len);

#endif