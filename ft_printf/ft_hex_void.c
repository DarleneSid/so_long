/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_void.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:28:25 by dsydelny          #+#    #+#             */
/*   Updated: 2022/12/05 17:19:02 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_putnbr_hexa(unsigned int n)
{
	int	l;

	l = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		l++;
	}
	return (l);
}

int	ft_putnbr_hexa(unsigned int n, char c)
{
	if (n >= 16)
	{
		ft_putnbr_hexa(n / 16, c);
	}
	if (n % 16 < 10)
		ft_putchar_l(n % 16 + '0');
	else if (c == 'x')
		ft_putchar_l(n % 16 - 10 + 'a');
	else
		ft_putchar_l(n % 16 - 10 + 'A');
	return (len_putnbr_hexa(n));
}

int	len_putnbr_void(unsigned long long n)
{
	int	l;

	l = 2;
	while (n != 0)
	{
		n = n / 16;
		l++;
	}
	return (l);
}

void	ft_putnbr_void(unsigned long long n)
{
	if (n >= 16)
	{
		ft_putnbr_void(n / 16);
		ft_putnbr_void(n % 16);
	}
	else if (n < 10)
		ft_putchar_l(n + '0');
	else
		ft_putchar_l(n % 16 - 10 + 'a');
}

int	ft_void_l(unsigned long long n)
{
	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		write(1, "0x", 2);
		ft_putnbr_void(n);
	}
	return (len_putnbr_void(n));
}
