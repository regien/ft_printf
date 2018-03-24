/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hh_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 04:42:04 by gmalpart          #+#    #+#             */
/*   Updated: 2018/03/24 06:07:31 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	f_hhhexa(va_list args, t_total *e)
{
	unsigned char	holder;

	holder = (unsigned char)va_arg(args, void*);
	ft_puthhhexa((unsigned int)holder, e);
	e->e = e->e - 4;
}

void	f_hhhexacap(va_list args, t_total *e)
{
	unsigned char	holder;

	holder = (unsigned char)va_arg(args, void*);
	ft_puthhhexacap((unsigned int)holder, e);
	e->e = e->e - 4;
}

void	f_hhoctal(va_list args, t_total *e)
{
	unsigned char	holder;

	holder = (unsigned char)va_arg(args, void*);
	ft_puthhoctal((unsigned int)holder, e);
	e->e = e->e - 4;
}

void	f_hhuint(va_list args, t_total *e)
{
	unsigned char	holder;

	holder = (unsigned char)va_arg(args, void*);
	ft_puthhuint((unsigned int)holder, e);
	e->e = e->e - 4;
}

void	f_hhint(va_list args, t_total *e)
{
	signed char		holder;

	holder = (signed char)va_arg(args, void*);
	ft_putnbrcont((long long)holder, e);
	e->e = e->e - 4;
}
