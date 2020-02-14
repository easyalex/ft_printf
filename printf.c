#include <stdarg.h>
#include <stdio.h>

//int ft_printf(const char *, ...); cspdiuxX

int ft_pars(const char *str)
{
	int index_str;
	int index_tab;
	int index_tab_str;
	int count;
	char tab_str[10][10];

	index_str = 0;
	index_tab = 0;
	count = 0;
	while (str[index_str])
	{
		index_tab_str = 0;
		if (str[index_str] == '%' && str[index_str + 1] != '%')
		{
			tab_str[index_tab][index_tab_str] = str[index_str];
			index_str++;
			index_tab_str++;
			while ( ((str[index_str] >= '0') && (str[index_str] <= '9')) || 
				((str[index_str] == ('c') || str[index_str] ==('s') ||str[index_str] == ('p') ||str[index_str] == ('d') 
					|| str[index_str] == ('i') || str[index_str] == ('u') || str[index_str] == ('x') || str[index_str] == ('X'))) 
					|| (str[index_str] == ('.') | str[index_str] == ('-') | str[index_str] == ('+')))
			{
				tab_str[index_tab][index_tab_str] = str[index_str];
				index_str++;
				index_tab_str++;
			}
			printf("pars03 index_tab_str[%d] - (%s)\n", index_tab,tab_str[index_tab]);
			index_tab++;
		}
		index_str++;
	}
	return (count);
}

int ft_printf(const char *format,...)
{
	va_list list_of_arg;
	char	*str;
	int		res;
	int		nbr_arg;

	printf("%s\n", format);

	nbr_arg = ft_pars(format); 

	// printf("Nombre de para envoyes = %d\n", nbr_arg);

	va_start(list_of_arg, format);
	
	str = va_arg(list_of_arg, char *);

	va_end(list_of_arg);
	return (res);
}

int main ()
{
	ft_printf("Bonjour %-7.2s et %d-7", "hhhhh", 19);

	return (0);
}

