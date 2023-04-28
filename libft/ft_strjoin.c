/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:45:06 by dsydelny          #+#    #+#             */
/*   Updated: 2022/11/21 13:09:25 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		cnt;
	int		cnt2;

	cnt = 0;
	cnt2 = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s3 = malloc((ft_strlen(s1) + ft_strlen(s2)) * (sizeof(char)) + 1);
	if (!s3)
		return (NULL);
	while (s1[cnt])
		s3[cnt2++] = s1[cnt++];
	cnt = 0;
	while (s2[cnt])
		s3[cnt2++] = s2[cnt++];
	s3[cnt2] = '\0';
	return (s3);
}
