#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_dispatch(char **str)
{
	write(1, "A", 1);
	++*str;
}

int ft_pars(char *ptr_format)
{
	int			count = 0;

	// printf("%s", ptr_format);

	while (*ptr_format)
	{
		if (*ptr_format != '%')
		{	
			write(1, ptr_format, 1);
			// write(1, "hello", 1);
			// write(1, &c, 1);
			// char	*ptr;
			// ptr = &c;
			// write(1, ptr, 1);
			ptr_format++;
		}
		else
			ft_dispatch(&ptr_format);
	}

	return (count);
}

int ft_printf(const char *format,...)
{
	va_list list_of_arg;
	int		res;
	int		nbr_arg;

	// char	c = 'D';


	// printf("%s\n", format);
	char	*ptr_format;
	// char	*ptr_c;

	// ptr_c = &c;

	// printf("%c\n", *format);



	ptr_format = (char*)format; // char* juste pour caster


	nbr_arg = ft_pars(ptr_format); 

	// printf("Nombre de para envoyes = %d\n", nbr_arg);

	va_start(list_of_arg, format);
	
	// str = va_arg(list_of_arg, char *);

	va_end(list_of_arg);
	return (res);
}

int main ()
{
	ft_printf("Bonjour %-7.2s et %d-7", "hhhhh", 19);

	return (0);
}

