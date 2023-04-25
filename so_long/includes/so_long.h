/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 21:21:26 by dsydelny          #+#    #+#             */
/*   Updated: 2023/04/25 20:52:16 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define MAX_LINES 40
	
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "../ft_printf/ft_printf.h"
# include <X11/X.h>
# include <stdio.h>
# include <stdbool.h>


typedef	int	t_moha	__attribute__((ext_vector_type(2)));

typedef struct t_mlx
{
	void	*mlx;
	void	*win;
	void	*img[5];
}			t_mlx;

typedef struct t_data 
{
	char 		**map;
	int			size;
	int			nb_c;
	int			height;
	int			width;
	t_moha		pos_p;
	t_moha		pos_e;
	t_mlx		*mlx;
	// int			cond;
}			t_data;

typedef struct t_cnt
{
	int	cnt_p;
	int	cnt_c;
	int	cnt_e;
}			t_cnt;

/* parsing.c */
int		parsing(t_data *data, char *file);

/* error.c */
void	exit_safely(char **a, int error_code);
void	free_dstr(char **dstr);

/* moves.c */
int		walkable(char place);
char	**copy_map(char **old);
void	set_tile(char *tile, char data);
int		go_through_map(char **map, int walking);;
char	**set_map_to_p(char **map_old);
int		is_there_e_or_c(char **map);


/* visualizer.c */
int		map_size(char **map);
void	resest_cursor(int size);
void	printf_map(char **map);
void	visualize(char **map);

/* game.c */
int startgame(t_data *data);
int	loadimages(t_mlx *mlx, t_data *data);
int	loadmap(t_data *data, t_mlx *mlx);
int	ft_free_window(t_data *data);
int	key_hook(int keycode, t_data *data);
int	ft_freemlx(t_data *data);


#endif
