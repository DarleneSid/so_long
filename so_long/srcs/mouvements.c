/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:40:51 by dsydelny          #+#    #+#             */
/*   Updated: 2023/04/25 00:03:01 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_freemlx(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 5)
		mlx_destroy_image(data->mlx->mlx, data->mlx->img[i]);
	mlx_clear_window(data->mlx->mlx, data->mlx->win);
	mlx_destroy_window(data->mlx->mlx, data->mlx->win);
	mlx_destroy_display(data->mlx->mlx);
	free(data->mlx->mlx);
	exit_safely(data->map, 4);
	exit(1);
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	int x = 0;
	if (keycode == 'q' || keycode == 65307)
		ft_freemlx(data);
	if (keycode == 'w' || keycode == 65362)
	{
		if (data->map[data->pos_p.x - 1][data->pos_p.y] == '1')
			return 0;
		if (data->map[data->pos_p.x - 1][data->pos_p.y] == 'C')
			data->nb_c--;
		data->map[data->pos_p.x][data->pos_p.y] = '0';
		data->map[data->pos_p.x -= 1][data->pos_p.y] = 'P';
	}
	if (keycode == 'a' || keycode == 65361)
	{
		if (data->map[data->pos_p.x][data->pos_p.y - 1] == '1')
			return 0;
		if (data->map[data->pos_p.x][data->pos_p.y - 1] == 'C')
			data->nb_c--;
		data->map[data->pos_p.x][data->pos_p.y] = '0';
		data->map[data->pos_p.x][data->pos_p.y -= 1] = 'P';
		
	}
	if (keycode == 's' || keycode == 65364)
	{
		if (data->map[data->pos_p.x + 1][data->pos_p.y] == '1')
			return 0;
		if (data->map[data->pos_p.x + 1][data->pos_p.y] == 'C')
			data->nb_c--;
		data->map[data->pos_p.x][data->pos_p.y] = '0';
		data->map[data->pos_p.x += 1][data->pos_p.y] = 'P';
	}
	if (keycode == 'd' || keycode == 65363)
	{
		if (data->map[data->pos_p.x][data->pos_p.y + 1] == '1')
			return 0;
		if (data->map[data->pos_p.x][data->pos_p.y + 1] == 'C')
			data->nb_c--;
		data->map[data->pos_p.x][data->pos_p.y] = '0';
		data->map[data->pos_p.x][data->pos_p.y += 1] = 'P';
		
	}
	if (data->map[data->pos_p.x][data->pos_p.y] ==
	data->map[data->pos_e.x][data->pos_e.y])
		ft_freemlx(data);
	// if (data->nb_c == 0)
	// 	data->cond = 4;
	loadmap(data, data->mlx);
	return (1);
}
