/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:13:45 by ocapers           #+#    #+#             */
/*   Updated: 2022/09/09 14:12:49 by sdavos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define TRUE 1
# define FALSE 0
# define BUFFER_SIZE 10
# define WIN_HEIGHT 1080
# define WIN_LENGHT 1920
# define RAYS 960
# define UP 1
# define DOWN 2
# define LEFT 123
# define RIGHT 124
# define UP_KEY 13
# define DOWN_KEY 1
# define LEFT_KEY 0
# define RIGHT_KEY 2
# define SPACE 49
# define ENTER 256
# define ESC 53
# define GUN 12
# define WALL_COLOR 0x000000
# define SPACE_COLOR 0xFFFFFF
# define PLAYER_COLOR 0xFF0000
# define POINT_SIZE 12
# define FOV 0.66
# define SPEED_P 0.05
# define SPEED_R 0.05
# define SPEED_R_M 0.04
# define SCALE 13
# define MMAP_WIDTH 33
# define MMAP_HEIGH 14
# define YELLOW 0x00FFFF00
# define GREEN 0x0000FF00

typedef struct s_keys
{
	int	up_key;
	int	down_key;
	int	left_key;
	int	right_key;
	int	left;
	int	right;
	int	esc;
	int	space;
	int	enter;
	int	gun;
}	t_keys;

typedef struct s_map
{
	char	**map;
	int		length;
	int		height;
}	t_map;

typedef struct s_pixel
{
	void	*img;
	void	*addr;
	int		bits_pixel;
	int		bits_line;
	int		end;
}	t_pixel;

typedef struct s_imgs
{
	t_pixel	pixel;
	int		width;
	int		height;	
}	t_imgs;

typedef struct s_window
{
	t_pixel	pixel;
	void	*mlx;
	void	*window;
}	t_window;

typedef struct s_color
{
	int	floor_red;
	int	floor_blue;
	int	floor_green;
	int	celling_red;
	int	celling_blue;
	int	celling_green;
}	t_color;

typedef struct s_doub {
	double	x;
	double	y;
}	t_doub;

typedef struct s_player {
	t_doub	pos;
	t_doub	dir;
	t_doub	plane;
	char	start_dir;
	double	rot;
}	t_player;

typedef struct s_ray
{
	int				x;
	double			camera_x;
	t_doub			ray_dir;
	int				map_x;
	int				map_y;
	t_doub			side_dist;
	t_doub			delta_dist;
	double			wall_x;
	int				tex_x;
	int				tex_y;
	double			step;
	double			tex_pos;
	t_imgs			wall;
	unsigned int	color;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
}	t_ray;

typedef struct s_anims
{
	int		anim_gun;
	void	*guns_imgs[20];
	int		x[20];
	int		y[20];
	int		anim_wall;
}	t_anims;

typedef struct s_data
{
	int			floor;
	int			ceil;
	t_color		colors;
	t_pixel		floor_ceil;
	t_window	*win;
	t_imgs		walls[7];
	t_map		map;
	t_player	plr;
	t_ray		*ray;
	t_keys		key;
	t_anims		anims;
	int			mouse;
	t_pixel		minimap;
	t_pixel		minimap_2;
}	t_data;

void		pars_anim_wall_xpm(t_data *data, int counter);

void		pars_color_help(t_data *data, char *line, int i, int *count);

char		*skip_for_map(int fd);

char		*skip_for_map_1(int fd);

int			set_pos(t_data *data, int i, int j, int content);

void		set_dir_rot_plane(t_data *data, int i, int j);

void		pars_wall(t_data *data, char *line, t_imgs *wall);

void		pars_fire_walls(t_data *data, char *line, t_imgs *wall);

void		pars_color(t_data *data, char *line, int counter, int path);

void		move_up_down(t_data *data);

void		get_h(t_data *data, char *config);

void		get_l(t_data *data, char *config, char *line);

void		errors_map(int *content);

void		error_for_color(t_data *data);

void		error_for_color_2(char **dst, int count, int i);

void		error_for_text(int *count);

void		bzero_for_array(int *array, int len);

void		init_raycast_help(t_data *data, t_ray *ray);

void		anim_fire_raycast(t_data *data, t_ray *ray);

void		raycast_help(t_data *data, t_ray *ray);

void		anims_parse_two(t_data *data, char **guns);

void		anims_parse(t_data *data);

const char	*f_strchr(const char *s, int c);

void		ft_minimap(t_data *data);

void		get_img_minimap_2(t_data *data);

void		get_img_minimap(t_data *data);

int			mouse_rotation(int x, int y, t_data *data);

void		open_door(t_data *data);

void		pars_wall(t_data *data, char *line, t_imgs *wall);

void		new_drow_floor_ceil(t_data *data);

void		drow_game_two(t_data *data);

void		create_ceil(t_data *data);

void		create_floor(t_data *data);

void		drow_game(t_data *data);

void		free_arr(char **arr);

void		fatal_error(char *msg);

void		free_exit(t_data *data);

void		init_mlx(t_data *data);

void		move_up_down(t_data *data);

void		move_left_right(t_data *data);

void		rotation(t_data *data);

void		ray_init(t_data *data);

void		ray_run(t_data *data);

void		dist_wall_hit(t_data *data);

void		find_tex_x(t_data *data);

int			find_texel(t_data *data, int x, int y);

void		draw_vert_line(t_data *data);

int			main(int argc, char **argv);

void		init_data(t_data *data);

int			lenght_count(int fd);

int			height_count(int fd, int map_lenght);

void		parse_input(t_data *data, char **argv);

void		check_contentidk(t_data *data);

void		check_border(t_data *data);

int			counter_for_map(char *s, char c);

char		*ft_strjoin(char *all_text, char *tmp);

char		*ft_strchr(char *s, int c);

char		*copy_from_txt(int fd, char *all_text);

char		*get_line(char *all_text);

char		*skip_before_new_line(char *all_text);

char		*get_next_line(int fd);

void		error_message(char *message, t_data *data);

void		parser_for_text(t_data *data, char *name);

void		pars_textures(t_data *data, char *line, int counter, int path);

// void		pars_color(t_data *data, char *line, int path);

void		draw_point(t_data *data, int color, int x, int y);

int			ft_close(t_data *data);

void		put_pixel(t_pixel *pix, int x, int y, int color);

void		set_player_napr_pos(t_data *data);

void		map_shit(t_data *data, char *config);

void		check_content(t_data *data);

void		parse_texture_2(t_data *data, int **addr, char *line, int i);

void		copy(int **addr, void *img);

void		*ft_memcpy(void *dst, const void *src, size_t n);

int			keys(t_data *data);

void		raycast_three(t_data *data, t_ray *ray);

void		raycast_two(t_ray *ray);

void		raycast_four(t_data *data, t_ray *ray);

void		raycast(t_data *data, t_ray *ray);

void		init_raycast(t_data	*data, t_ray *ray);

int			handler_keys(int key, t_data *data);

int			non_handler_keys(int key, t_data *data);

void		check_border(t_data *data);

void		main_2(t_window win, t_data data);

void		close_door(t_data *data);

void		keys_help(t_ray ray, t_data *data, int path);

void		key_help_2(t_data *data);

#endif