/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_conv_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouleng <cbouleng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 17:36:21 by cbouleng          #+#    #+#             */
/*   Updated: 2020/01/18 16:18:02 by cbouleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		di_flag(char *str, va_list args)
{
	int space;

	if (di_precision(str))
		return (di_p_manage(str, args));
	if (*(str + 1) == '0')
		return (di_zero(str, args));
	space = di_pre_sp(str, args);
	return (di_print(args, space));
}
