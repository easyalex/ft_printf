/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h.                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:51:58 by abonniss          #+#    #+#             */
/*   Updated: 2020/02/11 18:52:06 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_atoi(char ***ptr_format2);
char	ft_dispatch(char **ptr_format2);
int 	ft_pars(char *ptr_format2);
int 	ft_printf(const char *format,...);


#endif