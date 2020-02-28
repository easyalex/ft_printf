/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:51:58 by abonniss          #+#    #+#             */
/*   Updated: 2020/02/11 18:52:06 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(char ***ptr_format2)
{
	int	number;

	number = 0;
	while (***ptr_format2 != '\0' && (***ptr_format2 >= '0' && ***ptr_format2 <= '9'))
	{
		number *= 10;
		number += ***ptr_format2 - '0';
		++**ptr_format2;
	}
	--**ptr_format2;
	return (number);
}


void 	ft_dispatch(char c, char ***ptr_format2)
{
	if
}

char		ft_find_letter(char *letter_set, char c)
{
	int i;

	i = 0;
	while (letter_set[i])
	{
		if (letter_set[i] == c)
			return (letter_set[i]);
		i++;
	}
	return (letter_set[i]);
}

char	ft_analyse_options(char **ptr_format2)
{
	int *tab;
	int i;

	tab[6];
	i = 0;
	while(i <= 5)
	{
		tab[i] = 0;
		i++;
	}
	while (**ptr_format2 !='\0')
	{
		if (**ptr_format2 == '-')
			tab[0] = 1;
		else if (**ptr_format2 == '0')
			tab[1] = 1;
		else if (**ptr_format2 > '0' && **ptr_format2 <= '9' && tab[4] == 0)
			tab[2] = (ft_atoi(&ptr_format2));
		else if (**ptr_format2 == '*')
			tab[3] = 1;
		else if (**ptr_format2 == '.')
			tab[4] = 1;
		else if (**ptr_format2 > '0' && **ptr_format2 <= '9' && tab[4] == 1)
			tab[5] = (ft_atoi(&ptr_format2));
		else if (ft_find_letter("cspdiuxX%z", **ptr_format2) != 'z')
			ft_dispatch((ft_find_letter("cspdiuxX%z", **ptr_format2)), &ptr_format2)
		++*ptr_format2;
	}
	i = 0;
	while(i <= 5)
	{
		printf("Tab[%d] = ('%d')\n", i, tab[i]);
		i++;
	}
	return (0);
}

int ft_pars(char *ptr_format2)
{
	while (*ptr_format2 != '\0')
	{
		if (*ptr_format2 != '%')
		{
			write(1, ptr_format2, 1); // On ne met pas '*' devant ptr_format2 car write prend une adresse.
			ptr_format2++;
		}
		else
			ft_dispatch(&ptr_format2);
			// write(1, "Test1\n", 6);
		// ptr_format2++;
	}
	write(1, "Test3\n", 6);
	return (0);
}

int ft_printf(const char *format,...)
{
	// va_list list_of_arg;
	char	*ptr_format;

	ptr_format = (char*)format; // char* juste pour caster

	// va_start(list_of_arg, format);

	ft_pars(ptr_format);

	// va_end(list_of_arg);
	return (0);
}

int main ()
{
	ft_printf("ABONNIS = (Bonjour \n%-12.758dfthfthtfh)\n");

	// printf("----- Test 2 -----\n");
	// printf("Bonjour %d\n", "str123");
	// ft_printf("Bonjour %-7.2s\n", "str123");

	// ft_printf("Bonjour %-7.2s et %d-7", "hhhhh", 19);

	return (0);
}

