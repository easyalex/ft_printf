/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:51:58 by abonniss          #+#    #+#             */
/*   Updated: 2020/02/11 18:52:06 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int ft_len_un_number(unsigned int number)
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

char *ft_utoa_printf(unsigned int number, int len)
{
	char 	*writen_nbr;
	int 	sign;
	
	writen_nbr = malloc(sizeof(char)*len); // writen_nbr[len] fait beuger l'ordi
	writen_nbr[len--] = '\0';
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
	return (writen_nbr);
}

void ft_regular_u(int space, int len, int *tab, char *str)
{
	if (tab[0] == 1)
	{
		ft_putstr_printf(str, len);
		space -= len;
		while (space--)
			write(1, " ", 1);
		return ;
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

void ft_precision1_u(int len, int *tab, char *str, unsigned int number, int precision)
{
	write(1, "-", 1);
	precision -= len;
	while (precision > 0)
	{
		write(1, "0", 1);
		precision--;
	}
	ft_putstr_printf((str + 1), len);
	return ; 
}

void 	ft_precision2_pos_u(int len, int *tab, char *str, unsigned int number, int precision, int space)
{
	int len_final;

	len_final = 0;
	if (precision > len)
		len_final = precision;
	if (precision < len)
		len_final = len;

	if (tab[0] == 0)
	{
		space -= len_final;
		while (space--)
			write(1, " ", 1);
		precision -= len;
		while (precision > 0)
		{
			write(1, "0", 1);
			precision--;
		}
		ft_putstr_printf(str, len);
		return ;
	}
	if (tab[0] == 1)
	{
		precision -= len;
		while (precision > 0)
		{
			write(1, "0", 1);
			precision--;
		}
		ft_putstr_printf(str, len);
		space -= len_final;
		while (space--)
			write(1, " ", 1);
		return ;
	}
}

void 	ft_conv_u_to_print(char *str, int *tab, int space, int len, int precision, unsigned int number)
{
	int len_final;

	if (space > len && tab[4] == 0)
	{
		ft_regular_u(space, len, tab, str);
		return ; 
	}
	else if (space < len && tab[4] == 0)
	{
		ft_putstr_printf(str, len);
		return ; 
	}
	
	len_final = 0;
	if (precision > len)
		len_final = precision;
	else if (precision < len)
		len_final = len;

	if ((space <= len_final && len_final >= 0) && (tab[4] == 1 || tab[1] == 1 || tab[0] == 1))
	{
		
		ft_precision1_u(len,  tab, str, number, precision);
		return ;
	}
	else if (space > len_final && (tab[4] == 1 || tab[1] == 1 || tab[0] == 1))
	{
		
		ft_precision2_pos_u(len,  tab, str, number, precision, space);
		return ;
	}
}
int		ft_conv_u_space_manage(va_list l_args, int *tab)
{
	int space;

	space = 0;
	if ((tab[2] > 0 || tab[3] == 1) && (tab[1] == 0 && tab[4] == 0))
	{
		if (tab[2] > 0)
			space = tab[2];
		if (tab[3] == 1)
			space = va_arg(l_args, int);
		return (space);
	}
	if ((tab[2] > 0 || tab[3] == 1) && (tab[1] == 1 || tab[1] == 0) && tab[4] == 1 )
	{
		if (tab[2] > 0)
			space = tab[2];
		if (tab[3] == 1)
			space = va_arg(l_args, int);
		return (space);
	}
	return (space);
}

int 	ft_conv_u_precision_manage(va_list l_args, int *tab)
{
	int precision; 

	precision = 0; 
	
	if (tab[4] == 1)
	{
		if (tab[5] > 0 || tab[6] == 1)
			if (tab[5] > 0)
				precision = tab[5];
			if (tab[6] == 1)
				precision = va_arg(l_args, int);
		return (precision); 
	}

	if ((tab[2] > 0 || tab[3] == 1) && tab[1] == 1)
	{
		if (tab[2] > 0)
			precision = tab[2];
		if (tab[3] == 1)
			precision = va_arg(l_args, int);
	}
	return (precision);
}

int		ft_conv_u(va_list l_args, int *tab)
{
	int 	space;
	char 	*str_number;
	int 	len_nbr;
	int 	precision;
	unsigned int 	number;

	space 		= ft_conv_u_space_manage(l_args, tab);
	precision 	= ft_conv_u_precision_manage(l_args, tab);
	number 		= va_arg(l_args, unsigned int);
	len_nbr 	= ft_len_un_number(number);
	str_number 	= ft_utoa_printf(number, len_nbr);

	
	ft_conv_u_to_print(str_number, tab, space, len_nbr, precision, number);
	free(str_number);

	return (0);
}




































