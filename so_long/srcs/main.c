/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 22:01:58 by dsydelny          #+#    #+#             */
/*   Updated: 2023/04/21 00:21:23 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	check_format()

int main(int ac, char **av)
{
	(void)av;
	if (ac != 2)
		return (write(2, "Error\n", 6));
	char **tab = ft_split("fddsfdsfdfs", 'd');
	char *s = ft_strnstr("avion.berdsfsdfsd", ".ber", ft_strlen("avion.ber"));
	ft_printf("%s\n", s);
	// if (av[1] )
	//check .ber
	//if(check extantion av[1])
}

/*

STEP 1
	check .ber with strnstr
	check .ber correctly
	read whole file and check correctly if it can be opened

	check borders (everywhere 1)
	check same lenght(quite if different)
	check character, collictibles, exit




*/