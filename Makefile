NAME = cub3D

NAME_LIBFT = libft.a

CC = gcc

CFLAGS =  -c 

HEADER = cub3d.h 

SRCS_LONG = main.c init.c parser_tex_and_color.c parser.c utils.c \
			help_functions.c get_next_line.c get_next_line_utils.c libft/ft_strlen.c\
			libft/ft_putstr_fd.c libft/ft_strnstr.c \
			libft/ft_calloc.c libft/ft_bzero.c \
			libft/ft_memset.c libft/ft_atoi.c \

# SRCS_LIBFT = libft/ft_bzero.c libft/ft_strlcat.c \
# 		libft/ft_isalnum.c libft/ft_isalpha.c \
# 		libft/ft_isascii.c libft/ft_isdigit.c \
# 		libft/ft_isprint.c libft/ft_memchr.c \
# 		libft/ft_memcmp.c libft/ft_memcpy.c \
# 		libft/ft_toupper.c libft/ft_memset.c \
# 		libft/ft_tolower.c libft/ft_strrchr.c\
# 		libft/ft_strncmp.c libft/ft_strdup.c \
# 		libft/ft_strchr.c libft/ft_strlen.c \
# 		libft/ft_calloc.c libft/ft_memmove.c \
# 		libft/ft_strtrim.c libft/ft_putchar_fd.c \
# 		libft/ft_putendl_fd.c libft/ft_putstr_fd.c\
# 		libft/ft_atoi.c libft/ft_strlcpy.c \
# 		libft/ft_strnstr.c libft/ft_putnbr_fd.c \
# 		libft/ft_strmapi.c libft/ft_strjoin.c \
# 		libft/ft_substr.c libft/ft_itoa.c \
#         libft/ft_striteri.c libft/ft_split.c \

OBJS = $(SRCS_LONG:.c=.o)

# OBJS_LIBFT = $(SRCS_LIBFT:.c=.o)

all:  $(NAME)

# $(LIBFT_NAME) : $(OBJS_LIBFT) $(HEADER)
# 	ar rcs $(LIBFT_NAME) $(OBJS_LIBFT)

$(NAME) : $(OBJS) $(HEADER)
	$(CC) $(OBJS) -o $(NAME)

%.o : %.c $(HEADER)
	$(CC)  -Imlx -c $< -o $@

clean:
	rm -rf $(OBJS) $(OBJS_LIBFT)

fclean: clean
	rm -f $(NAME) $(LIBFT_NAME)

re: fclean all

norm:
	norminette $(SRCS) $(LIBFT)

.PHONY: all clean fclean re norm