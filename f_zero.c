/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_zero.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 20:54:40 by gmalpart          #+#    #+#             */
/*   Updated: 2018/02/23 20:54:47 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**  printing zeros
**  changing part : relations with flag + it should 
**  fail with any ohter flag
*/

long long     len_number(long long nbr, int base)
{
    long long   holder;

    holder = 0;
    if (nbr < 0)
    {
        nbr = nbr * -1;
        holder++;
    }
    while (nbr /= base)
        holder++;
    return (holder);
}


void    f_putzeros(t_total *e, int size)
{
    int vaina;
    
    vaina = 0;
    if (e->wd < size)
    {
        vaina = e->wd - size;
        while (--vaina >= 0)
        {
            ft_putchar('0');
            e->e = e->e + 1;
        }
    }
}



void    f_zeroleft(int *i, const char *str, va_list arg, t_total *e)
{
    void    *holder;

    holder = va_arg(arg, void*);
    if(str[*i] == 'd' || str[*i] == 'i')
    {
       f_putzeros(e, (int)len_number((long long)holder, 10));
       ft_putnbrbase((long long)holder, 10, e);
    }
}

void    f_zero(int *i, char const *str, va_list arg, t_total *e)
{
    e->wd = 0;
    // flag + i think is not neccesary
    while (str[*i] >= '0' && str[*i] <= '9')
    {
        if (str[*i] >= '0' && str[*i] <= '9')
            e->wd = (e->wd * 10) + (str[*i] - '0');
        *i += 1;
    }
    f_zeroleft(i, str, arg, e);
}