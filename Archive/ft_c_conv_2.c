/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_conv_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouleng <cbouleng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 09:21:57 by cbouleng          #+#    #+#             */
/*   Updated: 2019/12/29 17:30:55 by cbouleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		c_s_given(va_list args, int space)
{
	int len;

	len = 1;
	while (space - 1 > 0)
	{
		ft_putchar(' ');
		space--;
		len++;
	}
	ft_putchar(va_arg(args, int));
	return (len);
}

int		c_star(va_list args)
{
	int value;

	value = va_arg(args, int);
	if (value < 0)
		return (c_bs_given(args, value));
	if (value >= 0)
		return (c_s_given(args, value));
	return (0);
}

int		c_p_manage(char *str, va_list args)
{
	int space;
	int len;

	len = 0;
	space = c_pre_sp(str, args);
	if (space < 0)
		return (len = c_bs_given(args, space));
	if (space > 0)
		return (len = c_s_given(args, space));
	if (space == 0)
	{
		ft_putchar(va_arg(args, int));
		return (1);
	}
	return (0);
}

int		c_simple(va_list args)
{
	char value;

	value = va_arg(args, int);
	ft_putchar(value);
	return (1);
}

int		c_flag(char *str, va_list args)
{
	int	len;

	len = 0;
	if (c_precision(str))
		return (len = c_p_manage(str, args));
	if (*(str + 1) >= '0' && *(str + 1) <= '9')
		return (len = c_space(str, args));
	if (*(str + 1) == '-')
		return (len = c_bspace(str, args));
	if (*(str + 1) == '*')
		return (len = c_star(args));
	if (*(str + 1) == 'c')
		return (len = c_simple(args));
	return (0);
}
