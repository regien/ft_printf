/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_leftalign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 21:44:35 by gmalpart          #+#    #+#             */
/*   Updated: 2018/03/24 06:56:33 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	f_plus_ints(int *i, const char *str, va_list arg, t_total *e)
{
	int	holder;

	holder = va_arg(arg, int);
	if (holder >= 0)
	{
		ft_putchar('+');
		e->e = e->e + 1;
	}
	*i = *i + 1;
	ft_putnbrcont((long long)holder, e);
}

void	f_plus(int *i, const char *str, va_list arg, t_total *e)
{
	if (str[*i + 1] == 'd' || str[*i + 1] == 'i')
		f_plus_ints(i, str, arg, e);
	else if (str[*i + 1] == '0')
	{
		e->e = e->e + 1;
		ft_putchar('+');
		*i = *i + 1;
		f_zerodebug(i, str, arg, e);
	}
	else if (str[*i + 1] == '-')
		f_left(i, str, arg, e);
	else if (str[*i + 1] > '0' || str[*i + 1] <= '9')
	{
		*i = *i + 1;
		f_right(i, str, arg, e);
	}
	else
		flags_pen(i, str, arg, e);
}

void	f_left(int *i, const char *str, va_list arg, t_total *e)
{
	int holder;
	int check;

	holder = e->e;
	check = 0;
	e->wd = 0;
	*i = *i + 1;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		e->wd = (e->wd * 10) + (str[*i] - '0');
		e->e = e->e + 1;
		*i = *i + 1;
	}
	e->e = e->e + 1;
	*i = *i - 1;
	flags_pen(i, str, arg, e);
	if (e->wd > (e->e - holder))
	{
		check = e->wd - (e->e - holder);
		while (--check >= 0)
		{
			ft_putchar(' ');
			e->e = e->e + 1;
		}
	}
}
