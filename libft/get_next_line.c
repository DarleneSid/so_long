/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:02:15 by dsydelny          #+#    #+#             */
/*   Updated: 2023/04/21 22:55:31 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*end_of_line(char **text)
{
	char	*just_line;
	char	*new_text;
	int		end_line;

	end_line = 0;
	while ((*text)[end_line] != '\n' && (*text)[end_line] != '\0')
		end_line++;
	just_line = ft_gnl_strndup((*text), end_line + 1);
	if ((*text)[end_line])
	{
		new_text = (*text);
		(*text) = ft_gnl_strdup(&(*text)[end_line + 1]);
		free(new_text);
	}
	if ((**text) == 0)
	{
		free (*text);
		*text = NULL;
	}
	return (just_line);
}

char	*last_line(char **text)
{
	char	*l_line;

	l_line = ft_gnl_strdup(*text);
	free(*text);
	(*text) = NULL;
	return (l_line);
}

char	*nothing_to_read(char **text, char *buf)
{
	if (*text && **text)
		return (free(buf), last_line(text));
	free(*text);
	*text = NULL;
	return (free(buf), NULL);
}

char	*get_next_line(int fd)
{
	static char	*text = NULL;
	char		*line;
	char		*buf;
	int			val_rd;

	val_rd = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!ft_gnl_strchr(text, '\n'))
	{
		val_rd = read(fd, buf, BUFFER_SIZE);
		if (val_rd == -1)
			return (free(buf), NULL);
		if (!val_rd)
			return (nothing_to_read(&text, buf));
		buf[val_rd] = '\0';
		text = ft_gnl_strjoin(text, buf);
	}
	line = end_of_line(&text);
	return (free(buf), line);
}
