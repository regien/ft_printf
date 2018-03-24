/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_intfloat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 03:57:59 by gmalpart          #+#    #+#             */
/*   Updated: 2018/03/24 04:08:22 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		f_octal(va_list arguments, t_total *e)
{
	unsigned int	hold;

	hold = va_arg(arguments, unsigned int);
	ft_putnbroct(hold, e);
	e->e = e->e - 2;
}

void		f_uint(va_list arguments, t_total *e)
{
	unsigned int	nbr;

	nbr = va_arg(arguments, unsigned int);
	ft_putnbruint(nbr, e);
	e->e = e->e - 2;
}


void		f_int(va_list args, t_total *e)
{
	int	nbr;
	long long hold;
	
	nbr = va_arg(args, int);
	hold = (long long)nbr;
	ft_putnbrcont(nbr, e);
	e->e = e->e - 2;
}
