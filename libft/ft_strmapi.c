/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:49:31 by dsydelny          #+#    #+#             */
/*   Updated: 2022/11/21 13:10:45 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		a;
	int		lens;
	char	*s1;

	if (!s || !f)
		return (0);
	lens = ft_strlen(s);
	s1 = malloc((lens + 1) * sizeof(char));
	if (!s1)
		return (NULL);
	a = 0;
	while (a < lens)
	{
		s1[a] = f(a, s[a]);
		a++;
	}
	s1[a] = '\0';
	return (s1);
}
