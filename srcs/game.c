/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:44:14 by dsydelny          #+#    #+#             */
/*   Updated: 2023/04/28 18:36:20 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_mlx *mlx, int y, int x, char c)
{
	if (c == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[2],
			y * 90, x * 90);
	if (c == 'C')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[3],
			y * 90, x * 90);
	if (c == 'P')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[0],
			y * 90, x * 90);
	if (c == '0' || c == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[1],
			y * 90, x * 90);
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
			put_image(mlx, y, x, data->map[x][y]);
			if (data->nb_c == 0)
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[4],
					data->pos_e.y * 90, data->pos_e.x * 90);
		}
	}
}

int	loadimages(t_mlx *mlx, t_data *data)
{
	int			r;
	int			i;
	static char	*images[5] = {"imgs/rob.xpm", "imgs/base.xpm",
		"imgs/wall.xpm", "imgs/money.xpm", "imgs/doors.xpm",
	};

	i = -1;
	while (++i < 5)
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

int	startgame(t_data *data)
{
	t_mlx	mlx;

	data->mlx = & mlx;
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		return (1);
	mlx.win = mlx_new_window(mlx.mlx, data->width * 90,
			data->height * 90, "THE GREAT ROBBERY");
	if (!mlx.win)
	{
		mlx_destroy_display(data->mlx->mlx);
		return (free(mlx.mlx), 1);
	}
	if (loadimages(&mlx, data))
		return (1);
	loadmap(data, &mlx);
	mlx_hook(mlx.win, KeyPress, KeyPressMask, key_hook, data);
	mlx_hook(mlx.win, 17, 0, ft_freemlx, data);
	mlx_loop(mlx.mlx);
	return (0);
}
