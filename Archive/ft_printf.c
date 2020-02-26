/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouleng <cbouleng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 09:59:05 by cbouleng          #+#    #+#             */
/*   Updated: 2020/02/04 09:38:51 by cbouleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	fmt_read(char *str)
{
	char	*fmt;
	int		i;
	int		j;

	j = 0;
	fmt = "cspdiuxX%";
	str++;
	while (str[j])
	{
		i = 0;
		while (fmt[i])
		{
			if (str[j] == fmt[i])
				return (fmt[i]);
			i++;
		}
		j++;
	}
	return (0);
}

int		flaglen(char *str)
{
	int		i;
	char	fmt;

	i = 2;
	fmt = fmt_read(str);
	str++;
	while (*str != fmt)
	{
		str++;
		i++;
	}
	return (i);
}

int		dealer(char fmt, char *str, va_list args)
{
	int len;

	len = 0;
	if (fmt == 'c')
		len = c_flag(str, args);
	if (fmt == 's')
		len = s_flag(str, args);
	if (fmt == 'p')
		len = p_flag(str, args);
	if (fmt == 'd' || fmt == 'i')
		len = di_flag(str, args);
	if (fmt == 'u')
		len = u_flag(str, args);
	if (fmt == 'x')
		len = x_flag(str, args);
	if (fmt == 'X')
		len = ix_flag(str, args);
	if (fmt == '%')
		len = po_flag(str, args);
	return (len);
}

int		ft_printf(const char *c_str, ...)
{
	va_list	args;
	int		len;
	char	*str;

	str = (char *)c_str;
	va_start(args, c_str);
	len = 0;
	while (*str)
	{
		while (*str == '%')
		{
			len += dealer(fmt_read(str), str, args);
			str += flaglen(str);
		}
		if (*str)
		{
			ft_putchar(*str);
			len++;
			str++;
		}
	}
	va_end(args);
	return (len);
}
