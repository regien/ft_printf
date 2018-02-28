/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_numbers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 17:03:24 by regien            #+#    #+#             */
/*   Updated: 2018/02/27 17:03:32 by regien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



void        put_paddin(t_total *e, int size)
{
    int vaina;
    
    vaina = 0;
    if (e->wd > size)
    {
        vaina = e->wd - size;
        while (--vaina >= 0)
        {
            ft_putchar(' ');
            e->e = e->e + 1;
        }
    }
}

void        f_alignr(int *i, char const *str, va_list arg, t_total *e)
{
    void    *holder;
    
    holder = va_arg(arg, void*);
    if (str[*i] == 'd' || str[*i] == 'i')
    {
        put_paddin(e, len_number();
    }

}

void        f_right(int *i, char const *str, va_list arg, t_total *e)
{
    int     count;
    
    count = 0;
    e->wd = 0;
    while (str[*i] >= '0' && str[*i] <= '9')
    {
        if (str[*i] >= '0' && str[*i] <= '9')
           e->wd = (e->wd * 10) + (str[*i] - '0');
        *i += 1;
    }
    f_alignr(str, arg, *i, e)
}

//void        f_numbers()