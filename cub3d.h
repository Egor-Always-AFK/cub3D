#ifndef CUB3D_H
# define CUB3D_H

#include "minilibx/mlx.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
# include <math.h>

#   define TRUE 1
#   define FALSE 0
#   define BUFFER_SIZE 10
// #   define IMG_HEIGHT 32
// #   define IMG_LENGHT 32
#   define WIN_HEIGHT 720
#   define WIN_LENGHT 1280
#	define UP 1
#	define DOWN 2
#	define LEFT 12
#	define RIGHT 14
#	define UP_KEY 13
#	define DOWN_KEY 1
#	define LEFT_KEY 0
#	define RIGHT_KEY 2
#	define ESC 53
# 	define WALL_COLOR 0x000000
# 	define SPACE_COLOR 0xFFFFFF
# 	define PLAYER_COLOR 0xFF0000
# 	define POINT_SIZE 12
# 	define FOV 0.66
# 	define SPEED_P 0.8
# 	define SPEED_R 0.4

typedef struct s_point
{
	double	x;
	double	y;
}				t_point;

typedef struct s_map
{
	char **map;
	int col;
	int exit;
	int collect;
	int	max_y;
	int x_ray;
	int y_ray;
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

typedef struct s_color
{
	int floor_red;
	int floor_blue;
	int floor_green;
	int celling_red;
	int celling_blue;
	int celling_green;
} t_color;

typedef struct s_player {
	t_point	pos;
	t_point	dir;
	char	start_dir;
}				t_player;


typedef struct s_ray
{
	t_point	dir;
	t_point	delta;
	t_point	side;
	int		i;
	int		step_x;
	int		step_y;
	int		hit;
}				t_ray;

typedef struct s_wall
{
	int		height;
	int		top;
	int		tex_x;
	double	tex_y;
	double	dist;
}				t_wall;

typedef struct s_data
{
	int length;
	int height;
	int counter;
	void *mlx;
	void *window;
	void *img;
	char *addr;
	int	bits_to_color;
	int bits_to_line;
	int end;
	t_map *map;
	t_imgs *imgs;
	t_color colors;
	t_player	plr;
	t_ray		ray;
	t_point		plane;
	t_wall		wall;
	int	ceil;
	int	floor;

} t_data;

int	handler_keys(int key, t_data *data);

void	drow_game_two(t_data *data);

void    create_ceil(t_data *data);

void    create_floor(t_data *data);

void    drow_game(t_data *data);

void	free_arr(char **arr);

void	fatal_error(char *msg);

void	free_exit(char *msg, t_data *data);

void    init_mlx(t_data *data);

void	move_up_down(int key, t_data *data);

void	move_left_right(int key, t_data *data);

void	rotation(int key, t_data *data);

void	ray_init(t_data *data);

void	ray_run(t_data *data);

void	dist_wall_hit(t_data *data);

void	find_tex_x(t_data *data);

int	find_texel(t_data *data, int x, int y);

void	draw_vert_line(t_data *data);

int main(int argc, char **argv);

void init_data(t_data *data);

int lenght_count(int fd);

int height_count(int fd, int map_lenght);

void parse_input(t_data *data, char **argv);

void check_contentidk(t_data *data);

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

void pars_color(t_data *data, char *line, int counter, int path);

void	draw_point(t_data *data, int color, int x, int y);

int	ft_close(t_data *data);
// void	put_pixel(t_data *data, int x, int y, int color);

void    set_player_napr_pos(t_data *data);

void map_shit(t_data *data, char *config);

void check_content(t_data *data);

#endif