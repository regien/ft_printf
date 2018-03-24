/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_numbers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 17:03:24 by regien            #+#    #+#             */
/*   Updated: 2018/03/24 02:57:17 by gmalpart         ###   ########.fr       */
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
