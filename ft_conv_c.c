/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:51:58 by abonniss          #+#    #+#             */
/*   Updated: 2020/02/11 18:52:06 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int ft_conv_c(char *ptr_format2, va_list l_args, int *tab)
{

	if (tab[0] == 1 || tab[0] == 0 || tab[2] > 0 || tab[0] == 1)
		ft_space

	char to_print;

	to_print = va_arg(l_args, int);

	write(1, &to_print, 1);

	return (1);
}


		if (*ptr_format2 == '-')
			tab[0] = 1;
		else if (*ptr_format2 == '0')
			tab[1] = 1;
		else if (*ptr_format2 > '0' && *ptr_format2 <= '9' && tab[4] == 0)
			tab[2] = (ft_atoi(&ptr_format2));
		else if (*ptr_format2 == '*')
			tab[3] = 1;
		else if (*ptr_format2 == '.')
			tab[4] = 1;
		else if (*ptr_format2 > '0' && *ptr_format2 <= '9' && tab[4] == 1)
			tab[5] = (ft_atoi(&ptr_format2));