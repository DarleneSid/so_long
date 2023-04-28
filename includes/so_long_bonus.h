/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 21:21:26 by dsydelny          #+#    #+#             */
/*   Updated: 2023/04/28 17:32:10 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define MAX_LINES 50
# define PREV_LN "\033[A"

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "../ft_printf/ft_printf.h"
# include <X11/X.h>
# include <stdio.h>
# include <stdbool.h>

typedef int	t_moha	__attribute__((ext_vector_type(2)));

typedef struct t_mlx
{
	void	*mlx;
	void	*win;
	void	*img[17];
	void	*img_moves[10];
}			t_mlx;

typedef struct t_data
{
	char		**map;
	int			size;
	int			nb_c;
	int			height;
	int			width;
	int			steps;
	t_moha		pos_p;
	t_moha		pos_e;
	t_moha		pos_en;
	t_mlx		*mlx;
}			t_data;

typedef struct t_cnt
{
	int	cnt_p;
	int	cnt_c;
	int	cnt_e;
	int	cnt_en;
}			t_cnt;

/* parsing_bonus.c */
int		check_borders(t_data *data);
int		check_valid_chars(t_data *data);
int		map_rules(t_data *data);
int		fill_map(t_data *data, char *file, int fd);
int		parsing(t_data *data, char *file);

/* images_bonus.c */
void	put_image(t_mlx *mlx, int y, int x, char c);
void	put_image2(t_data *data, t_mlx *mlx, int y, int x);
void	put_img_nbr(t_data *data, t_mlx *mlx, int nbr, int width);

/* moves_bonus.c */
int		walkable(char place);
char	**copy_map(char **old);
int		go_through_map(char **map, int walking);
char	**set_map_to_p(char **map_old);
int		is_there_e_or_c(char **map);

/* movements_bonus.c */
int		ft_freemlx(t_data *data);
int		ft_freemlx_2(t_data *data);
int		ft_free_window(t_data *data);
int		key_hook(int keycode, t_data *data);

/* game_bonus.c */
int		display_moves(t_mlx *mlx, t_data *data);
int		loadimages(t_mlx *mlx, t_data *data);
void	loadmap(t_data *data, t_mlx *mlx);
int		startgame(t_data *data);

/* steps_bonus.c */
int		step_up(int keycode, t_data *data);
int		step_left(int keycode, t_data *data);
int		step_down(int keycode, t_data *data);
int		step_right(int keycode, t_data *data);
void	set_tile(char *tile, char data);

/* main_bonus.c */
void	free_dstr(char **dstr);
void	exit_safely(char **a, int error_code);
int		main(int ac, char **av);

#endif
