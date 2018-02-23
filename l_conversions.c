/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_conversions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 06:26:03 by gmalpart          #+#    #+#             */
/*   Updated: 2018/02/21 06:26:12 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    f_lhexa(va_list args, t_total *e)
{
    unsigned long      holder;

    holder = (unsigned long)va_arg(args, void*);
	print_hexa((unsigned int)holder, e);
	e->e = e->e - 3;
}

void    f_lhexacap(va_list args, t_total *e)
{
	unsigned long  holder;

    holder = (unsigned long)va_arg(args, void*);
    print_caphexa((unsigned int)holder, e);
	e->e = e->e - 3;
}

void    f_loctal(va_list args, t_total *e)
{
    unsigned long  holder;
    
    holder = (unsigned long)va_arg(args, void*);
    ft_putnbroct((unsigned int)holder, e);
	e->e = e->e - 3;
}

void    f_luint(va_list args, t_total *e)
{
    long    holder;

    holder = (long)va_arg(args, void*);
    ft_putnbrcont((long long)holder, e);
	e->e = e->e - 3;
}

void    f_lint(va_list args, t_total *e)
{
    long   holder;

    holder = (long)va_arg(args, void*);
    ft_putnbrcont((long long)holder, e);
	e->e = e->e - 3;
}