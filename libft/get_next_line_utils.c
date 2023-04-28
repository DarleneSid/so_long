/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:05:34 by dsydelny          #+#    #+#             */
/*   Updated: 2023/04/24 17:30:00 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_gnl_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_gnl_strdup(char *s)
{
	char	*dup;
	int		count;

	count = 0;
	dup = malloc((ft_gnl_strlen(s) + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (s[count])
	{
		dup[count] = s[count];
		count++;
	}
	dup[count] = 0;
	return (dup);
}

char	*ft_gnl_strndup(char *s, int n)
{
	char	*dup;
	int		count;

	count = 0;
	dup = malloc((ft_gnl_strlen(s) + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (count < n)
	{
		dup[count] = s[count];
		count++;
	}
	dup[count] = 0;
	return (dup);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		cnt;
	int		cnt2;

	cnt = 0;
	cnt2 = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_gnl_strdup(s2));
	if (!s2)
		return (ft_gnl_strdup(s1));
	s3 = malloc((ft_gnl_strlen(s1) + ft_gnl_strlen(s2)) * (sizeof(char)) + 1);
	if (!s3)
		return (NULL);
	while (s1[cnt])
		s3[cnt2++] = s1[cnt++];
	cnt = 0;
	while (s2[cnt])
		s3[cnt2++] = s2[cnt++];
	s3[cnt2] = '\0';
	free(s1);
	return (s3);
}

char	*ft_gnl_strchr(char *s, int c)
{
	int	cnt;

	if (!s)
		return (NULL);
	cnt = 0;
	while (s[cnt])
	{
		if ((unsigned char)s[cnt] == (unsigned char)c)
			return ((char *)(s + cnt));
		cnt++;
	}
	if (s[cnt] == '\0' && c == '\0')
		return ((char *)(s + cnt));
	return (NULL);
}
