/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 21:10:39 by gmalpart          #+#    #+#             */
/*   Updated: 2018/01/27 13:56:15 by regien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int	ft_printf(char const *str, ...)
{
	int		i;
	int		e;
	va_list		arguments;

	e = 0;
	i = -1;
	va_start(arguments, str);
	while (str[++i])
	{
		if (str[i] == '%')
			flags_pen(&i, str, arguments, &e);
		else
			ft_putchar(str[i]);
	}
	va_end(arguments);
	return (e);
}

int main (void)
{
	int cac = 5;
	ft_printf("asdfg %d\n", cac);
	printf("%i\n", printf("qewadszcx"));
}
