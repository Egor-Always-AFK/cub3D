#include "cub3d.h"

void parser_for_text(t_data *data, char *name)
{
	int i = 0;
	int count[4]; // 1 - NO; 2 - SO; 3 - WE; 4 - EA
	char *line;
	int fd = open(name, O_RDONLY);
	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	count[3] = 0;
	if (fd == -1)
		error_message("Wow i can't open this conf :'c\n");
	line = get_next_line(fd);
	while (line[0] != '\n')
	{
		i = 0;
		while (line[i] != '\n')
		{
			if (line[i] == ' ')
				i++;
			else if (line[i] == 'N' && line[i + 1] == 'O')
			{
				pars_textures(data, line, i + 2, 0);
				count[0] += 1;
				break;
			}
			else if (line[i] == 'S' && line[i + 1] == 'O')
			{
				pars_textures(data, line, i + 2, 1);
				count[1] += 1;
				break;
			}
			else if (line[i] == 'W' && line[i + 1] == 'E')
			{
				pars_textures(data, line, i + 2, 2);
				count[2] += 1;
				break;
			}
			else if(line[i] == 'E' && line[i + 1] == 'A')
			{
				pars_textures(data, line, i + 2, 3);
				count[3] += 1;
				break;
			}
		}
		line = get_next_line(fd);
	}
	// printf("C[1]=%d\nC[2]=%d\nC[3]=%d\nC[4]=%d\n", count[0], count[1], count[2], count[3]);
	if (count[0] != 1 || count[1] != 1 || count[2] != 1 || count[3] != 1)
		error_message("parsing error!");
}

void pars_textures(t_data *data, char *line, int counter, int path)
{
	if(line[counter] == ' ')
		while(line[counter] == ' ')
			counter++;
	if (path == 0)
	{
		
	}
}