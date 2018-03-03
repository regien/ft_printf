/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_conversions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:09:58 by regien            #+#    #+#             */
/*   Updated: 2018/02/22 15:10:09 by regien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    f_zhexa(va_list args, t_total *e)
{
    size_t      holder;

    holder = (size_t)va_arg(args, void*);
	print_hexa((unsigned int)holder, e);
	e->e = e->e - 3;
}

void    f_zhexacap(va_list args, t_total *e)
{
	size_t  holder;

    holder = (size_t)va_arg(args, void*);
    print_caphexa((unsigned int)holder, e);
	e->e = e->e - 3;
}

void    f_zoctal(va_list args, t_total *e)
{
    size_t  holder;
    
    holder = (size_t)va_arg(args, void*);
    ft_putnbroct((unsigned int)holder, e);
	e->e = e->e - 3;
}

void    f_zuint(va_list args, t_total *e)
{
    size_t   holder;

    holder = (size_t)va_arg(args, void*);
    ft_putlluint((unsigned long long)holder, e);
	e->e = e->e - 3;
}

void    f_zint(va_list args, t_total *e)
{
    size_t  holder;

    holder = (size_t)va_arg(args, void*);
    ft_putnbrcont((long long)holder, e);
	e->e = e->e - 3;
}