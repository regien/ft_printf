/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 21:10:39 by gmalpart          #+#    #+#             */
/*   Updated: 2018/03/24 07:36:01 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(char const *str, ...)
{
	int			i;
	int			e;
	va_list		arguments;
	t_total		*total;

	total = ft_memalloc(sizeof(t_total));
	total->e = 0;
	total->wd = 0;
	i = -1;
	va_start(arguments, str);
	while (str[++i])
	{
		if (str[i] == '%')
			flags_pen(&i, str, arguments, total);
		else
			ft_putchar(str[i]);
	}
	va_end(arguments);
	e = total->e;
	free(total);
	return (i + e);
}
