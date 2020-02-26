/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouleng <cbouleng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 09:19:35 by cbouleng          #+#    #+#             */
/*   Updated: 2020/01/21 09:44:57 by cbouleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	c_precision(char *str)
{
	int i;

	i = 0;
	while (str[i] != 'c')
	{
		if (str[i] == '.')
			return (i);
		i++;
	}
	return (0);
}

int	c_pre_sp(char *str, va_list args)
{
	int	b_space;
	int	space;

	b_space = 0;
	space = 0;
	while (*str != '.' && *str != 'c')
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

int	c_bspace(char *str, va_list args)
{
	int		space;
	int		len;
	char	value;

	len = 1;
	space = c_pre_sp(str, args);
	value = va_arg(args, int);
	ft_putchar(value);
	space = -space;
	while (space > len)
	{
		ft_putchar(' ');
		len++;
	}
	return (len);
}

int	c_space(char *str, va_list args)
{
	int		space;
	int		len;
	char	value;

	len = 1;
	space = c_pre_sp(str, args);
	value = va_arg(args, int);
	while (space > len)
	{
		ft_putchar(' ');
		len++;
	}
	ft_putchar(value);
	return (len);
}

int	c_bs_given(va_list args, int space)
{
	int len;

	len = 1;
	ft_putchar(va_arg(args, int));
	space++;
	while (space < 0)
	{
		ft_putchar(' ');
		space++;
		len++;
	}
	return (len);
}
