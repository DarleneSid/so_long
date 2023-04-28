/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nums.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:28:33 by dsydelny          #+#    #+#             */
/*   Updated: 2022/12/05 17:22:15 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_putnbr(long int n)
{
	int	l;

	l = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		l++;
	}
	while (n > 0)
	{
		n /= 10;
		l++;
	}
	return (l);
}

int	len_uns_putnbr(unsigned int n)
{
	int	l;

	l = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		l++;
	}
	return (l);
}

int	ft_putnbr_l(int n)
{
	long int	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_l('-');
		nb = -nb;
	}
	if (nb <= 9)
		ft_putchar_l(nb + '0');
	else
	{
		ft_putnbr_l(nb / 10);
		ft_putchar_l(nb % 10 + '0');
	}
	return (len_putnbr(n));
}

int	ft_uns_putnbr(unsigned	int n)
{
	unsigned int	nb;

	nb = n;
	if (n <= 9)
		ft_putchar_l(nb + '0');
	else
	{
		ft_uns_putnbr(nb / 10);
		ft_putchar_l(nb % 10 + '0');
	}
	return (len_uns_putnbr(n));
}
