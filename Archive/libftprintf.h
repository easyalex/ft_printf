/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouleng <cbouleng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 13:01:44 by cbouleng          #+#    #+#             */
/*   Updated: 2019/12/29 18:12:09 by cbouleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>

int			ft_putnbr(int nb);
int			ft_putstr(char *str);
void		ft_putchar(char c);
int			ft_strlen(char *str);
void		ft_itoa_x(unsigned int nb);
void		ft_itoa_hex(unsigned int nb);
void		ft_putnbr_u(unsigned int nb);
int			ft_putnbr_zero(int nbr);
int			ft_nbrlen(int nb);
int			ft_nbrlen_u(unsigned int nb);
int			ft_nbrlen_hex(unsigned int nb);
int			ft_plen(size_t pt);
void		ft_print_p(size_t pt);

char		fmt_read(char *str);
int			flaglen(char *str);
int			dealer(char fmt, char *str, va_list args);
int			ft_printf(const char *c_str, ...);

int			po_precision(char *str);
int			read_flag(char *str, va_list args);
int			po_print(int space);
int			po_zero(va_list args, char *str);
int			po_flag(char *str, va_list args);

int			c_precision(char *str);
int			c_pre_sp(char *str, va_list args);
int			c_bspace(char *str, va_list args);
int			c_space(char *str, va_list args);
int			c_bs_given(va_list args, int space);
int			c_s_given(va_list args, int space);
int			c_star(va_list args);
int			c_p_manage(char *str, va_list args);
int			c_simple(va_list args);
int			c_flag(char *str, va_list args);

int			di_precision(char *str);
int			di_pre_sp(char *str, va_list args);
int			di_pre_zr(char *str, va_list args);
int			di_s_given_null(int space);
int			di_s_given(va_list args, int space);
int			di_sz_given2(int zero, int len, int value);
int			di_sz_given(va_list args, int space, int zero);
int			di_bsz_given_neg(int value, int space, int zero);
int			di_bsz_given(va_list args, int space, int zero);
int			di_null(va_list args, int zero);
int			di_p_zero(va_list args, int zero);
int			di_p_manage(char *str, va_list args);
int			di_zero_neg(int value, int zero);
int			di_print(va_list args, int space);
int			di_zero(char *str, va_list args);
int			di_flag(char *str, va_list args);

int			ix_precision(char *str);
int			ix_pre_sp(char *str, va_list args);
int			ix_pre_zr(char *str, va_list args);
int			ix_s_given_null(int space, int zero);
int			ix_s_given(va_list args, int space, int zero);
int			ix_sz_given2(int zero, int len, unsigned int value);
int			ix_sz_given(va_list args, int space, int zero);
int			ix_bsz_given(va_list args, int space, int zero);
int			ix_p_manage(char *str, va_list args);
int			ix_print(va_list args, int space);
int			ix_zero(char *str, va_list args);
int			ix_flag(char *str, va_list args);

int			p_precision(char *str);
int			p_pre_sp(char *str, va_list args);
int			p_space(char *str, va_list args);
int			p_bspace(char *str, va_list args);
int			p_bs_given(va_list args, int space, int lever);
int			p_s_given(va_list args, int space, int lever);
int			p_star(va_list args);
int			p_print(va_list args);
int			p_p_manage(char *str, va_list args);
int			p_flag(char *str, va_list args);

int			s_precision(char *str);
int			s_pre_sp(char *str, va_list args);
int			s_pre_zr(char *str, va_list args);
int			s_bs_given(va_list args, int space);
int			s_s_given(va_list args, int space);
int			s_star(va_list args);
int			s_print(va_list args);
int			s_no_print(int space);
int			s_sz_given(va_list args, int space, int zero);
int			s_bsz_given(va_list args, int space, int zero);
int			s_z_given(va_list args, int zero);
int			s_space(char *str, va_list args);
int			s_bspace(char *str, va_list args);
int			s_zero(char *str, va_list args);
int			s_p_manage(char *str, va_list args);
int			s_flag(char *str, va_list args);

int			u_precision(char *str);
int			u_pre_sp(char *str, va_list args);
int			u_pre_zr(char *str, va_list args);
int			u_s_given_null(int space, int zero);
int			u_s_given(va_list args, int space, int zero);
int			u_sz_given2(int zero, int len, unsigned int value);
int			u_sz_given(va_list args, int space, int zero);
int			u_bsz_given(va_list args, int space, int zero);
int			u_p_manage(char *str, va_list args);
int			u_print(va_list args, int space);
int			u_zero(char *str, va_list args);
int			u_flag(char *str, va_list args);

int			x_precision(char *str);
int			x_pre_sp(char *str, va_list args);
int			x_pre_zr(char *str, va_list args);
int			x_s_given_null(int space, int zero);
int			x_s_given(va_list args, int space, int zero);
int			x_sz_given2(int zero, int len, unsigned int value);
int			x_sz_given(va_list args, int space, int zero);
int			x_bsz_given(va_list args, int space, int zero);
int			x_p_manage(char *str, va_list args);
int			x_print(va_list args, int space);
int			x_zero(char *str, va_list args);
int			x_flag(char *str, va_list args);

#endif
