/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_conv_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouleng <cbouleng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 09:38:38 by cbouleng          #+#    #+#             */
/*   Updated: 2019/12/29 18:03:37 by cbouleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		s_z_given(va_list args, int zero)
{
	char	*value;
	int		value_len;
	int		len;

	len = 0;
	if ((value = va_arg(args, char *)) == NULL)
		value = "(null)";
	value_len = ft_strlen(value);
	while (zero && value_len)
	{
		ft_putchar(*value);
		value_len--;
		value++;
		zero--;
		len++;
	}
	return (len);
}

int		s_space(char *str, va_list args)
{
	int		space;
	int		len;
	char	*value;

	space = s_pre_sp(str, args);
	if ((value = va_arg(args, char *)) == NULL)
		value = "(null)";
	len = ft_strlen(value);
	space -= len;
	while (space > 0)
	{
		ft_putchar(' ');
		space--;
		len++;
	}
	ft_putstr(value);
	return (len);
}

int		s_bspace(char *str, va_list args)
{
	int		space;
	int		value_len;
	int		len;
	char	*value;

	len = 0;
	space = s_pre_sp(str, args);
	if ((value = va_arg(args, char *)) == NULL)
		value = "(null)";
	value_len = ft_strlen(value);
	ft_putstr(value);
	space += value_len;
	while (space < 0)
	{
		ft_putchar(' ');
		space++;
		len++;
	}
	return (len + value_len);
}

int		s_zero(char *str, va_list args)
{
	int		zero;
	int		value_len;
	char	*value;

	zero = s_pre_sp(str, args);
	if ((value = va_arg(args, char*)) == NULL)
		value = "(null)";
	value_len = ft_strlen(value);
	while (zero > value_len)
	{
		ft_putchar('0');
		value_len++;
	}
	ft_putstr(value);
	return (value_len);
}

int		s_p_manage(char *str, va_list args)
{
	int space;
	int zero;
	int len;

	len = 0;
	space = s_pre_sp(str, args);
	zero = s_pre_zr(str, args);
	if (space <= 0 && zero < 0)
		return (s_bs_given(args, space));
	if (space > 0 && zero < 0)
		return (s_s_given(args, space));
	if (space > 0 && zero >= 0)
		return (len = s_sz_given(args, space, zero));
	if (space <= 0 && zero >= 0)
		return (len = s_bsz_given(args, space, zero));
	return (0);
}
