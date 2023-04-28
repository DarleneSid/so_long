/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:57:54 by dsydelny          #+#    #+#             */
/*   Updated: 2022/12/05 17:40:09 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	cnt;

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
