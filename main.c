/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 21:10:39 by gmalpart          #+#    #+#             */
/*   Updated: 2018/01/29 14:53:08 by gmalpart         ###   ########.fr       */
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
	int limit = -2147483648;
	unsigned int valor = 1848445;
	float vaina = 0;
	char *str = "pendejada";
	char *algo;
	char letra = 'p';
	char vacia;
//	unsigned long out;
	int flags = -45;
	int flags2 = 45;

//	out = (unsigned long)str;

	printf("------------------ Integer Cases -----------------------\n\n");
	printf("integer = |%i|\n", limit);
	ft_printf("integer = |%i|\n", limit);
	printf("double = |%d|\n", limit);
	ft_printf("double = |%d|\n", limit);
	printf("unsigned int = |%u|\n", valor);
	ft_printf("unsigned int = |%u|\n", valor);
	printf("octal = |%o|\n", valor);
	ft_printf("octal = |%o|\n", valor);
	printf("float = |%f|\n", vaina); 
//	ft_printf("float = |%f|\n", vaina); 
//	printf("string = |%s|\n", str);
	
	printf("------------------ Strings Cases -----------------------\n\n");
	ft_printf("vacio = |%s|\n", algo);
	ft_printf(" total = |%d|\n", ft_printf("my stuff = |%s|", str));

	printf("------------------ Characters Cases -----------------------\n\n");
	printf("char = |%c|\n", letra);
	printf("char = |%%%%%%|\n");
	printf("pointer address =\t|%p|\n", str);
	ft_printf("mine ptradrs =\t\t|%p|\n", str);
	ft_putchar('\n');
	printf("mine\n");
	ft_printf("char = |%c|\n", letra);
	ft_printf("char = |%%%%%%|\n");
	printf("hexadecimal = |%x|\n", flags);
	ft_printf("hexadecimal = |%x|\n", flags);
	printf("hexadecimal = |%x|\n", flags2);
	ft_printf("hexadecimal = |%x|\n", flags2);
	
	printf("hexadecimal = |%X|\n", flags);
	ft_printf("hexadecimal = |%X|\n", flags);
	printf("hexadecimal = |%X|\n", flags2);
	ft_printf("hexadecimal = |%X|\n", flags2);

//	printf("char vacio = |%c|\n", vacia);
//	printf("char vacio = |%d|\n", vacia);
	printf("------------------ Padders Cases -----------------------\n\n");
	printf("weird integers = |%+2d|\n", flags);
}
