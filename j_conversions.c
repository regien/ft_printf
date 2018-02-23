/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_conversions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:47:04 by regien            #+#    #+#             */
/*   Updated: 2018/02/22 15:47:11 by regien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    f_jhexa(va_list args, t_total *e)
{
    uintmax_t      holder;

    holder = (uintmax_t)va_arg(args, void*);
	print_hexa((unsigned int)holder, e);
	e->e = e->e - 3;
}

void    f_jhexacap(va_list args, t_total *e)
{
	uintmax_t  holder;

    holder = (uintmax_t)va_arg(args, void*);
    print_caphexa((unsigned int)holder, e);
	e->e = e->e - 3;
}

void    f_joctal(va_list args, t_total *e)
{
    uintmax_t  holder;
    
    holder = (uintmax_t)va_arg(args, void*);
    ft_putnbroct((unsigned int)holder, e);
	e->e = e->e - 3;
}

void    f_juint(va_list args, t_total *e)
{
    uintmax_t    holder;

    holder = (uintmax_t)va_arg(args, void*);
    ft_putnbrcont((long long)holder, e);
	e->e = e->e - 3;
}

void    f_jint(va_list args, t_total *e)
{
    intmax_t   holder;

    holder = (intmax_t)va_arg(args, void*);
    ft_putnbrcont((long long)holder, e);
	e->e = e->e - 3;
}