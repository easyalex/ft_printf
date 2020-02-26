/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouleng <cbouleng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 09:47:03 by cbouleng          #+#    #+#             */
/*   Updated: 2019/12/29 18:05:45 by cbouleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		u_precision(char *str)
{
	int i;

	i = 0;
	while (str[i] != 'u')
	{
		if (str[i] == '.')
			return (1);
		i++;
	}
	return (0);
}

int		u_pre_sp(char *str, va_list args)
{
	int	b_space;
	int	space;

	b_space = 0;
	space = 0;
	while (*str != '.' && *str != 'u')
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

int		u_pre_zr(char *str, va_list args)
{
	int zero;
	int	b_space;

	zero = 0;
	b_space = 0;
	while (*str != '.')
		str++;
	while (*str != 'u')
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

int		u_s_given_null(int space, int zero)
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

int		u_s_given(va_list args, int space, int zero)
{
	int				value_len;
	int				flag;
	unsigned int	value;

	flag = 0;
	if ((value = va_arg(args, unsigned int)) == 0)
		return (u_s_given_null(space, zero));
	value_len = ft_nbrlen_u(value);
	if (space < 0)
	{
		ft_putnbr_u(value);
		space = -space;
		flag = 1;
	}
	while (space > value_len)
	{
		ft_putchar(' ');
		value_len++;
	}
	if (!flag)
		ft_putnbr_u(value);
	return (value_len);
}
