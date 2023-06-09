/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:24:27 by dsydelny          #+#    #+#             */
/*   Updated: 2023/04/28 19:19:23 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

int	walkable(char place)
{
	if (place != '1' && place != 'P' && place != '2')
		return (1);
	return (0);
}

char	**copy_map(char **old)
{
	char	**new;
	int		i;
	int		size;

	size = 0;
	while (old[size])
		size++;
	new = malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (NULL);
	i = 0;
	new[size] = 0;
	while (i < size)
	{
		new[i] = ft_strdup(old[i]);
		if (!new[i])
			return (free_dstr(new), NULL);
		i++;
	}
	return (new);
}

int	go_through_map(char **map, int walking)
{
	int	x;
	int	y;

	x = -1;
	while (map[++x])
	{
		y = -1;
		while (map[x][++y])
		{
			if (map[x][y] == 'P')
			{
				if (walkable(map[x - 1][y]))
					(set_tile(&map[x - 1][y], 'P'), walking = 1);
				if (walkable(map[x + 1][y]))
					(set_tile(&map[x + 1][y], 'P'), walking = 1);
				if (walkable(map[x][y - 1]))
					(set_tile(&map[x][y - 1], 'P'), walking = 1);
				if (walkable(map[x][y + 1]))
					(set_tile(&map[x][y + 1], 'P'), walking = 1);
			}
		}
	}
	return (walking);
}

char	**set_map_to_p(char **map_old)
{
	char	**map;
	int		walking;

	walking = 1;
	map = copy_map(map_old);
	if (!map)
		return (NULL);
	while (walking)
		walking = go_through_map(map, 0);
	return (map);
}

int	is_there_e_or_c(char **map)
{
	int	x;

	x = -1;
	while (map[++x])
		if (ft_strchr(map[x], 'C') || ft_strchr(map[x], 'E'))
			return (free_dstr(map), 1);
	return (free_dstr(map), 0);
}
