/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hh_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 04:42:04 by gmalpart          #+#    #+#             */
/*   Updated: 2018/02/21 04:42:06 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

/// ------------- HH CONVERSION ----------------


void	ft_puthhhexa(unsigned int nbr, int *e)
{
	if (nbr > 15)
	{
		ft_puthhhexa(nbr / 16, e);
		ft_puthhhexa(nbr % 16, e);
	}
	else
	{
		*e = *e + 1;
		ft_putchar(hexstr[nbr]);
	}
}

void	f_hhhexa(va_list args, int *e)
{
	unsigned char	holder;
	
	holder = (unsigned char)va_arg(args, void*);
	ft_puthhhexa((unsigned int)holder, e);
	*e = *e - 4;
}

void	ft_puthhhexacap(unsigned int nbr, int *e)
{
	if (nbr > 15)
	{
		ft_puthhhexacap(nbr / 16, e);
		ft_puthhhexacap(nbr % 16, e);
	}
	else
	{
		*e = *e + 1;
		ft_putchar(caphexstr[nbr]);
	}
}

void	f_hhhexacap(va_list args, int *e)
{
	unsigned char	holder;
	
	holder = (unsigned char)va_arg(args, void*);
	ft_puthhhexacap((unsigned int)holder, e);
	*e = *e - 4;
}

void		ft_puthhoctal(unsigned int hold, int *e)
{
	if (hold >= 10)
	{
		ft_puthhoctal(hold / 8, e);
		ft_puthhoctal(hold % 8, e);
	}
	else
	{
		*e = *e + 1;
		ft_putchar(hold + '0');
	}
}

void	f_hhoctal(va_list args, int *e)
{
	unsigned char	holder;
	
	holder = (unsigned char)va_arg(args, void*);
	ft_puthhoctal((unsigned int)holder, e);
	*e = *e - 4;
}

void		ft_puthhuint(unsigned int nbr, int *e)
{
	if (nbr >= 10)
	{
        ft_puthhuint(nbr / 10, e);
		ft_puthhuint(nbr % 10, e);
	}
	else
	{
		*e = *e + 1;
		ft_putchar(nbr + '0');
	}
}

void	f_hhuint(va_list args, int *e)
{
	unsigned char	holder;

	holder = (unsigned char)va_arg(args, void*);
	ft_puthhuint((unsigned int)holder, e);
	*e = *e - 4;
}

void	f_hhint(va_list args, int *e)
{
	signed char	holder;

	holder = (signed char)va_arg(args, void*);
	ft_putnbrcont((long long)holder, e);
	*e = *e - 4;
}