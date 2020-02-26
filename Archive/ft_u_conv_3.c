/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_conv_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouleng <cbouleng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 09:48:08 by cbouleng          #+#    #+#             */
/*   Updated: 2019/12/29 18:06:24 by cbouleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		u_zero(char *str, va_list args)
{
	int				zero;
	int				value_len;
	unsigned int	value;

	str += 2;
	if ((zero = u_pre_sp(str, args)) < 0)
		return (u_print(args, zero));
	value = va_arg(args, unsigned int);
	value_len = ft_nbrlen_u(value);
	while (zero > value_len)
	{
		ft_putchar('0');
		value_len++;
	}
	ft_putnbr_u(value);
	return (value_len);
}

int		u_flag(char *str, va_list args)
{
	int space;

	if (u_precision(str))
		return (u_p_manage(str, args));
	if (*(str + 1) == '0')
		return (u_zero(str, args));
	space = u_pre_sp(str, args);
	return (u_print(args, space));
}
