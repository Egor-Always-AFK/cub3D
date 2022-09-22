NAME = cub3D

NAME_B = cub3D_bonus

NAME_LIBFT = libft.a

CC = gcc

CFLAGS =  -g -Wall -Wextra -Werror

HEADER = cub3d.h

HEADER_BONUS = cub3d_bonus.h

SRCS = 		main.c parser_tex_and_color.c ray_cast.c keys.c keys_2.c \
			help_functions.c move_two.c move.c get_next_line.c get_next_line_utils.c\
			map_parse.c new_drow_game.c ray_cast_help.c\
			parse_walls.c pars_color.c map_parse_utils.c error_parse.c \

SRCS_BONUS = main_bonus.c parser_tex_and_color_bonus.c ray_cast_bonus.c keys_bonus.c keys_2_bonus.c \
			 help_functions_bonus.c anim_bonus.c map_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c\
			 move_bonus.c ray_cast_help_bonus.c new_drow_game_bonus.c map_parse_bonus.c\
			 parse_walls_bonus.c pars_color_bonus.c move_two_bonus.c map_parse_utils_bonus.c error_parse_bonus.c \

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

LIBFT_HDR 	= -I./libft

LIB_BINARY	= -L./libft -lft

LIBFT		= ./libft/libft.a

.PHONY : all clean fclean re bonus

all:  $(LIBFT) $(NAME)

FORCE:		;

$(LIBFT):	FORCE
			make -C ./libft

%.o : %.c $(HEADER) $(HEADER_BONUS)
	$(CC) $(CFLAGS)  -Imlx -c -g $< -o $@

$(NAME) : $(OBJS) $(HEADER)
	make -C ./minilibx/ all
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -L./minilibx -lmlx -framework OpenGL -framework AppKit -lz -o $(NAME)

$(NAME_B) : $(OBJS_BONUS) $(HEADER_BONUS)
	make -C ./minilibx/ all
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -L./minilibx -lmlx -framework OpenGL -framework AppKit -lz -o $(NAME_B)

bonus: $(LIBFT) ./libft/libft.a $(NAME_B)

clean:
	
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_B)

re: fclean all

bonus_re: fclean bonus
