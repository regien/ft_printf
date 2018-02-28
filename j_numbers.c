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

int    len_unsignumber(unsigned int nbr, int base)
{
    int holder;

    holder = 1;
    while (nbr /= base)
        holder++;
    return (holder);
}

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

void        ft_putunbase(unsigned int nbr, int base, t_total *e)
{
    if (nbr >= base)
    {
        ft_putunbase(nbr / base, base, e);
        ft_putunbase(nbr % base, base, e);
    }
    if (nbr < base)
    {
        e->e = e->e + 1;
        ft_putchar(hexstr[nbr]);
    }
}

void        ft_putcapunbase(unsigned int nbr, int base, t_total *e)
{
    if (nbr >= base)
    {
        ft_putcapunbase(nbr / base, base, e);
        ft_putcapunbase(nbr % base, base, e);
    }
    if (nbr < base)
    {
        e->e = e->e + 1;
        ft_putchar(caphexstr[nbr]);
    }
}

void        f_alignrextra(int *i, char const *str, void* holder, t_total *e)
{
    unsigned long       addr;

    if (str[*i] == 's')
    {
        put_paddin(e, ft_strlen(str));
        print_str((char*)holder, e);
    }
    else if (str[*i] == 'c' || str[*i] == '%')
    {
        put_paddin(e, 1);
        e->e = e->e + 1;
        str[*i] == 'c' ? ft_putchar('c') : 0;
        str[*i] == '%' ? ft_putchar('%') : 0;
    }
    else if (str[*i] == 'p')
    {
        put_paddin(e, 14);
        addr = (unsigned long)holder;
        ft_putstr("0x7ff");
        e->e = e->e + 5;
        print_address(addr, e);
    }
}

void        f_alignr(int *i, char const *str, va_list arg, t_total *e)
{
    void    *holder;
    int     holdint;

    holdint = 0;
    holder = va_arg(arg, void*);
    if (str[*i] == 'd' || str[*i] == 'i')
    {
        holdint = (int)holder;
        put_paddin(e, len_number((int)holder, 10));
        ft_putnbrbase((long long)holdint, 10, e);
    }
    else if (str[*i] == 'u' || str[*i] == 'o' || str[*i] == 'x' \
        || str[*i] == 'X')
    {
        // pseudo base
        str[*i] == 'u' ? holdint = 10 : 0;
        str[*i] == 'o' ? holdint = 8 : 0;
        str[*i] == 'x' || str[*i] == 'X' ? holdint = 16 : 0;
        put_paddin(e, len_unsignumber((unsigned int)holder, holdint));
        str[*i] == 'u' ? ft_putunbase((unsigned int)holder, 10, e) : 0;
        str[*i] == 'o' ? ft_putunbase((unsigned int)holder, 8, e) : 0;
        str[*i] == 'x' ? ft_putunbase((unsigned int)holder, 16, e) : 0;
        str[*i] == 'X' ? ft_putcapunbase((unsigned int)holder, 16, e) : 0;
    }
    f_alignrextra(i, str, holder, e);
    // extra cases 
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
    f_alignr(i, str, arg, e);
}

//void        f_numbers()