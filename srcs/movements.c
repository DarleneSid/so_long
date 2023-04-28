/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:40:51 by dsydelny          #+#    #+#             */
/*   Updated: 2023/04/27 14:36:24 by dsydelny         ###   ########.fr       */
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

int	ft_free_window(t_data *data)
{
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
	if (keycode == 'q' || keycode == 65307)
		ft_freemlx(data);
	if (keycode == 'w' || keycode == 65362)
		step_up(keycode, data);
	if (keycode == 'a' || keycode == 65361)
		step_left(keycode, data);
	if (keycode == 's' || keycode == 65364)
		step_down(keycode, data);
	if (keycode == 'd' || keycode == 65363)
		step_right(keycode, data);
	if ((data->map[data->pos_p.x][data->pos_p.y]
		== data->map[data->pos_e.x][data->pos_e.y]) && (data->nb_c == 0))
		ft_freemlx(data);
	loadmap(data, data->mlx);
	return (1);
}
