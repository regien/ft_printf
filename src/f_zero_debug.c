/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_zero_debug.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 05:40:05 by gmalpart          #+#    #+#             */
/*   Updated: 2018/03/24 05:57:56 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	f_zeroleftdebug(int *i, char const *str, va_list arg, t_total *e)
{
	int	holder;

	holder = va_arg(arg, int);
	if (str[*i] == 'd' || str[*i] == 'i')
	{
		f_putzeros(e, (len_number(holder, 10) + 1));
		ft_putnbr(holder);
	}
}

void	f_zerodebug(int *i, char const *str, va_list arg, t_total *e)
{
	e->wd = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		if (str[*i] >= '0' && str[*i] <= '9')
			e->wd = (e->wd * 10) + (str[*i] - '0');
		*i = *i + 1;
	}
	f_zeroleftdebug(i, str, arg, e);
}
