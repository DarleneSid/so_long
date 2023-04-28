/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:03:05 by dsydelny          #+#    #+#             */
/*   Updated: 2023/04/21 00:08:48 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stddef.h>

char	*get_next_line(int fd);
char	*end_of_line(char **text);
char	*last_line(char **text);
int		ft_gnl_strlen(char *s);
char	*ft_gnl_strdup(char *s);
char	*ft_gnl_strndup(char *s, int n);
char	*ft_gnl_strjoin(char *s1, char *s2);
char	*ft_gnl_strchr(char *s, int c);
char	*nothing_to_read(char **text, char *buf);

#endif
