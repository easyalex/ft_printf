/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_conv_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouleng <cbouleng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 18:02:57 by cbouleng          #+#    #+#             */
/*   Updated: 2019/12/29 18:02:59 by cbouleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		s_flag(char *str, va_list args)
{
	int len;

	len = 0;
	if (s_precision(str))
		return (len = s_p_manage(str, args));
	if (*(str + 1) == '0')
		return (len = s_zero(str, args));
	if (*(str + 1) >= '0' && *(str + 1) <= '9')
		return (len = s_space(str, args));
	if (*(str + 1) == '-')
		return (len = s_bspace(str, args));
	if (*(str + 1) == '*')
		return (len = s_star(args));
	if (*(str + 1) == 's')
		return (len = s_print(args));
	return (0);
}
