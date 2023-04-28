/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:56:26 by dsydelny          #+#    #+#             */
/*   Updated: 2022/12/05 17:38:49 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	chr;
	int	sign;
	int	res;

	chr = 0;
	sign = 1;
	res = 0;
	while (nptr[chr])
	{
		while ((nptr[chr] >= 9 && nptr[chr] <= 13) || nptr[chr] == 32)
			chr++;
		if (nptr[chr] == '-' || nptr[chr] == '+')
		{
			if (nptr[chr] == '-')
				sign = -1;
			chr++;
		}
		while (nptr[chr] >= '0' && nptr[chr] <= '9')
		{
			res = res * 10 + nptr[chr] - '0';
			chr++;
		}
		return (res * sign);
	}
	return (0);
}
