/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_zero.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 20:54:40 by gmalpart          #+#    #+#             */
/*   Updated: 2018/03/24 05:15:00 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**  printing zeros
**  changing part : relations with flag '+' it should
**  fail with any ohter flag
*/

int     len_number(int nbr, int base)
{
    int   holder;
    long    ringo;    

    ringo = nbr;
    holder = 1;
    if (ringo < 0)
    {
        ringo = ringo * -1;
        holder++;
    }
    while (ringo /= base)
        holder++;
    return (holder);
}


void    f_putzeros(t_total *e, int size)
{
    int vaina;
    
    vaina = 0;
 //       printf("\ne->wd = |%d| \n", e->wd);
 //       printf("\nsize = |%d| \n", size);
    if (e->wd > size)
    {
        vaina = e->wd - size;
 //       printf("vaina = |%d| \n", vaina);
        while (--vaina >= 0)
        {
            ft_putchar('0');
            e->e = e->e + 1;
        }
    }
}

// TEST FUNCTION ONLY
void    ft_putintcont(int n, t_total *e)
{
	if (n < 0)
	{
		e->e = e->e + 1;
		ft_putchar('-');
		n = -n;
	}
	if (n == -2147483648)
	{
		ft_putchar('2');
		n %= 1000000000;
		n = -n;
	}
	if (n >= 10)
	{
		ft_putintcont((n / 10), e);
		ft_putintcont((n % 10), e);
	}
	else
	{
		e->e = e->e + 1;
		ft_putchar(n + '0');
	}
}


void    f_zeroleft(int *i, const char *str, va_list arg, t_total *e)
{
//    void    *holder;
    int     holdint;

//    holder = va_arg(arg, void*);
    holdint = (int)va_arg(arg, int);
    if(str[*i] == 'd' || str[*i] == 'i')
    {
       f_putzeros(e, len_number((int)holdint, 10));
//       ft_putnbrbase((long long)holdint, 10, e);
//
//        ft_putintcont(holdint, e);
		ft_putnbrcont((long long)holdint, e);
    }
}



void    f_zero(int *i, char const *str, va_list arg, t_total *e)
{

    e->wd = 0;
    // flag + suppose to be here,  i think is not neccesary
    // UPDATE DEBUGGING flag + 
    if (str[*i + 1 ] == '+')
    {
        *i = *i + 1;
        f_plus(i, str, arg, e);
    }
    else
    {
        while (str[*i] >= '0' && str[*i] <= '9')
        {
            if (str[*i] >= '0' && str[*i] <= '9')
                e->wd = (e->wd * 10) + (str[*i] - '0');
    //        printf("word count = |%d| \n", e->wd);
            *i += 1;
        }
       f_zeroleft(i, str, arg, e);
    }
//      changed not staged
    
}

void    f_zeroleftdebug(int *i, char const *str, va_list arg, t_total *e)
{
    int    holder;
    
    holder = va_arg(arg, int);
//    e->wd = e->wd + 1;
    if (str[*i] == 'd' || str[*i] == 'i')
    {
        f_putzeros(e, (len_number(holder, 10) + 1));
        ft_putnbr(holder);
    }
}

void    f_zerodebug(int *i, char const *str, va_list arg, t_total *e)
{
        e->wd = 0;
        while (str[*i] >= '0' && str[*i] <= '9')
        {
            if (str[*i] >= '0' && str[*i] <= '9')
                e->wd = (e->wd * 10) + (str[*i] - '0');
            *i = *i + 1;
        }
        f_zeroleftdebug(i, str, arg, e);
}
