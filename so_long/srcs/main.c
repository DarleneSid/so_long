/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 22:01:58 by dsydelny          #+#    #+#             */
/*   Updated: 2023/04/21 22:59:45 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_borders(char **map)
{
	int x;
	int y;
	int len_x;
	int len_y;

	x = 0;
	y = 0;
	len_y = ft_strlen(map[x]) - 2;
	while (map[x]) 
	{
		if (map[x][0] != '1' || map[x][len_y] != '1')
			return(ft_printf("Not valid map! y\n"));
		x++;
	}
	len_x = x - 1; 
	while (y <= len_y)
	{ 
		if (map[0][y] != '1' || map[len_x][y] != '1')
			return(ft_printf("Not valid map! x\n"));
		y++;
	}
	return (0);
}

//len of x == len x++

void	exit_safely(char **a, int error_code)
{
	int	cnt;

	cnt = 0;
	while (a[cnt])
	{
		free(a[cnt]);
		cnt++;
	}
	free(a);
	if (error_code == 1)
		ft_printf("Error\n");
	if (error_code == 2)
		ft_printf("No Error\n");
}

int	check_valid_chars(char *line)
{
	int x;

	x = 0;
	while (line[x + 1])
	{
		if (line[x] != '1' && 
		line[x] != 'P' && line[x] != '0' &&
		line[x] != 'C' && line[x] != 'E')
			return(1);
		x++;
	}
	return (0);
}

int fill_map(char *file)
{
	int size;
	int fd;
	int b;
	char **map;
	
	fd = open(file, O_RDONLY);
	if (fd == -1)
		(ft_printf("Not valid fd!\n"), exit(0));
	map = ft_calloc(MAX_LINES + 1, sizeof(char *));
	if (!map)
		return (1);
	map[0] = get_next_line(fd);	
	size = ft_strlen(map[0]);
	b = 0;
	while (map[b])
	{
		if (check_valid_chars(map[b]))
			return (exit_safely(map, 1), close(fd), 1);
	//	ft_printf("%s", map[b]);
		b++;
		map[b] = get_next_line(fd);
		if (map[b] && (ft_strlen(map[b]) != size || b > MAX_LINES))
			return (exit_safely(map, 1), close(fd), 1);
	}
	check_borders(map);
	exit_safely(map, 2);
	close(fd);
	return (0);
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (write(2, "Error\n", 6));
	int a = ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".ber\0", 5);
	fill_map(av[1]);
}

/*
PLAN 

i need to find exit?? make sure theres single e and p and c
(counter should be 1) for p and e

minilib????

*/


