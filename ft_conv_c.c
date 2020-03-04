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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_conv_c(va_list l_args, int *tab)
{
	int 	space; 

	space = 0;
	if (tab[2] > 0 || tab[3] == 1)
		if (tab[2] > 0)
			space = tab[2];
		if ((tab[2] == 0) && (tab[3] == 1))
			space = va_arg(l_args, int);
	if (tab[0] == 1)
	{
		ft_putchar(va_arg(l_args, int));
		while (space-- >= 2) //  1 car il faut soustraire le char des espaces
			write(1, " ", 1);
	}
	else
	{
		while (space-- >= 2) //  1 car il faut soustraire le char des espaces
			write(1, " ", 1);
		ft_putchar(va_arg(l_args, int));
	}
	return (0);
}


		// if (*ptr_format2 == '-')
		// 	tab[0] = 1;
		// else if (*ptr_format2 == '0')
		// 	tab[1] = 1;
		// else if (*ptr_format2 > '0' && *ptr_format2 <= '9' && tab[4] == 0)
		// 	tab[2] = (ft_atoi(&ptr_format2));
		// else if (*ptr_format2 == '*')
		// 	tab[3] = 1;
		// else if (*ptr_format2 == '.')
		// 	tab[4] = 1;
		// else if (*ptr_format2 > '0' && *ptr_format2 <= '9' && tab[4] == 1)
		// 	tab[5] = (ft_atoi(&ptr_format2));