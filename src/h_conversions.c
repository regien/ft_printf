/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_conversions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 05:19:58 by gmalpart          #+#    #+#             */
/*   Updated: 2018/03/24 02:52:18 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    f_hhexa(va_list args, t_total *e)
{
	unsigned short  holder;

	holder = (unsigned short)va_arg(args, void*);
	print_hexa((unsigned int)holder, e);
	e->e = e->e - 3;
}

void    f_hhexacap(va_list args, t_total *e)
{
	unsigned short  holder;

	holder = (unsigned short)va_arg(args, void*);
	print_caphexa((unsigned int)holder, e);
	e->e = e->e - 3;
}

void    f_hoctal(va_list args, t_total *e)
{
	unsigned short  holder;

	holder = (unsigned short)va_arg(args, void*);
	ft_putnbroct((unsigned int)holder, e);
	e->e = e->e - 3;
}

void    f_huint(va_list args, t_total *e)
{
	unsigned short holder;

	holder = (unsigned short)va_arg(args, void*);
	ft_putnbruint((unsigned int)holder, e);
	e->e = e->e - 3;
}

void    f_hint(va_list args, t_total *e)
{
	short   holder;

	holder = (unsigned short)va_arg(args, void*);
	ft_putnbrcont((long long)holder, e);
	e->e = e->e - 3;
}
