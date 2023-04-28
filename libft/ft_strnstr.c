/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:48:58 by dsydelny          #+#    #+#             */
/*   Updated: 2022/12/07 19:11:39 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	cnt;
	int		cnt2;

	cnt = 0;
	cnt2 = 0;
	if (little[0] == '\0')
		return ((char *)big);
	if (!len)
		return (NULL);
	while (big[cnt] && cnt < len)
	{
		while (big[cnt + cnt2] == little[cnt2] && cnt + cnt2 < len)
		{
			cnt2++;
			if (little[cnt2] == '\0')
				return ((char *)&big[cnt]);
		}
		cnt2 = 0;
		cnt++;
	}
	return (NULL);
}
