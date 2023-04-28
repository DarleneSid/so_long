/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:57:42 by dsydelny          #+#    #+#             */
/*   Updated: 2022/11/21 13:35:45 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dest2;
	const char	*src2;
	size_t		len;

	if (!src && !dest)
		return (NULL);
	dest2 = dest;
	src2 = src;
	len = 0;
	while (len < n)
	{
		dest2[len] = src2[len];
		len++;
	}
	return (dest);
}
