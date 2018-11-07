/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 18:19:53 by ghtouman          #+#    #+#             */
/*   Updated: 2018/11/07 15:53:47 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_flag.h"

void	print_d_i(void *element, pf_flags flags)
{
	if (flags.check_flags & 0x02)
	{
		modifier[flags.index_m].fct_m(element, flags);
		return ;
	}
	ft_write_p((int)element, flags, 10);
	ft_putnbr_no_minus((int)element);
}

void	print_D(void *element, pf_flags flags)
{
	if (flags.check_flags & 0x02)
	{
		modifier[flags.index_m].fct_m(element, flags);
		return ;
	}
	ft_write_p((long int)element, flags, 10);
	ft_putlnbr((long int)element);
}


// void	print_D(va_list ap, t_list *ma_list)
// {
// 	t_elem		element;
//
// 	element = (t_elem){0, 0, NULL};
// 	if (check_modifie(ma_list, ap, &element, "int"))
// 	{
// 		ft_putnbrre(element.elem);
// 		return ;
// 	}
// 	element.elem = va_arg(ap, long int);
// 	ft_putnbrre(element.elem);
// }
//
// void	print_O(va_list ap, t_list *ma_list)
// {
// 	t_elem		element;
//
// 	element = (t_elem){0, 0, NULL};
// 	if (check_modifie(ma_list, ap, &element, "u_int"))
// 	{
// 		ft_putstr(ft_itoa_base_maj(element.u_elem, 8, "0123456789abcdef"));
// 		return ;
// 	}
// 	element.u_elem = va_arg(ap, unsigned long int);
// 	ft_putstr(ft_itoa_base_maj(element.u_elem, 8, "0123456789abcdef"));
// }
//
// void	print_U(va_list ap, t_list *ma_list)
// {
// 	t_elem		element;
//
// 	element = (t_elem){0, 0, NULL};
// 	if (check_modifie(ma_list, ap, &element, "u_int"))
// 	{
// 		ft_putstr(ft_itoa_base_maj(element.u_elem, 10, "0123456789abcdef"));
// 		return ;
// 	}
// 	element.u_elem = va_arg(ap, unsigned long int);
// 	ft_putstr(ft_itoa_base_maj(element.u_elem, 10, "0123456789abcdef"));
// }
