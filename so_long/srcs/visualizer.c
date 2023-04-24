# define RED     "\033[1;31m"
# define GREEN   "\033[1;32m"
# define YELLOW  "\033[1;33m"
# define BLUE    "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN    "\033[1;36m"
# define RESET   "\033[0;0m"
# define BACK    "\033[F"
# define PREV_LN "\033[A"
#include "so_long.h"

int	map_size(char **map)
{
	int	size;

	size = 0;
	while (map[size])
		size++;
	return (size);
}

void	resest_cursor(int size)
{
	while (size-- >= 0)
	{
		printf(PREV_LN);
	}
}

void	printf_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				printf(BLUE);
			if (map[i][j] == '0')
				printf(YELLOW);
			if (map[i][j] == 'P')
				printf(RED);
			if (map[i][j] == 'C')
				printf(GREEN);
			if (map[i][j] == 'E')
				printf(MAGENTA);
			printf("%c", map[i][j]);
			printf(RESET);
			j++;
		}
		i++;
		printf("\n");
	}
}

void	visualize(char **map)
{
	int		size;
	char	*buffer;

	size = map_size(map);
	buffer = get_next_line(0);
	while (buffer)
	{
		if (buffer[0] == '\n')
		{
			printf_map(map);
			resest_cursor(size);
			free(buffer);
			return ;
		}
		free(buffer);
		buffer = get_next_line(0);
	}
}
