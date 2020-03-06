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


int 	ft_dispatch(char fmt, va_list l_args, int *tab)
{
	// if (fmt == '%')
	// 	return (ft_conv_100(ptr_format2, tab));
	if (fmt == 'c')
		return (ft_conv_c(l_args, tab));
	else if (fmt == 's')
		return (ft_conv_s(l_args, tab));
	else if (fmt == 'd' || fmt == 'i')
		return (ft_conv_di(l_args, tab));
	// else if (fmt == 'u')
	// 	return (ft_conv_u(l_args, tab));
	// else if (fmt == 'x' || fmt == 'X')
	// 	return (ft_conv_xX(l_args, tab));
	// else if (fmt == 'p')
	// 	return (ft_conv_p(l_args, tab));
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
	while (i <= 6)
		tab[i++] = 0;
	while (*ptr_format2 !='\0' && *ptr_format2 != format)
	{
		if (*ptr_format2 == '-')
			tab[0] = 1;
		else if (*ptr_format2 == '0')
			tab[1] = 1;
		else if (*ptr_format2 > '0' && *ptr_format2 <= '9' && tab[4] == 0)
			tab[2] = (ft_atoi(&ptr_format2));
		else if (*ptr_format2 == '*' && tab[4] == 0)
			tab[3] = 1;
		else if (*ptr_format2 == '.')
			tab[4] = 1;
		else if (*ptr_format2 > '0' && *ptr_format2 <= '9' && tab[4] == 1)
			tab[5] = (ft_atoi(&ptr_format2));
		else if (*ptr_format2 == '*' && tab[4] == 1)
			tab[6] = 1;
		*ptr_format2++;
	}
	// i = 0;
	// printf("\nTab[%d] (-) 	= ('%d')\n", 0, tab[0]);
	// printf("\nTab[%d] (0) 	= ('%d')\n", 1, tab[1]);
	// printf("\nTab[%d] (nbr1)	= ('%d')\n", 2, tab[2]);
	// printf("\nTab[%d] (*) 	= ('%d')\n", 3, tab[3]);
	// printf("\nTab[%d] (.) 	= ('%d')\n", 4, tab[4]);
	// printf("\nTab[%d] (nbr2)	= ('%d')\n", 5, tab[5]);
	// printf("\nTab[%d] (*) 	= ('%d')\n", 6, tab[6]);
	// while(i <= 6)
	// {
	// 	printf("\nTab[%d] = ('%d')\n", 1, tab[i]);
	// 	i++;
	// }
	return (0);
}


int		ft_pars(char *ptr_format2, va_list l_args)
{
	int tab[7];
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
			ft_dispatch(format, l_args, tab);
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
	
	// printf("\n\n----- Test lettre %%d ----- = a number 123\n");
	// printf("----- Test 1 ----- = 'Bonjour [%%d]'		== Affiche simplement le chiffre\n");
	printf("OK - THEFONCTION = (Bonjour %-10.*d)\n",2 , 5214123);
	ft_printf("OK - THEABONNISS = (Bonjour %-10.*d)\n\n",2 , 5214123);

	printf("OK - THEFONCTION = (Bonjour %010.*d)\n",2 , 5214123);
	ft_printf("OK - THEABONNISS = (Bonjour %010.*d)\n\n",2 , 5214123);

	printf("OK - THEFONCTION = (Bonjour %10.*d)\n",2 , 5214123);
	ft_printf("OK - THEABONNISS = (Bonjour %10.*d)\n\n",2 , 5214123);

	printf("OK - THEFONCTION = (Bonjour %20.15d)\n", 5214123);
	ft_printf("OK - THEABONNISS = (Bonjour %20.15d)\n\n", 5214123);

	// printf("----- Test 2 ----- = 'Bonjour [%%7d]' 		== Met 7 'espace' avant le chiffre\n");
	printf("OK - THEFONCTION = (Bonjour %7d)\n", 123);
	ft_printf("OK - THEABONNISS = (Bonjour %7d)\n\n", 123);
	
	// printf("----- Test 3 ----- = 'Bonjour [%%-7d]'		== Met 7 'espace' apres le chiffre grace au '-'\n");
	printf("OK - THEFONCTION = (Bonjour %-7d)\n", 123);
	ft_printf("OK - THEABONNISS = (Bonjour %-7d)\n\n", 123);
	
	// printf("----- Test 3 bis ----- = 'Bonjour [%%-d]'	== Ne fait rien de plus qu'afficher le chiffre\n");
	printf("OK - THEFONCTION = (Bonjour %-d)\n", 123);
	ft_printf("OK - THEABONNISS = (Bonjour %-d)\n\n", 123);
	
	// printf("----- Test 5 ----- = 'Bonjour [%%7.5d]' 		== Tient compte du 7 pour les espaces avant le chiffre et met 5 '0' -> le chiffre et les 0 on la priorite et reduise les espaces\n");
	printf("OK - THEFONCTION = (Bonjour %7.5d)\n", 123);
	ft_printf("OK - THEABONNISS = (Bonjour %7.5d)\n\n", 123);
	
	// printf("----- Test 5bis ----- = 'Bonjour [%%.5d]' 	== C'est le '.' qui permet de mettre 5 '0' devant le chiffre moins les chiffres de %%d\n");
	printf("OK - THEFONCTION = (Bonjour %.5d)\n", 123);
	ft_printf("OK - THEABONNISS = (Bonjour %.5d)\n\n", 123);
	
	// printf("----- Test 6 ----- = 'Bonjour [%%--7d]'		== Peut importe le nbr de '-' met des espace apres le chiffre\n");
	printf("OK - THEFONCTION = (Bonjour %--7d)\n", 123);
	ft_printf("OK - THEABONNISS = (Bonjour %--7d)\n\n", 123);
	
	// printf("----- Test 8 ----- = 'Bonjour [%%07d]'		== Remplis de '0' en soustrayant le nombre de chiffre a afficher\n");
	printf("THEFONCTION = (Bonjour %07d)\n", 123);
	ft_printf("THEABONNISS = (Bonjour %07d)\n\n", 123);
	
	printf("THEFONCTION = (Bonjour %-07.0d)\n", 123);
	ft_printf("THEABONNISS = (Bonjour %-07.0d)\n\n", 123);
	
	printf("THEFONCTION = (Bonjour %-*.*d)\n", 10, 10, 123);
	ft_printf("THEABONNISS = (Bonjour %-*.*d)\n\n", 10, 10, 123);
	
	// printf("----- Test 8 ----- = 'Bonjour [%%70d]'		== Met des 70 espace avant d'afficher le nombre\n");
	printf("OK - THEFONCTION = (Bonjour %70d)\n", 123);
	ft_printf("OK - THEABONNISS = (Bonjour %70d)\n\n", 123);
	// printf("----- Test 11 ----- = 'Bonjour [%%*d]'		== * Prend le chiffre en parametre et remplace '*'\n");
	printf("OK - THEFONCTION = (Bonjour %*d)\n", 10, 456);
	ft_printf("OK - THEABONNISS = (Bonjour %*d)\n\n", 10, 456);
	
	printf("OK - THEFONCTION = (Bonjour %0*d)\n", 10, 456);
	ft_printf("OK - THEABONNISS = (Bonjour %0*d)\n\n", 10, 456);
	
	printf("OK - THEFONCTION = (Bonjour %0*.10d)\n", 10, 456);
	ft_printf("OK - THEABONNISS = (Bonjour %0*.10d)\n\n", 10, 456);




			//AFFICHER STRING S//

	// printf("----- Test 2 -----\n");
	// printf("THEFONCTION = (Bonjour %10.*s)\n", 20, "str123");
	// ft_printf("THEABONNISS = (Bonjour %10.*s)\n", 20, "str123");
	// printf("----- Test 1 ----- = 'Bonjour %%s'\n");
	// printf("THEFONCTION = (Bonjour %s)\n", "str123");
	// ft_printf("THEABONNISS = (Bonjour %s)\n", "str123");
	// printf("----- Test 1 ----- = 'Bonjour %%.s'\n");
	// printf("THEFONCTION = (Bonjour %.s)\n", "str123");
	// ft_printf("THEABONNISS = (Bonjour %.s)\n", "str123");
	// printf("----- Test 2 ----- = 'Bonjour %%7s'\n");
	// printf("THEFONCTION = (Bonjour %7s)\n", "str123");
	// ft_printf("THEABONNISS = (Bonjour %7s)\n", "str123");
	// printf("----- Test 3 ----- = 'Bonjour %%-7s'\n");
	// printf("THEFONCTION = (Bonjour %-7s)\n", "str123");
	// ft_printf("THEABONNISS = (Bonjour %-7s)\n", "str123");
	// printf("----- Test 3 ----- = 'Bonjour %%-*s', 20\n");
	// printf("THEFONCTION = (Bonjour %-*s)\n", 20, "str123");
	// ft_printf("THEABONNISS = (Bonjour %-*s)\n", 20, "str123");
	// printf("----- Test 5 ----- = 'Bonjour %%7.50s'\n");
	// printf("THEFONCTION = (Bonjour %7.50s)\n", "str123");
	// ft_printf("THEABONNISS = (Bonjour %7.50s)\n", "str123");
	// printf("----- Test 5 ----- = 'Bonjour %%*.*s' 5 , 10 \n");
	// printf("THEFONCTION = (Bonjour %*.*s)\n", 5, 10, "str123");
	// ft_printf("THEABONNISS = (Bonjour %*.*s)\n", 5, 10, "str123");
	// printf("----- Test 5 ----- = 'Bonjour %%*.*s' 10 , 5 \n");
	// printf("THEFONCTION = (Bonjour %*.*s)\n", 10, 5, "str123");
	// ft_printf("THEABONNISS = (Bonjour %*.*s)\n", 10, 5, "str123");
	// printf("----- Test 5 ----- = 'Bonjour %%*.(-)*s' 10 , 5 == Undifined behavior avec -Werror\n");
	// // printf("THEFONCTION = (Bonjour %*.-*s)\n", 10, 5, "str123");
	// // ft_printf("THEABONNISS = (Bonjour %*.-*s)\n", 10, 5, "str123");
	// printf("----- Test 5 ----- = 'Bonjour %%(-)*.*s' 10 , 5\n");
	// printf("THEFONCTION = (Bonjour %-*.*s)\n", 10, 5, "str123");
	// ft_printf("THEABONNISS = (Bonjour %-*.*s)\n", 10, 5, "str123");

			//AFFICHER CHAR C//

	// ft_printf("THEABONNISS = (Bonjour %-*c et le reste)\n", 100, 'a');
	// printf("THEFONCTION = (Bonjour %-*c et le reste)\n", 100, 'a');
	// printf("----- Test 1 ----- = 'Bonjour %%c'\n");
	// printf("THEFONCTION = (Bonjour %c)\n", 'A');
	// ft_printf("THEABONNISS = (Bonjour %c)\n", 'A');
	// printf("----- Test 2 ----- = 'Bonjour %%10c'\n");
	// printf("THEFONCTION = (Bonjour %10c)\n", 'A');
	// ft_printf("THEABONNISS = (Bonjour %10c)\n", 'A');
	// printf("----- Test 3 ----- = 'Bonjour %%*c'\n");
	// printf("THEFONCTION = (Bonjour %*c)\n", 10, 'A');
	// ft_printf("THEABONNISS = (Bonjour %*c)\n", 10, 'A');
	// printf("----- Test 4 ----- = 'Bonjour %%-10c'\n");
	// printf("THEFONCTION = (Bonjour %-10c)\n", 'A');
	// ft_printf("THEABONNISS = (Bonjour %-10c)\n", 'A');
	// printf("----- Test 5 ----- = 'Bonjour %%--10c' (peut importe le nbr de '-')\n");
	// printf("THEFONCTION = (Bonjour %--10c)\n", 'A');
	// ft_printf("THEABONNISS = (Bonjour %--10c)\n", 'A');
	// printf("----- Test 6 ----- = 'Bonjour %%10.c' == Undifined behavior avec -Werror\n");
	// printf("THEFONCTION = (Bonjour %10.c)\n", 'A');
	// ft_printf("THEABONNISS = (Bonjour %10.c)\n", 'A');


	return (0);
}

