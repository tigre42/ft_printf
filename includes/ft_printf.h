/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:32:20 by ghtouman          #+#    #+#             */
/*   Updated: 2018/11/07 14:03:33 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "../libft/libft.h"

typedef	struct		s_flags
{
	char			check_flags;
	unsigned char	index_s;
	unsigned char	index_m;
	unsigned int	precision;
	unsigned int	width;
	char			check_char;;
}					pf_flags;

typedef struct		s_specifier
{
	char			flag_s;
	void			(*fct_s)(void*, pf_flags);
}					t_specifier;

typedef struct		s_modifier
{
	char			flag_m;
	void			(*fct_m)(void*, pf_flags);
}					t_modifier;

typedef struct		s_character
{
	char			flag_c;
	//	void			(*fct)(char);
}					t_character;

int					ft_printf(const char *format, ...);
void				print_d_i(void *element, pf_flags flags);
void				print_o(void *element, pf_flags flags);
void				print_O(void *element, pf_flags flags);
void				print_x(void *element, pf_flags flags);
void				print_X(void *element, pf_flags flags);
void				print_u(void *element, pf_flags flags);
void				print_U(void *element, pf_flags flags);
void				print_D(void *element, pf_flags flags);
void				print_p(void *element, pf_flags flags);
void				print_c(void *element, pf_flags flags);
void				print_C(void *element, pf_flags flags);
void				print_s(void *element, pf_flags flags);
void				print_S(void *element, pf_flags flags);

void				modif_h(void *element, pf_flags);
void				modif_hh(void *element, pf_flags);
void				modif_j(void *element, pf_flags);
void				modif_l(void *element, pf_flags);
void				modif_ll(void *element, pf_flags);
void				modif_z(void *element, pf_flags);

int					ft_control(pf_flags flags, va_list ap);
void				ft_putnbr_base(unsigned int n, unsigned int b, char maj);
void				ft_putlnbr_base(unsigned long n, unsigned int b, char maj);
void				ft_putllnbr_base(uintmax_t n, uintmax_t b, char maj);
void				ft_putlnbr(long int n);
void				ft_putnbr_no_minus(intmax_t n);

void				ft_putwchar(wchar_t element);
void				ft_putwstr(wchar_t *str);

size_t				ft_len_number(intmax_t nb, size_t len, char base);
size_t				ft_len_number_u(uintmax_t nb, size_t len, char base);

int					ft_parse_flags(const char *format, va_list ap, size_t *ret);
void				ft_check_characters(pf_flags *flags, char **str);
void				ft_check_modifier(pf_flags *flags, char **str);
void				ft_check_precision(pf_flags *flags, char **str);
void				ft_write_p_u(uintmax_t element, pf_flags flags, char base);
void				ft_write_p(intmax_t element, pf_flags flags, char base);

int					ft_check_specifier(pf_flags *flags, char *str);

void				ft_check_width(pf_flags *flags, char **str);
void				ft_print_width(intmax_t element, pf_flags flags, int len);
void				ft_print_width_s(pf_flags flags, size_t len);









# endif
