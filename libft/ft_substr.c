/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:40:09 by dsydelny          #+#    #+#             */
/*   Updated: 2022/12/01 14:35:10 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	size_t	cnt;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	s1 = malloc((len * sizeof(char)) + 1);
	if (!s1)
		return (NULL);
	cnt = 0;
	while (cnt < len && s[start])
	{
		s1[cnt] = s[start];
		start++;
		cnt++;
	}
	s1[cnt] = '\0';
	return (s1);
}
