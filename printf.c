#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// void	ft_dispatch(char **ptr_format3)
// {

// 	// printf("NAME = 	ptr_format3 	VALUE = [%p]->[%c] ADRESS = [%p]\n", ptr_format3, **ptr_format3, &ptr_format3);
// 	char **ptr_format31;
// 	char *set = "cspdiuxX%";

// 	ptr_format31 = ptr_format3;
// 	while (**ptr_format31)
// 	{
// 		if (**ptr_format31 == *set)
// 	}

// 	++*ptr_format3;
// }

// int ft_pars(char *ptr_format2)
// {
// 	int			count = 0;
// 	// printf("NAME = 	ptr_format2 	VALUE = [%p]->[%c] ADRESS = [%p]\n", ptr_format2, *ptr_format2, &ptr_format2);

// 	while (*ptr_format2)
// 	{
// 		if (*ptr_format2 != '%')
// 		{
// 			write(1, ptr_format2, 1); // On ne met pas '*' devant ptr_format2 car write prend une adresse.
// 			// write(1, "hello", 1);
// 			// write(1, &c, 1);
// 			// char	*ptr;
// 			// ptr = &c;
// 			// write(1, ptr, 1);
// 			ptr_format2++;
// 		}
// 		else
// 			ft_dispatch(&ptr_format2);
// 	}

// 	return (count);
// }

// int ft_printf(const char *format,...)
// {
// 	va_list list_of_arg;
// 	int		res;
// 	int		nbr_arg;
// 	char	*ptr_format;

// 	ptr_format = (char*)format; // char* juste pour caster
// 	// printf("NAME = 	format 		VALUE = [%p]->[%c] ADRESS = [%p]\n", format, *format, &format);
// 	// printf("NAME = 	Ptr_format 	VALUE = [%p]->[%c] ADRESS = [%p]\n", ptr_format, *ptr_format, &ptr_format);

// 	nbr_arg = ft_pars(ptr_format); 

// 	// printf("Nombre de para envoyes = %d\n", nbr_arg);

// 	va_start(list_of_arg, format);
	
// 	// str = va_arg(list_of_arg, char *);

// 	va_end(list_of_arg);
// 	return (res);
// }

int main ()
{
	// printf("\n\n----- Test lettre S ----- = a string of characters 'str123'\n");
	// printf("----- Test 1 ----- = 'Bonjour %%s'\n");
	// printf("PRINTF = (Bonjour %s)\n", "str123");
	// printf("----- Test 2 ----- = 'Bonjour %%7s'\n");
	// printf("PRINTF = (Bonjour %7s)\n", "str123");
	// printf("----- Test 3 ----- = 'Bonjour %%-7s'\n");
	// printf("PRINTF = (Bonjour %-7s)\n", "str123");
	// printf("----- Test 4 ----- = 'Bonjour %%+7s' == Undifined behavior avec -Werror\n");
	// // printf("PRINTF = (Bonjour %+7s)\n", "str123");
	// printf("----- Test 5 ----- = 'Bonjour %%7.50s'\n");
	// printf("PRINTF = (Bonjour %7.50s)\n", "str123");
	// printf("----- Test 6 ----- = 'Bonjour %%--7s'(peut importe le nbr de '-')\n");
	// printf("PRINTF = (Bonjour %--7s)\n", "str123");
	// printf("----- Test 7 ----- = 'Bonjour %%++7s' == Undifined behavior avec -Werror\n");
	// // printf("PRINTF = (Bonjour %++7s)\n", "str123");
	// printf("----- Test 8 ----- = 'Bonjour %%07s' == Undifined behavior avec -Werror\n");
	// // printf("PRINTF = (Bonjour %07s)\n", "str123");
	// printf("----- Test 9 ----- = 'Bonjour %%@7s' == Undifined behavior avec -Werror\n");
	// // printf("PRINTF = (Bonjour %@7$s)\n", "str123");
	// printf("----- Test 10 ----- = 'Bonjour %%7#s' == Undifined behavior avec -Werror\n");
	// // printf("PRINTF = (Bonjour %7#s)\n", "str123");

	// printf("\n\n----- Test lettre C ----- = a character 'c'\n");
	// printf("----- Test 1 ----- = 'Bonjour %%c'\n");
	// printf("PRINTF = (Bonjour %c)\n", 'c');
	// printf("----- Test 2 ----- = 'Bonjour %%7c'\n");
	// printf("PRINTF = (Bonjour %7c)\n", 'c');
	// printf("----- Test 3 ----- = 'Bonjour %%-7c'\n");
	// printf("PRINTF = (Bonjour %-7c)\n", 'c');
	// printf("----- Test 4 ----- = 'Bonjour %%+7c' == Undifined behavior avec -Werror\n");
	// // printf("PRINTF = (Bonjour %+7c)\n", 'c');
	// printf("----- Test 5 ----- = 'Bonjour %%7.50c' == Undifined behavior avec -Werror\n");
	// // printf("PRINTF = (Bonjour %7.50c)\n", 'c');
	// printf("----- Test 6 ----- = 'Bonjour %%--7c' (peut importe le nbr de '-')\n");
	// printf("PRINTF = (Bonjour %--7c)\n", 'c');
	// printf("----- Test 7 ----- = 'Bonjour %%++7c' == Undifined behavior avec -Werror\n");
	// // printf("PRINTF = (Bonjour %++7c)\n", 'c');
	// printf("----- Test 8 ----- = 'Bonjour %%07c' == Undifined behavior avec -Werror\n");
	// // printf("PRINTF = (Bonjour %07c)\n", 'c');
	// printf("----- Test 9 ----- = 'Bonjour %%@7c' == Undifined behavior avec -Werror\n");
	// // printf("PRINTF = (Bonjour %@7$c)\n", 'c');
	// printf("----- Test 10 ----- = 'Bonjour %%7#c' == Undifined behavior avec -Werror\n");
	// // printf("PRINTF = (Bonjour %7#c)\n", 'c');

	printf("\n\n----- Test lettre d ----- = a number 123\n");
	printf("----- Test 1 ----- = 'Bonjour %%d'\n");
	printf("PRINTF = (Bonjour %d)\n", 123);
	printf("----- Test 2 ----- = 'Bonjour %%7d'\n");
	printf("PRINTF = (Bonjour %7d)\n", 123);
	printf("----- Test 3 ----- = 'Bonjour %%-7d'\n");
	printf("PRINTF = (Bonjour %-7d)\n", 123);
	printf("----- Test 4 ----- = 'Bonjour %%+7d' == Undifined behavior avec -Werror\n");
	printf("PRINTF = (Bonjour %+7d)\n", 123);
	printf("----- Test 5 ----- = 'Bonjour %%7.50d' == Undifined behavior avec -Werror\n");
	printf("PRINTF = (Bonjour %7.50d)\n", 123);
	printf("----- Test 6 ----- = 'Bonjour %%--7d' (peut importe le nbr de '-')\n");
	printf("PRINTF = (Bonjour %--7d)\n", 123);
	printf("----- Test 7 ----- = 'Bonjour %%++7d' == Undifined behavior avec -Werror\n");
	printf("PRINTF = (Bonjour %++7d)\n", 123);
	printf("----- Test 8 ----- = 'Bonjour %%07d' == Undifined behavior avec -Werror\n");
	printf("PRINTF = (Bonjour %07d)\n", 123);
	printf("----- Test 9 ----- = 'Bonjour %%@7d' == Undifined behavior avec -Werror\n");
	// printf("PRINTF = (Bonjour %@7$d)\n", 123);
	printf("----- Test 10 ----- = 'Bonjour %%7#d' == Undifined behavior avec -Werror\n");
	// printf("PRINTF = (Bonjour %7#d)\n", 123);

	// ft_printf("ABONNIS = (Bonjour %7.35514456155s)\n", "str123");

	// printf("----- Test 2 -----\n");
	// printf("Bonjour %d\n", "str123");
	// ft_printf("Bonjour %-7.2s\n", "str123");

	// ft_printf("Bonjour %-7.2s et %d-7", "hhhhh", 19);

	return (0);
}

