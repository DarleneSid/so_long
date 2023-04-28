/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:59:25 by dsydelny          #+#    #+#             */
/*   Updated: 2022/12/01 14:38:12 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			cnt;
	unsigned char	*ss1;
	unsigned char	*ss2;

	cnt = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while ((ss1[cnt] || ss2[cnt]) && cnt < n)
	{
		if (ss1[cnt] != ss2[cnt])
			return (ss1[cnt] - ss2[cnt]);
		cnt++;
	}
	return (0);
}
