/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:57:53 by dsydelny          #+#    #+#             */
/*   Updated: 2022/12/05 16:44:27 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	countw( const char *s, char c)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (!c)
		return (1);
	while (s[a])
	{
		if (s[a] != c)
		{
			while (s[a] && s[a] != c)
				a++;
			b++;
		}
		while (s[a] == c)
			a++;
	}
	return (b);
}

void	countl(const char *str, char c, char **tab)
{
	int	i;
	int	len;
	int	w;

	i = 0;
	w = 0;
	if (!c)
		return ;
	while (str[i])
	{
		len = 0;
		if (str[i] != c)
		{
			while (str[i] && str[i++] != c)
				len++;
			tab[w] = malloc(len + 1);
			if (!tab[w])
				return ;
			w++;
		}
		while (str[i] == c)
			i++;
	}
}

void	filltab(const char *s, char c, char **tab, int i)
{
	int	x;
	int	y;

	y = 0;
	while (s[i])
	{
		x = 0;
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
			{
				tab[y][x] = s[i];
				i++;
				x++;
			}
			tab[y][x] = '\0';
			y++;
			i--;
		}
		i++;
	}
	tab[y] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	if (!s[0])
	{
		tab = malloc(1 * sizeof(char *));
		tab[0] = NULL;
		return (tab);
	}
	tab = malloc((countw(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	if (!c)
	{
		tab[0] = ft_strdup(s);
		tab[1] = NULL;
		return (tab);
	}
	countl(s, c, tab);
	filltab(s, c, tab, 0);
	return (tab);
}
