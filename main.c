#include "cub3d.h"

int main(int argc, char **argv)
{
	t_data data;
	t_map map;

	if (argc != 2)
		error_message("Error!\nFew arguments :c\n");
	if (ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])) != NULL)
	{
		parser_for_text(&data, argv[1]);
	}
	else
		error_message("NO!");
	return(0);
}