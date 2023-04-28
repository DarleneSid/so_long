/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:44:14 by dsydelny          #+#    #+#             */
/*   Updated: 2023/04/28 22:25:22 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	display_moves(t_mlx *mlx, t_data *data)
{
	int			r;
	int			i;
	static char	*images[10] = {"imgs/0.xpm", "imgs/1.xpm",
		"imgs/2.xpm", "imgs/3.xpm", "imgs/4.xpm", "imgs/5.xpm",
		"imgs/6.xpm", "imgs/7.xpm", "imgs/8.xpm", "imgs/9.xpm"};

	i = -1;
	while (++i < 10)
	{
		mlx->img_moves[i] = mlx_xpm_file_to_image(mlx->mlx, images[i], &r, &r);
		if (!mlx->img_moves[i])
		{
			r = 0;
			while (r < i)
				mlx_destroy_image(data->mlx->mlx, data->mlx->img_moves[r++]);
			ft_freemlx_2(data);
			ft_free_window(data);
			return (1);
		}
	}	
	return (0);
}

int	loadimages(t_mlx *mlx, t_data *data)
{
	int			r;
	int			i;
	static char	*images[17] = {"imgs/rob.xpm", "imgs/base.xpm",
		"imgs/wall.xpm", "imgs/money.xpm", "imgs/doors.xpm", "imgs/1312.xpm",
		"imgs/base_red.xpm", "imgs/base_blue.xpm", "imgs/1312_red.xpm",
		"imgs/1312_blue.xpm", "imgs/rob_r.xpm", "imgs/rob_b.xpm",
		"imgs/door_1.xpm", "imgs/door_2.xpm", "imgs/light_r.xpm",
		"imgs/light_b.xpm", "imgs/n_base.xpm"};

	i = -1;
	while (++i < 17)
	{
		mlx->img[i] = mlx_xpm_file_to_image(mlx->mlx, images[i], &r, &r);
		if (!mlx->img[i])
		{
			r = 0;
			while (r < i)
				mlx_destroy_image(data->mlx->mlx, data->mlx->img[r++]);
			ft_free_window(data);
			return (1);
		}
	}	
	return (0);
}

void	loadmap(t_data *data, t_mlx *mlx)
{
	int	x;
	int	y;

	x = -1;
	while (data->map[++x])
	{
		y = -1;
		while (data->map[x][++y])
		{
			if (data->nb_c != 0)
				put_image(mlx, y, x, data->map[x][y]);
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[16],
				y * 90, data->height * 90);
			put_img_nbr(data, mlx, data->steps, data->width - 1);
			if (data->nb_c == 0)
				put_image2(data, mlx, y, x);
		}
	}
}

int	startgame(t_data *data)
{
	t_mlx	mlx;

	data->mlx = & mlx;
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		return (1);
	mlx.win = mlx_new_window(mlx.mlx, data->width * 90,
			((data->height + 1) * 90), "THE GREAT ROBBERY");
	if (!mlx.win)
	{
		mlx_destroy_display(data->mlx->mlx);
		return (free(mlx.mlx), 1);
	}
	if (loadimages(&mlx, data))
		return (1);
	if (display_moves(&mlx, data))
		return (1);
	loadmap(data, &mlx);
	mlx_hook(mlx.win, KeyPress, KeyPressMask, key_hook, data);
	mlx_hook(mlx.win, 17, 0, ft_freemlx, data);
	mlx_loop(mlx.mlx);
	return (0);
}
