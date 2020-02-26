/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_conv_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouleng <cbouleng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 09:25:49 by cbouleng          #+#    #+#             */
/*   Updated: 2020/01/03 13:41:54 by cbouleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		p_s_given(va_list args, int space, int lever)
{
	int		value_len;
	size_t	value;

	value = va_arg(args, size_t);
	value_len = ft_plen(value);
	if (lever && value == (size_t)NULL)
		value_len--;
	while (space > value_len)
	{
		ft_putchar(' ');
		value_len++;
	}
	ft_putstr("0x");
	if (!lever && value != (size_t)NULL)
		ft_print_p(value);
	if (!lever && value == (size_t)NULL)
		ft_putchar('0');
	return (value_len);
}

int		p_star(va_list args)
{
	int value;

	value = va_arg(args, int);
	if (value < 0)
		return (p_bs_given(args, value, 0));
	if (value >= 0)
		return (p_s_given(args, value, 0));
	return (0);
}

int		p_print(va_list args)
{
	size_t	value;

	if (!(value = va_arg(args, size_t)))
	{
		ft_putstr("0x0");
		return (3);
	}
	ft_putstr("0x");
	ft_print_p(value);
	return (ft_plen(value));
}

int		p_p_manage(char *str, va_list args)
{
	int space;

	space = p_pre_sp(str, args);
	if (space < 0)
		return (p_bs_given(args, space, 1));
	if (space >= 0)
		return (p_s_given(args, space, 1));
	return (0);
}

int		p_flag(char *str, va_list args)
{
	if (p_precision(str))
		return (p_p_manage(str, args));
	if (*(str + 1) >= '0' && *(str + 1) <= '9')
		return (p_space(str, args));
	if (*(str + 1) == '-')
		return (p_bspace(str, args));
	if (*(str + 1) == '*')
		return (p_star(args));
	if (*(str + 1) == 'p')
		return (p_print(args));
	return (0);
}
