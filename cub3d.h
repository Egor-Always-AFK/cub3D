#ifndef CUB3D_H
# define CUB3D_H

#include "minilibx/mlx.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#   define TRUE 1
#   define FALSE 0
#   define BUFFER_SIZE 10
#   define IMG_HEIGHT 32
#   define IMG_LENGHT 32
#   define WIN_HEIGHT 900
#   define WIN_LENGHT 900
#	define UP 1
#	define DOWN 2
#	define LEFT 3
#	define RIGHT 4
#	define UP_KEY 13
#	define DOWN_KEY 1
#	define LEFT_KEY 0
#	define RIGHT_KEY 2
#	define ESC 53

typedef struct s_map
{
	char **map;
	int col;
	int exit;
	int collect;
} t_map;

typedef struct s_imgs
{
	void *textures_north;
	void *textures_south;
	void *textures_west;
	void *textures_east;
	void *exit;
	void *background;
	void *wall;
} t_imgs;

typedef struct s_player
{
	int pos_x;
	int pos_y;
	int collect;
} t_player;

typedef struct s_data
{
	int length;
	int height;
	int counter;
	void *mlx;
	void *window;
	t_map *map;
	t_imgs *imgs;
	t_player player;
} t_data;

int main(int argc, char **argv);

void init(t_data *data);

int lenght_count(int fd);

int height_count(int fd, int map_lenght);

void parse_input(t_data *data, char **argv);

void check_content(t_data *data);

void check_border(t_data *data);

int	counter_for_map(char *s, char c);

char	*ft_strjoin(char *all_text, char *tmp);

char	*ft_strchr(char *s, int c);

char	*copy_from_txt(int fd, char *all_text);

char	*get_line(char *all_text);

char	*skip_before_new_line(char *all_text);

char	*get_next_line(int fd);

void	error_message(char *message);

void parser_for_text(t_data *data, char *name);

void pars_textures(t_data *data, char *line, int counter, int path);

#endif