/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_conv_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouleng <cbouleng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 09:36:37 by cbouleng          #+#    #+#             */
/*   Updated: 2019/12/30 13:47:26 by cbouleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	s_star(va_list args)
{
	int value;
	int len;

	value = va_arg(args, int);
	if (value < 0)
		return (len = s_bs_given(args, value));
	if (value >= 0)
		return (len = s_s_given(args, value));
	return (0);
}

int	s_print(va_list args)
{
	char	*value;
	int		value_len;

	value = va_arg(args, char *);
	if (value == NULL)
		value = "(null)";
	value_len = ft_strlen(value);
	ft_putstr(value);
	return (value_len);
}

int	s_sz_given(va_list args, int space, int zero)
{
	char	*value;
	int		len;
	int		value_len;

	len = 0;
	if ((value = va_arg(args, char *)) == NULL)
		value = "(null)";
	if ((value_len = ft_strlen(value)) > zero)
		value_len = zero;
	while (space - value_len > 0)
	{
		ft_putchar(' ');
		space--;
		len++;
	}
	while (value_len > 0)
	{
		ft_putchar(*value);
		value++;
		value_len--;
		len++;
	}
	return (len);
}

int	s_bsz_given(va_list args, int space, int zero)
{
	char	*value;
	int		len;
	int		value_len;

	len = 0;
	if ((value = va_arg(args, char *)) == NULL)
		value = "(null)";
	if ((value_len = ft_strlen(value)) > zero)
		value_len = zero;
	space = -space - value_len;
	while (value_len > 0)
	{
		ft_putchar(*value);
		value_len--;
		value++;
		len++;
	}
	while (space > 0)
	{
		ft_putchar(' ');
		space--;
		len++;
	}
	return (len);
}
