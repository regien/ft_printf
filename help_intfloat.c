/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_intfloat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 17:00:02 by gmalpart          #+#    #+#             */
/*   Updated: 2018/01/29 14:44:22 by gmalpart         ###   ########.fr       */
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

void		f_octal(va_list arguments, int *e)
{
	unsigned int	hold;

	hold = va_arg(arguments, unsigned int);
	ft_putnbroct(hold, e);
	*e = *e - 2;
}

void		ft_putnbroct(unsigned int hold, int *e)
{
	if (hold >= 10)
	{
		ft_putnbroct(hold / 8, e);
		ft_putnbroct(hold % 8, e);
	}
	else
	{
		*e = *e + 1;
		ft_putchar(hold + '0');
	}
}

// UITENGERS cases

void		f_uint(va_list arguments, int *e)
{
	unsigned int	nbr;

	nbr = va_arg(arguments, unsigned int);
	ft_putnbruint(nbr, e);
	*e = *e - 2;
}

void		ft_putnbruint(unsigned int nbr, int *e)
{
	if (nbr >= 10)
	{
		ft_putnbruint(nbr / 10, e);
		ft_putnbruint(nbr % 10, e);
	}
	else
	{
		*e = *e + 1;
		ft_putchar(nbr + '0');
	}
}

// INTEGERS cases

void		f_int(va_list args, int *e)
{
	int	nbr;
	long long hold;
	
	nbr = va_arg(args, int);
	hold = (long long)nbr;
	ft_putnbrcont(nbr, e);
	*e = *e - 2;
}

void		ft_putnbrcont(long long nbr, int *e)
{
	if (nbr < 0)
	{
		*e = *e + 1;
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
		*e = *e + 1;
		ft_putchar(nbr + '0');
	}
}



// PUTNBR BASE

char	hexlen[] = "0123456789abcdef";
//char	caphexstr[] = "0123456789ABCDEF";

void		ft_putnbrbase(long long nbr, int base, int *e)
{
	if (nbr < 0)
	{
		*e = *e + 1;
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
		*e = *e + 1;
		ft_putchar(hexlen[nbr]);
	}
}
