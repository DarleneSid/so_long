/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:46:30 by dsydelny          #+#    #+#             */
/*   Updated: 2022/12/01 14:30:31 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	cnt;

	cnt = ft_strlen((char *)(s));
	while (cnt >= 0)
	{
		if ((unsigned char)s[cnt] == (unsigned char)c)
			return ((char *)(s + cnt));
		cnt--;
	}
	return (NULL);
}
