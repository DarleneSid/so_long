/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:57:45 by dsydelny          #+#    #+#             */
/*   Updated: 2022/12/07 18:52:52 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest2;
	const char	*src2;
	size_t		len;

	if (!src && !dest)
		return (NULL);
	dest2 = dest;
	src2 = src;
	len = 0;
	if (src2 > dest2)
	{
		while (n > len)
		{
			dest2[len] = src2[len];
			len++;
		}
	}
	else
	{
		while (n-- > 0)
			dest2[n] = src2[n];
	}
	return (dest);
}
