/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:24:13 by dsydelny          #+#    #+#             */
/*   Updated: 2022/12/05 17:25:03 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_putchar_l(char a);
int		ft_putstr_l(char *s);
int		len_putnbr(long int n);
int		len_uns_putnbr(unsigned int n);
int		len_putnbr_hexa(unsigned int n);
int		ft_putnbr_l(int n);
int		ft_putnbr_hexa(unsigned int n, char c);
void	ft_putnbr_void(unsigned long long n);
int		len_putnbr_void(unsigned long long n);
int		ft_void_l(unsigned long long n);
int		ft_uns_putnbr(unsigned int n);
int		ft_whats_next(char s, va_list ap);
int		ft_printf(const char *s, ...);

#endif
