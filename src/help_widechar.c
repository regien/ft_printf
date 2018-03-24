/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_widechar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 04:22:22 by gmalpart          #+#    #+#             */
/*   Updated: 2018/03/24 06:05:36 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	f_widechar(const char *str, int *i, va_list arguments, t_total *e)
{
	void *holder;

	if (str[*i] == 'C' || str[*i + 1] == 'c')
	{
		if (str[*i] == 'l')
		{
			*i = *i + 1;
			e->e = e->e - 3;
		}
		else
			e->e = e->e - 2;
		holder = va_arg(arguments, void*);
		e->e = e->e + 1;
		ft_putchar((char)holder);
	}
	else
		f_widestr(str, i, arguments, e);
}

void	ft_putstrwide(wchar_t *str, t_total *e)
{
	int i;

	i = -1;
	while (str[++i])
	{
		write(1, &str[i], 1);
		e->e = e->e + 1;
	}
}

void	f_widestr(const char *str, int *i, va_list arguments, t_total *e)
{
	wchar_t		*holder;

	if (str[*i] == 'S' || str[*i + 1] == 's')
	{
		if (str[*i] == 'l')
		{
			*i = *i + 1;
			e->e = e->e - 3;
		}
		else
			e->e = e->e - 2;
		holder = va_arg(arguments, wchar_t*);
		if (holder != NULL)
			ft_putstrwide(holder, e);
	}
}
