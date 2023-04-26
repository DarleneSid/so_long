/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 22:01:58 by dsydelny          #+#    #+#             */
/*   Updated: 2023/04/26 21:14:24 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_dstr(char **dstr)
{
	int	i;

	if (!dstr)
		return ;
	i = 0;
	while (dstr[i])
		free(dstr[i++]);
	free(dstr);
}

void	exit_safely(char **a, int error_code)
{
	int	cnt;

	cnt = 0;
	free_dstr(a);
	if (error_code == 1)
		ft_printf("Error\n");
	if (error_code == 2)
		ft_printf("No Error\n");
	if (error_code == 3)
		ft_printf("Follow rules of filling map!\n");
	exit (1);
}

int	main(int ac, char **av)
{
	t_data	data;

	ft_memset(& data, 0, sizeof(t_data));
	if (ac != 2)
		return (write(2, "Error\n", 6));
	if (ft_strlen(av[1]) <= 4)
		return (ft_printf("Not valid file!\n"), 1);
	if (ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".ber\0", 5))
		return (ft_printf("It has to end with .ber!\n"), 1);
	if (parsing(& data, av[1]))
		return (1);
	if (startgame(& data))
		return (free_dstr(data.map), 1);
	exit_safely(data.map, 0);
}

/*
PLAN 

i need to find exit?? make sure theres single e and p and c
(counter should be 1) for p and e

minilib????

*/

// x = 0;

// printf (++x) 1
// printf (x) 1

// x = 0;
// printf (x++) 0
// printf (x) 1
