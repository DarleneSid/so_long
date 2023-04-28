/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:28:39 by dsydelny          #+#    #+#             */
/*   Updated: 2022/12/20 16:44:04 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_whats_next(char s, va_list ap)
{
	int	s_len;

	s_len = 0;
	if (s == 'c')
		s_len += ft_putchar_l((char)va_arg(ap, int));
	else if (s == 's')
		s_len += ft_putstr_l(va_arg(ap, char *));
	else if (s == 'p')
		s_len += ft_void_l(va_arg(ap, unsigned long long));
	else if (s == 'd' || s == 'i')
		s_len += ft_putnbr_l(va_arg(ap, int));
	else if (s == 'u')
		s_len += ft_uns_putnbr(va_arg(ap, unsigned int));
	else if (s == 'x' || s == 'X')
		s_len += ft_putnbr_hexa(va_arg(ap, unsigned int), s);
	else
		s_len += ft_putchar_l(s);
	return (s_len);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(ap, s);
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			len += ft_whats_next(s[i], ap);
		}
		else
			len += ft_putchar_l(s[i]);
		i++;
	}
	va_end(ap);
	return (len);
}
