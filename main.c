#include "cub3d.h"

int main(int argc, char **argv)
{
	t_data data;
	t_map map;

	if (argc != 2)
		error_message("Error!\nFew arguments :c\n");
	// data.mlx = mlx_init();
	if (ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])) != NULL)
	{
		parser_for_text(&data, argv[1]);
		printf("f_r:%d\nf_g:%d\nf_b:%d\n", data.colors.floor_red, data.colors.floor_green, data.colors.floor_blue);
		printf("c_r:%d\nc_g:%d\nc_b:%d\n", data.colors.celling_red, data.colors.celling_green, data.colors.celling_blue);
	}
	else
		error_message("Error!map not .cub");
	return(0);
}