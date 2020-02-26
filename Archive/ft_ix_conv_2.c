/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ix_conv_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouleng <cbouleng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 09:54:23 by cbouleng          #+#    #+#             */
/*   Updated: 2019/12/29 17:54:50 by cbouleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ix_sz_given2(int zero, int len, unsigned int value)
{
	int value_len;

	value_len = ft_nbrlen_hex(value);
	while (zero > value_len)
	{
		ft_putchar('0');
		value_len++;
		len++;
	}
	ft_itoa_hex(value);
	value_len = ft_nbrlen_hex(value);
	return (len + value_len);
}

int		ix_sz_given(va_list args, int space, int zero)
{
	int				len;
	int				value_len;
	unsigned int	value;

	len = 0;
	value = va_arg(args, unsigned int);
	value_len = ft_nbrlen_hex(value);
	while (space > zero && space > value_len)
	{
		ft_putchar(' ');
		space--;
		len++;
	}
	return (ix_sz_given2(zero, len, value));
}

int		ix_bsz_given(va_list args, int space, int zero)
{
	int				value_len;
	unsigned int	value;

	value = va_arg(args, unsigned int);
	value_len = ft_nbrlen_hex(value);
	while (zero > value_len)
	{
		ft_putchar('0');
		value_len++;
	}
	ft_itoa_hex(value);
	space = -space;
	while (space > zero && space > value_len)
	{
		ft_putchar(' ');
		value_len++;
	}
	return (value_len);
}

int		ix_p_manage(char *str, va_list args)
{
	int space;
	int zero;

	space = ix_pre_sp(str, args);
	zero = ix_pre_zr(str, args);
	if (*(str + 1) == '0' && space > 0 && zero < 0)
		return (ix_sz_given(args, 0, space));
	if (zero <= 0)
		return (ix_s_given(args, space, zero));
	if (space > 0 && zero > 0)
		return (ix_sz_given(args, space, zero));
	if (space <= 0 && zero > 0)
		return (ix_bsz_given(args, space, zero));
	return (0);
}

int		ix_print(va_list args, int space)
{
	int				value_len;
	int				flag;
	unsigned int	value;

	flag = 0;
	value = va_arg(args, unsigned int);
	value_len = ft_nbrlen_hex(value);
	if (space < 0)
	{
		ft_itoa_hex(value);
		space = -space;
		flag = 1;
	}
	while (space > value_len)
	{
		ft_putchar(' ');
		value_len++;
	}
	if (!flag)
		ft_itoa_hex(value);
	return (value_len);
}
