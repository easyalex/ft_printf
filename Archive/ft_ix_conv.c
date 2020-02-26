/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ix_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouleng <cbouleng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 09:54:13 by cbouleng          #+#    #+#             */
/*   Updated: 2019/12/30 09:09:21 by cbouleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ix_precision(char *str)
{
	int i;

	i = 0;
	while (str[i] != 'X')
	{
		if (str[i] == '.')
			return (1);
		i++;
	}
	return (0);
}

int		ix_pre_sp(char *str, va_list args)
{
	int	b_space;
	int	space;

	b_space = 0;
	space = 0;
	while (*str != '.' && *str != 'X')
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

int		ix_pre_zr(char *str, va_list args)
{
	int zero;
	int	b_space;

	b_space = 0;
	zero = 0;
	while (*str != '.')
		str++;
	while (*str != 'X')
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

int		ix_s_given_null(int space, int zero)
{
	int len;
	int flag;

	flag = 0;
	len = zero ? 1 : 0;
	if (zero && space < 0)
	{
		ft_putchar('0');
		flag = 1;
	}
	space = (space < 0) ? -space : space;
	space = zero ? space - 1 : space;
	while (space > 0)
	{
		ft_putchar(' ');
		space--;
		len++;
	}
	if (zero && !flag)
		ft_putchar('0');
	return (len);
}

int		ix_s_given(va_list args, int space, int zero)
{
	int				value_len;
	int				flag;
	unsigned int	value;

	flag = 0;
	if ((value = va_arg(args, unsigned int)) == 0)
		return (ix_s_given_null(space, zero));
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
