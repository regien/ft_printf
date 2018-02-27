/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 23:07:31 by gmalpart          #+#    #+#             */
/*   Updated: 2018/02/21 23:07:46 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**  You can easily wrap this 4 functions in a base function and shrink the code
**  cannon in a classical song, good shit.
*/
void	ft_putllhexa(unsigned long long nbr, t_total *e)
{
	if (nbr > 15)
	{
		ft_putllhexa(nbr / 16, e);
		ft_putllhexa(nbr % 16, e);
	}
	else
	{
		e->e = e->e + 1;
		ft_putchar(hexstr[nbr]);
	}
}

void    f_llhexa(va_list args, t_total *e)
{
    unsigned long long  holder;

    holder = (unsigned long long)va_arg(args, void*);
	ft_putllhexa(holder, e);
	e->e = e->e - 4;
}

void	ft_putllhexacap(unsigned long long nbr, t_total *e)
{
	if (nbr > 15)
	{
		ft_putllhexacap(nbr / 16, e);
		ft_putllhexacap(nbr % 16, e);
	}
	else
	{
		e->e = e->e + 1;
		ft_putchar(caphexstr[nbr]);
	}
}

void    f_llhexacap(va_list args, t_total *e)
{
	unsigned long long  holder;

    holder = (unsigned long)va_arg(args, void*);
    ft_putllhexacap(holder, e);
	e->e = e->e - 4;
}

void	ft_putlloctal(unsigned long long nbr, t_total *e)
{
	if (nbr > 7)
	{
		ft_putlloctal(nbr / 8, e);
		ft_putlloctal(nbr % 8, e);
	}
	else
	{
		e->e = e->e + 1;
		ft_putchar(hexstr[nbr]);
	}
}

void    f_lloctal(va_list args, t_total *e)
{
    unsigned long long  holder;
    
    holder = (unsigned long)va_arg(args, void*);
    ft_putlloctal(holder, e);
	e->e = e->e - 4;
}


void	ft_putlluint(unsigned long long nbr, t_total *e)
{
	if (nbr >= 10)
	{
		ft_putlluint(nbr / 10, e);
		ft_putlluint(nbr % 10, e);
	}
	else
	{
		e->e = e->e + 1;
		ft_putchar(hexstr[nbr]);
	}
}

void    f_lluint(va_list args, t_total *e)
{
    unsigned long long    holder;

    holder = (unsigned long long)va_arg(args, void*);
    ft_putlluint(holder, e);
	e->e = e->e - 4;
}

void	ft_putllint(long long nbr, t_total *e)
{
	if (nbr >= 10)
	{
		ft_putllint(nbr / 10, e);
		ft_putllint(nbr % 10, e);
	}
	else
	{
		e->e = e->e + 1;
		ft_putchar(hexstr[nbr]);
	}
}

void    f_llint(va_list args, t_total *e)
{
    long long   holder;

    holder = (long long)va_arg(args, void*);
    ft_putllint((long long)holder, e);
	e->e = e->e - 4;
}