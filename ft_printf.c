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
#include "libft.h"

int		ft_atoi(char **ptr_format2)
{
	int	number;

	number = 0;
	while (**ptr_format2 != '\0' && (**ptr_format2 >= '0' && **ptr_format2 <= '9'))
	{
		number *= 10;
		number += **ptr_format2 - '0';
		++*ptr_format2;
	}
	--*ptr_format2;
	return (number);
}


int 	ft_dispatch(char fmt, char *ptr_format2, va_list l_args, int *tab)
{
	// if (fmt == '%')
	// 	return (ft_conv_100(ptr_format2, tab));
	if (fmt == 'c')
		return (ft_conv_c(ptr_format2, l_args, tab));
	// else if (fmt == 'd' || fmt == 'i')
	// 	return (ft_conv_di(ptr_format2, tab));
	// else if (fmt == 'u')
	// 	return (ft_conv_u(ptr_format2, tab));
	// else if (fmt == 'x' || fmt == 'X')
	// 	return (ft_conv_xX(ptr_format2, tab));
	// else if (fmt == 'p')
	// 	return (ft_conv_p(ptr_format2, tab));
	return (0);
}

char	ft_find_letter(char *letter_set, char *str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (letter_set[j])
		{
			if (letter_set[j] == str[i])
				return (letter_set[j]);
			j++;
		}
		i++;
	}
	return ('z');
}

int 	ft_flag_len(char c, char *str)
{
	int i;

	i = 1;
	while (*str)
	{
		if (*str == c)
			return (i);
		i++;
		*str++;
	}
	return (0);
}

int		ft_analyse_options(char *ptr_format2, char format, int *tab)
{
	int i;

	i = 0;
	while (i <= 5)
	{
		tab[i++] = 0;
		// i++;
	}
	while (*ptr_format2 !='\0' && *ptr_format2 != format)
	{
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
		*ptr_format2++;
	}
	i = 0;
	// while(i <= 5)
	// {
	// 	printf("Tab[%d] = ('%d')\n", i, tab[i]);
	// 	i++;
	// }
	return (0);
}


int		ft_pars(char *ptr_format2, va_list l_args)
{
	int tab[6];
	char format;
	int i;

	i = 0;
	while (ptr_format2[i] != '\0')
	{
		if (ptr_format2[i] != '%')
		{
			write(1, (ptr_format2 + i), 1); // On ne met pas '*' devant ptr_format2 car write prend une adresse.
			i++;
		}
		if (ptr_format2[i] == '%')
		{
			format = ft_find_letter("cspdiuxX%z", (ptr_format2 + (i + 1)));
			ft_analyse_options((ptr_format2 + i), format, &tab);
			i += ft_flag_len(format, (ptr_format2 + i));
			ft_dispatch(format, ptr_format2, l_args, tab);
		}
	}
	return (0);
}

int ft_printf(const char *format,...)
{
	va_list l_args;
	char	*ptr_format;

	ptr_format = (char*)format; // char* juste pour caster

	va_start(l_args, format);

	ft_pars(ptr_format, l_args);

	va_end(l_args);
	return (0);
}

int main ()
{
	ft_printf("ABONNIS = (Bonjour %12.145c et le reste)", 'a');

	// printf("----- Test 2 -----\n");
	// printf("Bonjour %d\n", "str123");
	// ft_printf("Bonjour %-7.2s\n", "str123");

	// ft_printf("Bonjour %-7.2s et %d-7", "hhhhh", 19);

	return (0);
}

