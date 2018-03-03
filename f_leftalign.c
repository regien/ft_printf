/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_leftalign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 21:44:35 by gmalpart          #+#    #+#             */
/*   Updated: 2018/03/01 21:44:43 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


// because i just dont remember how this shit work in so many functions 
/*
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
*/


// norm por dos lineas
void    f_plus(int *i, const char *str, va_list arg, t_total *e)
{
    int holder;

//    *i = *i + 1;
    if (str[*i + 1] == 'd' || str[*i + 1] == 'i')
    {
        holder = va_arg(arg, int);
        if (holder >= 0)
        {
            ft_putchar('+');
            e->e = e->e + 1;
        }
        *i = *i + 1;
        ft_putnbrcont((long long)holder, e);
    }
//  suposse to handle flag zero, not sure about this, let se later REMINDER
    else if (str[*i + 1] == '0')
    {
        e->e = e->e + 1;
        ft_putchar('+');
        *i = *i + 1;
        f_zerodebug(i, str, arg, e);
    }

    else if (str[*i + 1] == '-')
        f_left(i, str, arg, e);
    else if (str[*i + 1] > '0' || str[*i + 1] <= '9')
    {
        *i = *i + 1;
        f_right(i, str, arg, e);
    }
    else
        flags_pen(i, str, arg, e);
}

/*
void    f_minus(int *i, char *str, va_list arg, t_total *e)
{

}
*/

void    f_left(int *i, const char *str, va_list arg, t_total *e)
{
    int holder;
    int check;

    holder = e->e;
    check = 0;
    e->wd = 0;
    *i = *i + 1;
    while (str[*i] >= '0' && str[*i] <= '9')
    {
        e->wd = (e->wd * 10) + (str[*i] - '0');
        e->e = e->e + 1;
        *i = *i + 1;
    }
// test only
    e->e = e->e + 1;
    *i = *i - 1;
    flags_pen(i, str, arg, e);
// actual len and then check if its okay
    if (e->wd > (e->e - holder))
    {
        check = e->wd - (e->e - holder);
        while (--check >= 0)
        {
            ft_putchar(' ');
            e->e = e->e + 1;
        }
    }
}