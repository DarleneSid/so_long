/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:19:44 by dsydelny          #+#    #+#             */
/*   Updated: 2023/04/27 14:35:41 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	step_up(int keycode, t_data *data)
{
	if (data->map[data->pos_p.x - 1][data->pos_p.y] == '1')
		return (0);
	if (data->map[data->pos_p.x - 1][data->pos_p.y] == '2')
		return (ft_printf("YOU DIED\n"), ft_freemlx(data), 1);
	if (data->map[data->pos_p.x - 1][data->pos_p.y] == 'C')
		data->nb_c--;
	data->map[data->pos_p.x][data->pos_p.y] = '0';
	data->pos_p.x -= 1;
	data->map[data->pos_p.x][data->pos_p.y] = 'P';
	data->steps++;
	return (1);
}

int	step_left(int keycode, t_data *data)
{
	if (data->map[data->pos_p.x][data->pos_p.y - 1] == '1')
		return (0);
	if (data->map[data->pos_p.x][data->pos_p.y - 1] == '2')
		return (ft_printf("YOU DIED\n"), ft_freemlx(data), 1);
	if (data->map[data->pos_p.x][data->pos_p.y - 1] == 'C')
		data->nb_c--;
	data->map[data->pos_p.x][data->pos_p.y] = '0';
	data->pos_p.y -= 1;
	data->map[data->pos_p.x][data->pos_p.y] = 'P';
	data->steps++;
	return (1);
}

int	step_down(int keycode, t_data *data)
{
	if (data->map[data->pos_p.x + 1][data->pos_p.y] == '1')
		return (0);
	if (data->map[data->pos_p.x + 1][data->pos_p.y] == '2')
		return (ft_printf("YOU DIED\n"), ft_freemlx(data), 1);
	if (data->map[data->pos_p.x + 1][data->pos_p.y] == 'C')
		data->nb_c--;
	data->map[data->pos_p.x][data->pos_p.y] = '0';
	data->pos_p.x += 1;
	data->map[data->pos_p.x][data->pos_p.y] = 'P';
	data->steps++;
	return (1);
}

int	step_right(int keycode, t_data *data)
{
	if (data->map[data->pos_p.x][data->pos_p.y + 1] == '1')
		return (0);
	if (data->map[data->pos_p.x][data->pos_p.y + 1] == '2')
		return (ft_printf("YOU DIED\n"), ft_freemlx(data), 1);
	if (data->map[data->pos_p.x][data->pos_p.y + 1] == 'C')
		data->nb_c--;
	data->map[data->pos_p.x][data->pos_p.y] = '0';
	data->pos_p.y += 1;
	data->map[data->pos_p.x][data->pos_p.y] = 'P';
	data->steps++;
	return (1);
}

void	set_tile(char *tile, char data)
{
	*tile = data;
}
