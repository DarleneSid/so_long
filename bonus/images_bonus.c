/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 22:05:06 by dsydelny          #+#    #+#             */
/*   Updated: 2023/04/27 22:06:10 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	if (c == '2')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[5],
			y * 90, x * 90);
}

void	put_image2(t_data *data, t_mlx *mlx, int y, int x)
{
	int	r;

	r = 1;
	if (data->steps % 2)
		r = 0;
	if (data->map[x][y] == '0')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[6 + r],
			y * 90, x * 90);
	if (data->map[x][y] == '2')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[8 + r],
			y * 90, x * 90);
	if (data->map[x][y] == 'P')
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->img[10 + r], y * 90, x * 90);
	if (data->map[x][y] == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->img[14 + r], y * 90, x * 90);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[12 + r],
		data->pos_e.y * 90, data->pos_e.x * 90);
}

void	put_img_nbr(t_data *data, t_mlx *mlx, int nbr, int width)
{
	if (nbr != 0)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_moves[nbr % 10],
			width * 90, data->height * 90);
		put_img_nbr(data, mlx, nbr / 10, width - 1);
	}
}
