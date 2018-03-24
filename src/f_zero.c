/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_zero.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 20:54:40 by gmalpart          #+#    #+#             */
/*   Updated: 2018/03/24 05:52:44 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**  printing zeros
**  changing part : relations with flag '+' it should
**  fail with any ohter flag
*/

int		len_number(int nbr, int base)
{
	int		holder;
	long	ringo;

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

void	f_putzeros(t_total *e, int size)
{
	int	vaina;

	vaina = 0;
	if (e->wd > size)
	{
		vaina = e->wd - size;
		while (--vaina >= 0)
		{
			ft_putchar('0');
			e->e = e->e + 1;
		}
	}
}

void	f_zeroleft(int *i, const char *str, va_list arg, t_total *e)
{
	int	holdint;

	holdint = (int)va_arg(arg, int);
	if (str[*i] == 'd' || str[*i] == 'i')
	{
		f_putzeros(e, len_number((int)holdint, 10));
		ft_putnbrcont((long long)holdint, e);
	}
}

void	f_zero(int *i, char const *str, va_list arg, t_total *e)
{
	e->wd = 0;
	if (str[*i + 1] == '+')
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
			*i += 1;
		}
		f_zeroleft(i, str, arg, e);
	}
}
