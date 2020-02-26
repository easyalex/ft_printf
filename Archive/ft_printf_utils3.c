/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouleng <cbouleng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:40:24 by cbouleng          #+#    #+#             */
/*   Updated: 2020/02/04 09:44:31 by cbouleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_nbrlen(int nb)
{
	int i;

	i = 1;
	if (nb < 0)
	{
		i++;
		nb = -nb;
	}
	while ((nb /= 10) >= 1)
		i++;
	return (i);
}

int		ft_nbrlen_u(unsigned int nb)
{
	int i;

	i = 1;
	while ((nb /= 10) >= 1)
		i++;
	return (i);
}

int		ft_nbrlen_hex(unsigned int nb)
{
	int i;

	i = 1;
	while ((nb /= 16) >= 1)
		i++;
	return (i);
}

int		ft_plen(size_t pt)
{
	int i;

	i = 3;
	while (pt /= 16)
		i++;
	return (i);
}

void	ft_print_p(size_t pt)
{
	if (pt / 16)
		ft_print_p(pt / 16);
	if ((pt % 16) < 10)
		ft_putchar((pt % 16) + 48);
	else
		ft_putchar((pt % 16) + 87);
}
