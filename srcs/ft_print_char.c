/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 18:19:37 by ghtouman          #+#    #+#             */
/*   Updated: 2018/11/09 20:12:07 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(void *element, pf_flags flags)
{
	if (flags.index_m == 1)
	{
		print_C(element, flags);
		return ;
	}
	if (!(flags.check_char & 0x04))
		ft_print_width_s(flags, 1);
	ft_putchar_one((char)element);
	if (flags.check_char & 0x04)
		ft_print_width_s(flags, 1);
}

void	print_C(void *element, pf_flags flags)
{
	wchar_t gheram[2];

	gheram[0] = (wchar_t)element;
	gheram[1] = '\0';
	if (flags.check_flags & 0x08 && (!(flags.check_char & 0x04)))
		ft_width_unicode(flags, gheram);
	if ((gheram[0] > 255 && MB_CUR_MAX != 4) || gheram[0] < 0x0 ||
		(gheram[0] >= 0xd800 && gheram[0] <= 0xdfff) || (gheram[0] > 0x10ffff))
		return ;
	else if (gheram[0] > 0x7f && gheram[0] <= 0xff && MB_CUR_MAX != 4)
		ft_putchar_one(gheram[0]);
	else
		ft_putwchar(gheram[0]);
}

void	print_s(void *element, pf_flags flags)
{
	char *str;
	unsigned int tmp;

	tmp = flags.precision;
	if (flags.index_m == 1)
		return (print_S(element, flags));
	str = (char*)element;
	if (!(flags.check_char & 0x04))
		ft_print_width_s(flags, ft_strlen(str));
	if ((flags.check_flags & 0x04) && flags.precision == 0)
		return (ft_print_width_s(flags, tmp));
	if (*str && flags.precision > 0)
	{
		while (*str && flags.precision-- > 0)
			ft_putchar_count(str++, 1);
		if (flags.check_char & 0x04)
			ft_print_width_s(flags, tmp);
		return ;
	}
	ft_putchar_count(str, ft_strlen(str));
	if (flags.check_char & 0x04)
		ft_print_width_s(flags, ft_strlen(str));
}

void	print_S(void *element, pf_flags flags)
{
	wchar_t		*str;
	size_t		i;
	size_t		weight;
	long int	p;

	str = (wchar_t*)element;
	i = 0;
	if (flags.check_flags & 0x08 && (!(flags.check_char & 0x04)))
		ft_width_unicode(flags, str);
	if (flags.check_flags & 0x04)
	{
		p = (long int)flags.precision;
		while (str[i] && p > 0)
		{
			weight = ft_weight_wchar(str[i]);
			if (p >= weight)
				ft_putwchar(str[i]);
			p = p - weight;
		}
	}
	else
		ft_putwstr((wchar_t*)element);
	if (flags.check_flags & 0x08 && flags.check_char & 0x04)
		ft_width_unicode(flags, str);
}
