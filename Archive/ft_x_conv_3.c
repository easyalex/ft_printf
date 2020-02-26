/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_conv_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouleng <cbouleng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 09:52:28 by cbouleng          #+#    #+#             */
/*   Updated: 2019/12/29 18:07:34 by cbouleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		x_zero(char *str, va_list args)
{
	int				zero;
	int				value_len;
	unsigned int	value;

	str += 2;
	if ((zero = x_pre_sp(str, args)) < 0)
		return (x_print(args, zero));
	value = va_arg(args, unsigned int);
	value_len = ft_nbrlen_hex(value);
	while (zero > value_len)
	{
		ft_putchar('0');
		value_len++;
	}
	ft_itoa_x(value);
	return (value_len);
}

int		x_flag(char *str, va_list args)
{
	int space;

	if (x_precision(str))
		return (x_p_manage(str, args));
	if (*(str + 1) == '0')
		return (x_zero(str, args));
	space = x_pre_sp(str, args);
	return (x_print(args, space));
}
