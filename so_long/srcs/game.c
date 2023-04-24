/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:44:14 by dsydelny          #+#    #+#             */
/*   Updated: 2023/04/25 00:06:12 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	loadmap(t_data *data, t_mlx *mlx)
{
	int x, y;
	// static int rand;
	x = -1;
	while (data->map[++x])
	{
		y = -1;
		while (data->map[x][++y])
		{
			if (data->map[x][y] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[2], y * 64, x * 64);
			if (data->map[x][y] == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[3], y * 64, x * 64);		
			if (data->map[x][y] == 'P')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[0], y * 64, x * 64);		
			if (data->map[x][y] == '0' || data->map[x][y] == 'E')
				// mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[data->cond], y * 64, x * 64);
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[1], y * 64, x * 64);
			if (data->nb_c == 0)
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[4], data->pos_e.y * 64, data->pos_e.x * 64);
		}
	}
	// rand++;
	return (0);
}


int	loadimages(t_mlx *mlx)
{
	int	r;
	int i;
	static const char	*images[5] = {
		"imgs/wall.xpm", "imgs/bow.xpm", "imgs/tree.xpm", "imgs/flower.xpm", "imgs/door.xpm"
	};

	i = -1;
	while (++i < 5)
	{
		mlx->img[i] = mlx_xpm_file_to_image(mlx->mlx, images[i], &r, &r);
		// if (!mlx->img[i])
			// free(imgs, i)
	}	

	return (0);	
}

#include <sys/time.h>
# define PREV_LN "\033[A"

int	display_hour(void)
{
	struct	timeval	time;
	// int				hour;
	// int				min;
	int				sec;
	
	gettimeofday(&time, 0);
	// hour = time.tv_sec / 3600;
	// min = (time.tv_sec - hour * 3600) / 60;
	sec = time.tv_sec % 60;
	// printf("%d\n", sec);
	// printf(PREV_LN);
	return (1);
}

int startgame(t_data *data)
{
	t_mlx mlx;
	
	data->mlx = & mlx;
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		return (1);
	// data->cond = 1;
	mlx_do_key_autorepeaton(mlx.mlx);
	// check return
	mlx.win = mlx_new_window(mlx.mlx, data->width * 64, data->height * 64, "Hello dasha!");
	loadimages(&mlx);
	loadmap(data, &mlx);
	mlx_hook(mlx.win, KeyPress, KeyPressMask, key_hook, data);
	mlx_hook(mlx.win, 17, 0, ft_freemlx, data);
	mlx_loop_hook(mlx.mlx, display_hour, NULL);
	mlx_loop(mlx.mlx);
	return (0);	
}
