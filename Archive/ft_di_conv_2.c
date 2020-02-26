/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_conv_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouleng <cbouleng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 09:42:12 by cbouleng          #+#    #+#             */
/*   Updated: 2020/01/18 16:23:37 by cbouleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		di_sz_given2(int zero, int len, int value)
{
	int value_len;

	if (value < 0)
	{
		ft_putchar('-');
		value = -value;
		len++;
	}
	if (value == -2147483648)
		value_len = 10;
	else
		value_len = ft_nbrlen(value);
	while (zero > value_len)
	{
		ft_putchar('0');
		value_len++;
	}
	if (value == -2147483648)
		ft_putstr("2147483648");
	else
		ft_putnbr(value);
	return (len + value_len);
}

int		di_sz_given(va_list args, int space, int zero)
{
	int	len;
	int	value_len;
	int	value;

	len = 0;
	if ((value = va_arg(args, int)) == -2147483648)
		value_len = 11;
	else
		value_len = ft_nbrlen(value);
	if (zero >= value_len && value < 0)
		space--;
	while (space > zero && space > value_len)
	{
		ft_putchar(' ');
		space--;
		len++;
	}
	return (di_sz_given2(zero, len, value));
}

int		di_bsz_given_neg(int value, int space, int zero)
{
	int value_len;

	if (value == -2147483648)
		value_len = 11;
	else
		value_len = ft_nbrlen(value);
	ft_putchar('-');
	while (zero > value_len - 1)
	{
		ft_putchar('0');
		value_len++;
	}
	if (value == -2147483648)
		ft_putstr("2147483648");
	else
		ft_putnbr(-value);
	space = -space;
	while (space > value_len)
	{
		ft_putchar(' ');
		value_len++;
	}
	return (value_len);
}

int		di_bsz_given(va_list args, int space, int zero)
{
	int		value_len;
	int		value;

	if ((value = va_arg(args, int)) < 0)
		return (di_bsz_given_neg(value, space, zero));
	value_len = ft_nbrlen(value);
	while (zero > value_len)
	{
		ft_putchar('0');
		value_len++;
	}
	ft_putnbr(value);
	space = -space;
	while (space > zero && space > value_len)
	{
		ft_putchar(' ');
		value_len++;
	}
	return (value_len);
}

int		di_print(va_list args, int space)
{
	int	value_len;
	int	value;
	int	flag;

	flag = 0;
	value_len = 0;
	if ((value = va_arg(args, int)) == -2147483648)
		value_len = 11;
	else
		value_len = ft_nbrlen(value);
	if (space < 0)
	{
		ft_putnbr(value);
		space = -space;
		flag = 1;
	}
	while (space > value_len)
	{
		ft_putchar(' ');
		value_len++;
	}
	if (!flag)
		ft_putnbr(value);
	return (value_len);
}
