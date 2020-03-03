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
#include "libft.h"

int 	ft_conv_c(char *ptr_format2, va_list l_args, int *tab);
int		ft_atoi(char **ptr_format2);
int 	ft_dispatch(char fmt, char *ptr_format2, va_list l_args, int *tab);
char	ft_find_letter(char *letter_set, char *str);
int		ft_analyse_options(char *ptr_format2, char format, int *tab);
int 	ft_pars(char *ptr_format2, va_list l_args);


#endif