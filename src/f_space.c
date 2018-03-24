/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_space.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 03:24:42 by gmalpart          #+#    #+#             */
/*   Updated: 2018/03/24 05:59:55 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	f_space(int *i, const char *str, va_list arg, t_total *e)
{
	int	holder;

	if (str[*i + 1] == 'd' || str[*i + 1] == 'i')
	{
		holder = va_arg(arg, int);
		if (holder >= 0)
		{
			e->e = e->e + 1;
			ft_putchar(' ');
		}
		*i = *i + 1;
		ft_putnbrcont((long long)holder, e);
	}
	else
		flags_pen(i, str, arg, e);
}

void	f_hash(int *i, const char *str, va_list arg, t_total *e)
{
	unsigned int	holder;

	if (str[*i + 1] == 'o')
	{
		*i = *i + 1;
		holder = va_arg(arg, unsigned int);
		e->e = e->e + 1;
		ft_putchar('0');
		if (holder != 0)
			ft_putnbroct(holder, e);
	}
	else if (str[*i + 1] == 'x')
	{
		e->e = e->e + 2;
		ft_putstr("0x");
		flags_pen(i, str, arg, e);
	}
	else if (str[*i + 1] == 'X')
	{
		e->e = e->e + 2;
		ft_putstr("0X");
		flags_pen(i, str, arg, e);
	}
}
