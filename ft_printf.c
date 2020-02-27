#include "ft_printf.h"

ft_strchrindex
int				ft_atoi(char ***ptr_format2)
{
	int	number;

	number = 0;
	printf("Ft_atoi = %s\n", **ptr_format2);

	while (***ptr_format2 >= '0' && ***ptr_format2 <= '9')
	{
		number *= 10;
		number += ***ptr_format2 - '0';
		++**ptr_format2;
	}
	printf("Number = %d\n", number);
	--**ptr_format2;
	return (number);
}

char	ft_dispatch(char **ptr_format2)
{
	// printf("NAME = 	ptr_format3 	VALUE = [%p]->[%c] ADRESS = [%p]\n", ptr_format3, **ptr_format3, &ptr_format3);
	++*ptr_format2;
	printf("%s\n", *ptr_format2);
	// ++*ptr_format2;

	int *tab;
	int i;

	tab[5];
	i = 0;
	while(i <= 5)
	{
		tab[i] = 0;
		i++;
	}
	while (**ptr_format2)
	{
		printf("('%c')\n", **ptr_format2);
		if (**ptr_format2 == '-')
			tab[0] = 1;
		else if (**ptr_format2 == '0')
			tab[1] = 1;
		else if (**ptr_format2 > '0' && **ptr_format2 <= '9' && tab[4] == 0)
		{
			printf("Tab[2] = ('%d')\n", tab[2]);
			tab[2] = (ft_atoi(&ptr_format2));
		}
		else if (**ptr_format2 == '*')
			tab[3] = 1;
		else if (**ptr_format2 == '.')
			tab[4] = 1;
		else if (**ptr_format2 > '0' && **ptr_format2 <= '9' && tab[4] == 1)
		{
			tab[5] = (ft_atoi(&ptr_format2));
		}
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
	int			count = 0;
	int			len = 0;
	// printf("NAME = 	ptr_format2 	VALUE = [%p]->[%c] ADRESS = [%p]\n", ptr_format2, *ptr_format2, &ptr_format2);

	while (*ptr_format2)
	{
		if (*ptr_format2 != '%')
		{
			write(1, ptr_format2, 1); // On ne met pas '*' devant ptr_format2 car write prend une adresse.
			ptr_format2++;
		}
		else
			ft_dispatch(&ptr_format2);
	}
	return (count);
}

int ft_printf(const char *format,...)
{
	va_list list_of_arg;
	int		res;
	int		nbr_arg;
	char	*ptr_format;

	ptr_format = (char*)format; // char* juste pour caster
	// printf("NAME = 	format 		VALUE = [%p]->[%c] ADRESS = [%p]\n", format, *format, &format);
	// printf("NAME = 	Ptr_format 	VALUE = [%p]->[%c] ADRESS = [%p]\n", ptr_format, *ptr_format, &ptr_format);

	va_start(list_of_arg, format);

	nbr_arg = ft_pars(ptr_format); 

	// printf("Nombre de para envoyes = %d\n", nbr_arg);

	va_end(list_of_arg);
	return (res);
}

int main ()
{
	ft_printf("ABONNIS = (Bonjour \n%-12.758d)\n");

	// printf("----- Test 2 -----\n");
	// printf("Bonjour %d\n", "str123");
	// ft_printf("Bonjour %-7.2s\n", "str123");

	// ft_printf("Bonjour %-7.2s et %d-7", "hhhhh", 19);

	return (0);
}

