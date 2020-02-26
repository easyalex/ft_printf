/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prct_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouleng <cbouleng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 17:20:28 by cbouleng          #+#    #+#             */
/*   Updated: 2019/12/29 17:48:36 by cbouleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		po_precision(char *str)
{
	int i;

	i = 1;
	while (str[i] != '%')
	{
		if (str[i] == '.')
			return (1);
		i++;
	}
	return (0);
}

int		read_flag(char *str, va_list args)
{
	int	b_space;
	int	space;

	b_space = 0;
	space = 0;
	str++;
	while (*str != '%' && *str != '.')
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

int		po_print(int space)
{
	int len;

	len = 0;
	if (space < 0)
	{
		ft_putchar('%');
		while (space + 1 < 0)
		{
			ft_putchar(' ');
			space++;
			len++;
		}
	}
	else
	{
		while (space - 1 > 0)
		{
			ft_putchar(' ');
			space--;
			len++;
		}
		ft_putchar('%');
	}
	return (len + 1);
}

int		po_zero(va_list args, char *str)
{
	int zero;
	int len;

	len = 0;
	if ((zero = read_flag(str, args)) < 0)
		return (po_print(zero));
	while (zero - 1 > 0)
	{
		ft_putchar('0');
		zero--;
		len++;
	}
	ft_putchar('%');
	return (len + 1);
}

int		po_flag(char *str, va_list args)
{
	int space;

	if (*(str + 1) == '%')
	{
		ft_putstr("%");
		return (1);
	}
	if (*(str + 1) == '0')
		return (po_zero(args, str));
	space = read_flag(str, args);
	return (po_print(space));
}
