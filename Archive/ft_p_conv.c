/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouleng <cbouleng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 09:05:45 by cbouleng          #+#    #+#             */
/*   Updated: 2020/01/03 13:23:28 by cbouleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		p_precision(char *str)
{
	int i;

	i = 0;
	while (str[i] != 'p')
	{
		if (str[i] == '.')
			return (1);
		i++;
	}
	return (0);
}

int		p_pre_sp(char *str, va_list args)
{
	int	b_space;
	int	space;

	b_space = 0;
	space = 0;
	while (*str != '.' && *str != 'p')
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

int		p_space(char *str, va_list args)
{
	int		space;
	int		value_len;
	size_t	value;

	space = p_pre_sp(str, args);
	value = va_arg(args, size_t);
	value_len = ft_plen(value);
	while (space > value_len)
	{
		ft_putchar(' ');
		value_len++;
	}
	ft_putstr("0x");
	ft_print_p(value);
	return (value_len);
}

int		p_bspace(char *str, va_list args)
{
	int		space;
	int		value_len;
	int		len;
	size_t	value;

	len = 0;
	space = p_pre_sp(str, args);
	value = va_arg(args, size_t);
	value_len = ft_plen(value);
	ft_putstr("0x");
	ft_print_p(value);
	space += value_len;
	while (space < 0)
	{
		ft_putchar(' ');
		space++;
		len++;
	}
	return (len + value_len);
}

int		p_bs_given(va_list args, int space, int lever)
{
	int		len;
	int		value_len;
	size_t	value;

	len = 0;
	value = va_arg(args, size_t);
	value_len = ft_plen(value);
	if (lever && value == (size_t)NULL)
		value_len--;
	space += value_len;
	ft_putstr("0x");
	if (!lever && value != (size_t)NULL)
		ft_print_p(value);
	if (!lever && value == (size_t)NULL)
		ft_putchar('0');
	while (space < 0)
	{
		ft_putchar(' ');
		space++;
		len++;
	}
	return (len + value_len);
}
