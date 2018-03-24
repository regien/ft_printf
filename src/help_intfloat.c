/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_intfloat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 17:00:02 by gmalpart          #+#    #+#             */
/*   Updated: 2018/03/24 04:08:23 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putnbroct(unsigned int hold, t_total *e)
{
	if (hold >= 8)
	{
		ft_putnbroct(hold / 8, e);
		ft_putnbroct(hold % 8, e);
	}
	else
	{
		e->e = e->e + 1;
		ft_putchar(hexstr[hold]);
	}
}

void		ft_putnbruint(unsigned int nbr, t_total *e)
{
	if (nbr >= 10)
	{
		ft_putnbruint(nbr / 10, e);
		ft_putnbruint(nbr % 10, e);
	}
	else
	{
		e->e = e->e + 1;
		ft_putchar(nbr + '0');
	}
}

void		ft_putnbrcont(long long nbr, t_total *e)
{
	if (nbr < 0)
	{
		e->e = e->e + 1;
		nbr = -nbr;
		ft_putchar('-');
	}
	if (nbr >= 10)
	{
		ft_putnbrcont(nbr / 10, e);
		ft_putnbrcont(nbr % 10, e);
	}
	if (nbr < 10)
	{
		e->e = e->e + 1;
		ft_putchar(nbr + '0');
	}
}

/*
** Base solution for integers.
*/

void		ft_putnbrbase(long long nbr, int base, t_total *e)
{
	if (nbr < 0)
	{
		e->e = e->e + 1;
		ft_putchar('-');
		nbr = nbr * -1;
	}
	if (nbr >= 10)
	{
		ft_putnbrbase(nbr / 10, base, e);
		ft_putnbrbase(nbr % 10, base, e);
	}
	if (nbr < 10)
	{
		e->e = e->e + 1;
		ft_putchar(hexstr[nbr]);
	}
}
