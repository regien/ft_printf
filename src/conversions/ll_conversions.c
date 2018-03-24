/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 23:07:31 by gmalpart          #+#    #+#             */
/*   Updated: 2018/03/24 06:14:37 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**  You can easily wrap this 4 functions in a base function and shrink the code
**  cannon in a classical song, good shit.
*/

void	f_llhexa(va_list args, t_total *e)
{
	unsigned long long	holder;

	holder = (unsigned long long)va_arg(args, void*);
	ft_putllhexa(holder, e);
	e->e = e->e - 4;
}

void	f_llhexacap(va_list args, t_total *e)
{
	unsigned long long	holder;

	holder = (unsigned long)va_arg(args, void*);
	ft_putllhexacap(holder, e);
	e->e = e->e - 4;
}

void	f_lloctal(va_list args, t_total *e)
{
	unsigned long long	holder;

	holder = (unsigned long)va_arg(args, void*);
	ft_putlloctal(holder, e);
	e->e = e->e - 4;
}

void	f_lluint(va_list args, t_total *e)
{
	unsigned long long	holder;

	holder = (unsigned long long)va_arg(args, void*);
	ft_putlluint(holder, e);
	e->e = e->e - 4;
}

void	f_llint(va_list args, t_total *e)
{
	long long	holder;

	holder = (long long)va_arg(args, void*);
	ft_putllint((long long)holder, e);
	e->e = e->e - 4;
}
