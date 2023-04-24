/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:17:43 by dsydelny          #+#    #+#             */
/*   Updated: 2023/04/23 22:13:45 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_borders(t_data *data)
{
	int x;
	int y;
	int len_x;
	int len_y;

	x = -1;
	y = -1;
	len_y = ft_strlen(data->map[0]) - 1;
	while (data->map[++x]) 
		if (data->map[x][0] != '1' || data->map[x][len_y] != '1')
			return(1);
	len_x = x - 1;
	while (++y <= len_y)
		if (data->map[0][y] != '1' || data->map[len_x][y] != '1')
			return(1);
	return (0);
}

int	check_valid_chars(t_data *data)
{
	int x;
	int y;

	x = -1;
	while (data->map[++x])
	{
		y = -1;
		while (data->map[x][++y])
		{
			if (!ft_strchr("1CP0E", data->map[x][y]))
				return(1);
		}
	}
	return (0);
}

int map_rules(t_data *data)
{
	int	x;
	int	y;
	t_cnt counter;

	ft_memset(& counter, 0, sizeof(t_cnt));
	x = -1;
	while (data->map[++x])
	{
		y = -1;
		while (data->map[x][++y])
		{
			if (data->map[x][y] == 'P')
				counter.cnt_p++;
			if (data->map[x][y] == 'E')
				counter.cnt_e++;
			if (data->map[x][y] == 'C')
				counter.cnt_c++;
		}
	}
	if (counter.cnt_p != 1 || counter.cnt_e != 1 || counter.cnt_c < 1)
		return (1);
	data->nb_c = counter.cnt_c;
	return (0);
}

void print_map(char **map)
{
	for (int i = 0; map[i]; i++)
		printf("%s\n", map[i]);
}

int fill_map(t_data *data, char *file)
{
	int		fd;
	static int		var = 0;
	char 	*str;
	char 	*tmp;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		(ft_printf("Not valid fd!\n"), exit(0));
	str = get_next_line(fd);
	if (!str)
		return (close(fd), 1);
	data->size = ft_strlen(str);
	while (str)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		if (!ft_strncmp(tmp, "\n", 1))
			var = 1;
		str = ft_gnl_strjoin(str, tmp);
		free(tmp);
	}
	close(fd);
	free(tmp);
	data->map = ft_split(str, '\n');
	if (!*data->map)
		return (free(str), 1);
	free(str);
	if (var == 1)
		return (1);
	return (0);
}

int	parsing(t_data *data, char *file)
{
	if (fill_map(data, file))
		return (exit_safely(data->map, 1), 1);
	//printf_map(data->map);
	//resest_cursor(map_size(data->map));
	if (check_borders(data))
		return (exit_safely(data->map, 1), 1);
	if (check_valid_chars(data))
		return (exit_safely(data->map, 1), 1);
	if (map_rules(data))
		return (exit_safely(data->map, 3), 1);
	if (is_there_e_or_c(set_map_to_p(data->map)))
		return (exit_safely(data->map, 3), 1);	
	return (0);
}