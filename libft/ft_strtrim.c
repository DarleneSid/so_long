/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:27:13 by dsydelny          #+#    #+#             */
/*   Updated: 2022/12/01 14:43:24 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check(char a, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == a)
			return (1);
		i++;
	}
	return (0);
}

int	ft_firstcut(char const *s1, char const *set)
{
	int	cnt;

	cnt = 0;
	while (ft_check(s1[cnt], set) && s1[cnt])
		cnt++;
	return (cnt);
}

int	ft_secondcut(char const *s1, char const *set)
{
	int	cntb;

	cntb = ft_strlen(s1) - 1;
	while (ft_check(s1[cntb], set) && cntb > 0)
		cntb--;
	return (cntb);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	cnt;
	size_t	cntb;
	int		cnt1;
	char	*strim;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	cnt = ft_firstcut(s1, set);
	if (cnt == ft_strlen(s1))
		return (ft_strdup(""));
	cntb = ft_secondcut(s1, set);
	strim = malloc((ft_strlen(s1) - cnt - (ft_strlen(s1) - cntb))
			* sizeof(char) + 2);
	if (!strim)
		return (NULL);
	cnt1 = 0;
	while (cnt <= cntb)
	{
		strim[cnt1++] = s1[cnt++];
	}
	strim[cnt1] = '\0';
	return (strim);
}
