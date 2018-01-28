/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 21:10:39 by gmalpart          #+#    #+#             */
/*   Updated: 2018/01/28 01:06:45 by gmalpart         ###   ########.fr       */
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
	return (i + e);
}

int main (void)
{
	int cac = 5;
	float vaina = 0;
	char *str = "pendejada";
	char *algo;
	char letra = 'p';
	char vacia;

	int flags = -45;


	ft_printf("asdfg %d\n", cac);
	printf("integer = |%i|\n", printf("qewadszcx"));
	printf("float = |%f|\n", vaina); 
	printf("string = |%s|\n", str);
	
	printf("------------------ Strings Cases -----------------------\n\n");
	ft_printf("vacio = |%s|\n", algo);
	ft_printf(" total = |%d|\n", ft_printf("my stuff = |%s|", str));

	printf("------------------ Characters Cases -----------------------\n\n");
	printf("char = |%c|\n", letra);
	printf("char = |%%|\n");
	printf("mine\n");
	ft_printf("char = |%c|\n", letra);
	ft_printf("char = |%%|\n");
//	printf("char vacio = |%c|\n", vacia);
//	printf("char vacio = |%d|\n", vacia);
	printf("------------------ Characters Cases -----------------------\n\n");
	printf("weird integers = |%+d|", flags);
}
