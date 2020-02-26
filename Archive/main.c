#include "libftprintf.h"

// void	ft_itoa_x(unsigned int nb)
// {
// 	char *base;

// 	if (nb == 0)
// 		write(1, '0', 1);
// 	else
// 	{
// 		base = "0123456789abcdef";
// 		if (nb / 16)
// 			ft_itoa_x(nb / 16);
// 		ft_putchar(base[nb % 16]);
// 	}
// }

// void	ft_putnbr(int nb)
// {
// 	if (nb = -2147483648)
// 		ft_putstr("-2147483648");
// 	else
// 	{
// 		if (nb < 0)
// 		{
// 			write(1, '-', 1);
// 			nb = -nb;
// 		}
// 		if (nb > 9)
// 			ft_putnbr(nb / 10);
// 		ft_putchar(nb % 10 + 48);
// 	}
// }

int main()
{
	printf("----- Test 8 ----- \n");
	ft_printf("Charles = (Bonjour %-0..*d)\n", 50,  123);
	printf("PRINTF  = (Bonjour %-0..*d)\n", 50,  123);

	return (0);
}