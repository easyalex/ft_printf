/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouleng <cbouleng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 12:17:41 by cbouleng          #+#    #+#             */
/*   Updated: 2020/02/04 09:43:09 by cbouleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_itoa_x(unsigned int nb)
{
	char			*base;
	unsigned int	nbr;

	nbr = nb;
	if (nb == 0)
		ft_putchar('0');
	else
	{
		base = "0123456789abcdef";
		if (nbr / 16)
			ft_itoa_x(nbr / 16);
		ft_putchar(base[nbr % 16]);
	}
}

void	ft_itoa_hex(unsigned int nb)
{
	char			*base;
	unsigned int	nbr;

	nbr = nb;
	if (nb == 0)
		ft_putchar('0');
	else
	{
		base = "0123456789ABCDEF";
		if (nbr / 16)
			ft_itoa_hex(nbr / 16);
		ft_putchar(base[nbr % 16]);
	}
}

void	ft_putnbr_u(unsigned int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr_u(nb / 10);
	ft_putchar(nb % 10 + 48);
}
