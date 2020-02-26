/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_conv_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouleng <cbouleng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 09:43:33 by cbouleng          #+#    #+#             */
/*   Updated: 2020/01/18 16:23:39 by cbouleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		di_null(va_list args, int zero)
{
	int value;
	int value_len;

	(void)zero;
	value = va_arg(args, int);
	value_len = ft_nbrlen(value);
	ft_putnbr(value);
	return (value_len);
}

int		di_p_zero(va_list args, int zero)
{
	int value;
	int value_len;

	if ((value = va_arg(args, int)) < 0)
		return (di_zero_neg(value, zero));
	value_len = ft_nbrlen(value);
	while (zero > value_len)
	{
		ft_putchar('0');
		value_len++;
	}
	ft_putnbr(value);
	return (value_len);
}

int		di_p_manage(char *str, va_list args)
{
	int space;
	int zero;

	space = di_pre_sp(str, args);
	zero = di_pre_zr(str, args);
	if (space && zero == 0)
		return (di_s_given(args, space));
	if (space == 0 && zero < 0)
		return (di_null(args, zero));
	if (space < 0 && zero < 0)
		return (di_bsz_given(args, space, 0));
	if (space > 0 && zero > 0)
		return (di_sz_given(args, space, zero));
	if (*(str + 1) == '0' && space > 0 && zero < 0)
		return (di_p_zero(args, space));
	if (space > 0 && zero < 0)
		return (di_print(args, space));
	if (space <= 0 && zero > 0)
		return (di_bsz_given(args, space, zero));
	if (space == 0 && zero == 0)
		return (di_s_given(args, 0));
	return (0);
}

int		di_zero_neg(int value, int zero)
{
	int value_len;

	value_len = ft_nbrlen(value);
	if (value == -2147483648)
		value_len = 11;
	ft_putchar('-');
	while (zero > value_len)
	{
		ft_putchar('0');
		value_len++;
	}
	ft_putnbr_zero(value);
	return (value_len);
}

int		di_zero(char *str, va_list args)
{
	int zero;
	int value;
	int value_len;

	str += 2;
	if ((zero = di_pre_sp(str, args)) < 0)
		return (di_print(args, zero));
	if ((value = va_arg(args, int)) < 0)
		return (di_zero_neg(value, zero));
	value_len = ft_nbrlen(value);
	while (zero > value_len)
	{
		ft_putchar('0');
		value_len++;
	}
	ft_putnbr(value);
	return (value_len);
}
