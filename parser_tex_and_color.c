#include "cub3d.h"

void parser_for_text(t_data *data, char *name)
{
	int count[4]; // 1 - NO; 2 - SO; 3 - WE; 4 - EA
	char *line;
	int fd = open(name, O_RDONLY);
	if (fd < -1)
		error_message("Wow i can't open this conf :'c");
	line = get_next_line(fd);
	// printf("%c", line[0]);
	// printf("%d", ft_strlen(line));
	if ((line[0] != 'N' && line[1] != 'O') && ft_strnstr(line, ".xpm", ft_strlen(line)) == NULL) // условие переписать ( оно не работает не знаю почему oO)
		error_message("oh no, i don't know what are u do :c");

}