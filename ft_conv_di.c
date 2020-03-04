/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:51:58 by abonniss          #+#    #+#             */
/*   Updated: 2020/02/11 18:52:06 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int ft_len_number(number)
{
	int 	len_nbr;

	len_nbr = 0;
	if (number < 0)
	{
		len_nbr++;
		number *= -1;
	}
	while (number > 10)
	{
		number = number / 10;
		len_nbr++;
	}
	if (number >= 0 && number <= 9)
		len_nbr++;
	return (len_nbr);
}

char *ft_itoa_printf(int number, int len)
{
	char 	*writen_nbr;
	int 	sign;
	
	writen_nbr = malloc(sizeof(char)*len); // writen_nbr[len] fait beuger l'ordi
	writen_nbr[len--] = '\0';
	sign = 1;
	if (number < 0)
	{
		sign *= -1;
		number *= -1;
	}
	while (number > 10 && len >= 0)
	{
		writen_nbr[len] = (number % 10) + '0';
		number = number / 10;
		len--;
	}
	if (number >= 0 && number <= 9)
	{
		writen_nbr[len] = number + '0';
		len--;
	}
	if (sign == -1)
		writen_nbr[len] = '-';

	return (writen_nbr);
}

int 	ft_conv_di_precision_manage(va_list l_args, int *tab, int precision)
{
	if (tab[4] == 1)
	{
		if (tab[5] > 0 || tab[6] == 1)
			if (tab[5] > 0)
				precision = tab[5];
			if (tab[6] == 1)
				precision = va_arg(l_args, int);
	}
	return (precision);
}

void 	ft_conv_di_to_print(char *str, int *tab, int space, int len, int number)
{
	if (space > len && tab[4] == 0)
	{
		if (tab[0] == 1)
		{
			ft_putstr_printf(str, len);
			space -= len;
			while (space--)
				write(1, " ", 1);
		}
		else if (tab[0] == 0)
		{
			space -= len;
			while (space--)
					write(1, " ", 1);
			ft_putstr_printf(str, len);
			return ;
		}
	}
	// if (space > len)
	// {	
	// 	if (tab[0] == 1)
	// 	{
	// 		ft_putstr_printf(str, len);
	// 		space -= len;
	// 		while (space--)
	// 			write(1, " ", 1);
	// 	}
	// 	else
	// 	{
	// 		space -= len;
	// 		while (space--)
	// 			write(1, " ", 1);
	// 		ft_putstr_printf(str, len);
	// 	}
	// }
}

int		ft_conv_di(va_list l_args, int *tab)
{
	int 	space;
	char 	*str_number;
	int 	len_nbr;
	int 	precision;
	int 	number;

	space 		= ft_conv_s_space_manage(l_args, tab, space);
	precision 	= ft_conv_di_precision_manage(l_args, tab, space);
	number 		= va_arg(l_args, int);
	len_nbr 	= ft_len_number(number);
	str_number 	= ft_itoa_printf(number, len_nbr);

	// precision -= len_nbr;
	// if (number < 0)
	// 	precision++;
	
	// printf("\nSpace 		= [%d]\n", space);
	// printf("Precision 	= [%d]\n", precision);
	// printf("Number 		= [%d]\n", number);
	// printf("Len_Number 	= [%d]\n", len_nbr);
	// printf("Str_number 	= [%s]\n", str_number);

	ft_conv_di_to_print(str_number, tab, space, len_nbr, number);

	return (0);
}




































