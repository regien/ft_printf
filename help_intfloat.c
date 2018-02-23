/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_intfloat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 17:00:02 by gmalpart          #+#    #+#             */
/*   Updated: 2018/01/29 15:35:51 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** INTEGERS
** %i / %d these are integers as well
*/


/*
void		f_doub(va_list arguments, int *e)
{
	double	nbr;
	long long	hold;

	nbr = va_arg(arguments, double);
	hold = (long long)nbr;
	ft_putnbrcont(nbr, e);
	*e = *e - 2;
}
*/

// %o - OCTAL cases

void		f_octal(va_list arguments, t_total *e)
{
	unsigned int	hold;

	hold = va_arg(arguments, unsigned int);
	ft_putnbroct(hold, e);
	e->e = e->e - 2;
}

void		ft_putnbroct(unsigned int hold, t_total *e)
{
	if (hold >= 10)
	{
		ft_putnbroct(hold / 8, e);
		ft_putnbroct(hold % 8, e);
	}
	else
	{
		e->e = e->e + 1;
		ft_putchar(hold + '0');
	}
}

// UITENGERS cases

void		f_uint(va_list arguments, t_total *e)
{
	unsigned int	nbr;

	nbr = va_arg(arguments, unsigned int);
	ft_putnbruint(nbr, e);
	e->e = e->e - 2;
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

// INTEGERS cases

void		f_int(va_list args, t_total *e)
{
	int	nbr;
	long long hold;
	
	nbr = va_arg(args, int);
	hold = (long long)nbr;
	ft_putnbrcont(nbr, e);
	e->e = e->e - 2;
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



// PUTNBR BASE
// refactorize it wit everything that is above in order to shorten the code

char	hexlen[] = "0123456789abcdef";
//char	caphexstr[] = "0123456789ABCDEF";

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
