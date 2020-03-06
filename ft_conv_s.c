/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:51:58 by abonniss          #+#    #+#             */
/*   Updated: 2020/02/11 18:52:06 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_conv_s_space_manage(va_list l_args, int *tab)
{
	int space;

	space = 0;
	if (tab[2] > 0 || tab[3] == 1)
	{
		if (tab[2] > 0)
			space = tab[2];
		if (tab[3] == 1)
			space = va_arg(l_args, int);
	}
	return (space);
}

int 	ft_conv_s_precision_manage(va_list l_args, int *tab, int precision)
{
	if (tab[4] == 1)
	{
		if (tab[5] > 0 || tab[6] == 1)
			if (tab[5] > 0)
				precision = tab[5];
			if (tab[6] == 1)
				precision = va_arg(l_args, int);
		if (tab[5] == 0 && tab[6] == 0)
			precision = -1;
	}
	return (precision);
}

void 	ft_conv_s_to_print(int *tab, int space, int len, char *str)
{
	if (space < len)
	{
		ft_putstr_printf(str, len);
		return ;
	}

	if (space > len)
	{	
		if (tab[0] == 1)
		{
			ft_putstr_printf(str, len);
			space -= len;
			while (space--)
				write(1, " ", 1);
		}
		else
		{
			space -= len;
			while (space--)
				write(1, " ", 1);
			ft_putstr_printf(str, len);
		}
	}
}

int		ft_conv_s(va_list l_args, int *tab)
{
	int 	space;
	char 	*str;
	int 	len;
	int 	precision;

	space = ft_conv_s_space_manage(l_args, tab);
	precision = ft_conv_s_precision_manage(l_args, tab, space);

	str = va_arg(l_args, char*); // recherche de la string pour la mettre dans *str
	len = ft_strlen_printf(str); // calcul de la taille de *str

	if (precision > 0 && precision < len)
		len = precision;
	if (precision == -1)
		len = 0;

	ft_conv_s_to_print(tab, space, len, str);

	return (0);
}