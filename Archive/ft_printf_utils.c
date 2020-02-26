/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouleng <cbouleng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:56:07 by cbouleng          #+#    #+#             */
/*   Updated: 2020/02/04 09:40:53 by cbouleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_putnbr_zero(int nbr)
{
	long	nb;

	nb = -nbr;
	if (nbr == -2147483648)
		return (ft_putstr("2147483648"));
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + 48);
	return (0);
}

int		ft_putnbr(int nbr)
{
	long	nb;

	nb = nbr;
	if (nbr == -2147483648)
		return (ft_putstr("-2147483648"));
	else
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nb = -nbr;
		}
		if (nb > 9)
			ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
	return (0);
}

int		ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}
