/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 21:21:26 by dsydelny          #+#    #+#             */
/*   Updated: 2023/04/23 21:26:33 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define MAX_LINES 40
	
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <stdio.h>
# include <stdbool.h>

typedef struct t_data 
{
	char 	**map;
	int		size;
	int		nb_c;
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

#endif
