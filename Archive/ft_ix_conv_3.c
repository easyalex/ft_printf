/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ix_conv_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouleng <cbouleng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 17:42:17 by cbouleng          #+#    #+#             */
/*   Updated: 2019/12/30 09:11:47 by cbouleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ix_zero(char *str, va_list args)
{
	int				zero;
	int				value_len;
	unsigned int	value;

	str += 2;
	if ((zero = ix_pre_sp(str, args)) < 0)
		return (ix_print(args, zero));
	value = va_arg(args, unsigned int);
	value_len = ft_nbrlen_hex(value);
	while (zero > value_len)
	{
		ft_putchar('0');
		value_len++;
	}
	ft_itoa_hex(value);
	return (value_len);
}

int		ix_flag(char *str, va_list args)
{
	int space;

	if (ix_precision(str))
		return (ix_p_manage(str, args));
	if (*(str + 1) == '0')
		return (ix_zero(str, args));
	space = ix_pre_sp(str, args);
	return (ix_print(args, space));
}
