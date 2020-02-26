/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouleng <cbouleng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 09:42:00 by cbouleng          #+#    #+#             */
/*   Updated: 2020/01/23 12:17:25 by cbouleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		di_precision(char *str)
{
	int i;

	i = 0;
	while (str[i] != 'd' && str[i] != 'i')
	{
		if (str[i] == '.')
			return (1);
		i++;
	}
	return (0);
}

int		di_pre_sp(char *str, va_list args)
{
	int	b_space;
	int	space;

	b_space = 0;
	space = 0;
	while (*str != '.' && *str != 'd' && *str != 'i')
	{
		if (*str == '-')
			b_space = 1;
		if (*str == '*')
			space = va_arg(args, int);
		if (*str >= '0' && *str <= '9')
			space = space * 10 + *str - 48;
		str++;
	}
	if (space < 0 && b_space == 1)
		return (space);
	if (space > 0 && b_space == 1)
		return (-space);
	return (space);
}

int		di_pre_zr(char *str, va_list args)
{
	int zero;
	int	b_space;

	zero = 0;
	b_space = 0;
	while (*str != '.')
		str++;
	while (*str != 'd' && *str != 'i')
	{
		if (*str == '-')
			b_space = 1;
		if (*str == '*')
			zero = va_arg(args, int);
		if (*str >= '0' && *str <= '9')
			zero = zero * 10 + *str - 48;
		str++;
	}
	if (zero < 0 && b_space == 1)
		return (zero);
	if (zero > 0 && b_space == 1)
		return (-zero);
	return (zero);
}

int		di_s_given_null(int space)
{
	int len;

	len = 0;
	if (space < 0)
		space = -space;
	while (space)
	{
		ft_putchar(' ');
		space--;
		len++;
	}
	return (len);
}

int		di_s_given(va_list args, int space)
{
	int	value_len;
	int	value;
	int	flag;

	flag = 0;
	if ((value = va_arg(args, int)) == 0)
		return (di_s_given_null(space));
	value_len = ft_nbrlen(value);
	if (value == -2147483648)
		value_len = 11;
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
