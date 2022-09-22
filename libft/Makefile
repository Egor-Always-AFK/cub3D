NAME = libft.a

HEADER = libft.h

LIST = ft_atoi.c    ft_bzero.c\
	    ft_memset.c\
	    ft_strlcpy.c ft_strlen.c\
	   ft_strnstr.c\
	   ft_putchar_fd.c\
	   ft_putstr_fd.c ft_split.c\
	   ft_substr.c ft_calloc.c ft_putnbr_fd.c

OBJS = $(patsubst %.c,%.o,$(LIST))

FLAGS = -Wall -Wextra -Werror

.PHONY : all clean fclean re

all : $(NAME) $(HEADER)
 
$(NAME) : $(OBJS)
	ar rcs $(NAME) $?

%.o : %.c libft.h
	CC $(FLAGS) -c $< -o $@ -I ${HEADER}

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME) 

re : fclean all