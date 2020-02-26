/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouleng <cbouleng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 09:34:53 by cbouleng          #+#    #+#             */
/*   Updated: 2020/01/21 09:44:44 by cbouleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	s_pre_sp(char *str, va_list args)
{
	int	b_space;
	int	space;

	b_space = 0;
	space = 0;
	while (*str != '.' && *str != 's')
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

int	s_precision(char *str)
{
	int i;

	i = 0;
	while (str[i] != 's')
	{
		if (str[i] == '.')
			return (1);
		i++;
	}
	return (0);
}

int	s_pre_zr(char *str, va_list args)
{
	int zero;
	int	b_space;

	zero = 0;
	b_space = 0;
	while (*str != '.')
		str++;
	while (*str != 's')
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

int	s_bs_given(va_list args, int space)
{
	int		value_len;
	char	*value;

	if ((value = va_arg(args, char *)) == NULL)
		value = "(null)";
	value_len = ft_strlen(value);
	ft_putstr(value);
	space = -space;
	while (space > value_len)
	{
		ft_putchar(' ');
		value_len++;
	}
	return (value_len);
}

int	s_s_given(va_list args, int space)
{
	int		value_len;
	char	*value;

	if ((value = va_arg(args, char *)) == NULL)
		value = "(null)";
	value_len = ft_strlen(value);
	while (space > value_len)
	{
		ft_putchar(' ');
		value_len++;
	}
	ft_putstr(value);
	return (value_len);
}
