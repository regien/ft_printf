/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 21:10:39 by gmalpart          #+#    #+#             */
/*   Updated: 2018/02/19 18:19:32 by regien           ###   ########.fr       */
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
	int flags3 = 250;
	wchar_t wide = 0x061 << 1;	
	wchar_t *stringwide = L"Hello world";

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

	printf("just checking printf values\n");
	printf("ft_printf = |%d|\n", ft_printf("integer = |%i| ", limit)); 
	ft_printf("printf = |%d|\n", printf("integer = |%i| \n", limit));
	
	printf("------------------ Integer hh Cases -----------------------\n\n");

	printf("integer = |%hhi|\n", (signed char)limit);
	ft_printf("integer = |%hhi|\n", (signed char)limit);
	printf("double = |%hhd|\n", (signed char)limit);
	ft_printf("double = |%hhd|\n", (signed char)limit);
	printf("hexa = |%hhx|\n", (unsigned char)flags3);
	ft_printf("hexa = |%hhx|\n", (unsigned char)flags3);
	printf("HEXA = |%hhX|\n", (unsigned char)flags3);
	ft_printf("HEXA = |%hhX|\n", (unsigned char)flags3);
	printf("octal = |%hho|\n", (unsigned char)flags3);
	ft_printf("octal = |%hho|\n", (unsigned char)flags3);
	printf("uint = |%hhu|\n", (unsigned char)flags3);
	ft_printf("uint = |%hhu|\n", (unsigned char)flags3);
	printf("int = |%hhd|\n", (signed char)flags3);
	ft_printf("int = |%hhd|\n", (signed char)flags3);

	printf("------------------ Integer h Cases -----------------------\n\n");

	printf("hexa = |%hx|\n", (unsigned short)flags3);
	ft_printf("hexa = |%hx|\n", (unsigned short)flags3);
	printf("hexa = |%hX|\n", (unsigned short)flags3);
	ft_printf("hexa = |%hX|\n", (unsigned short)flags3);
	printf("hexa = |%ho|\n", (unsigned short)flags3);
	ft_printf("hexa = |%ho|\n", (unsigned short)flags3);
	printf("uint = |%hu|\n", (unsigned short)flags3);
	ft_printf("uint = |%hu|\n", (unsigned short)flags3);
	printf("d flag = |%hd|\n", (unsigned short)flags3);
	ft_printf("d flag = |%hd|\n", (unsigned short)flags3);
	printf("integer = |%hi|\n", (unsigned short)flags3);
	ft_printf("integer = |%hi|\n", (unsigned short)flags3);
	
	printf("------------------ Integer l Cases -----------------------\n\n");

	printf("hexa = |%lx|\n", (unsigned long)flags3);
	ft_printf("hexa = |%lx|\n", (unsigned long)flags3);
	printf("HEXA = |%lX|\n", (unsigned long)flags3);
	ft_printf("HEXA = |%lX|\n", (unsigned long)flags3);
	printf("Uint = |%lu|\n", (unsigned long)flags3);
	ft_printf("uint = |%lu|\n", (unsigned long)flags3);
	printf("Octal = |%lo|\n", (unsigned long)flags3);
	ft_printf("OCtal = |%lo|\n", (unsigned long)flags3);
	printf("integer = |%ld|\n", (long)flags3);
	ft_printf("integer = |%ld|\n", (long)flags3);

	printf("------------------ Integer ll Cases -----------------------\n\n");

	printf("hexa = |%llx|\n", (unsigned long long)flags3);
	ft_printf("hexa = |%llx|\n", (unsigned long long)flags3);
	printf("HEXA = |%llX|\n", (unsigned long long)flags3);
	ft_printf("HEXA = |%llX|\n", (unsigned long long)flags3);
	printf("octal = |%llo|\n", (unsigned long long)flags3);
	ft_printf("octal = |%llo|\n", (unsigned long long)flags3);
	printf("uint = |%llu|\n", (unsigned long long)flags3);
	ft_printf("uint = |%llu|\n", (unsigned long long)flags3);
	printf("dint = |%lld|\n", (long long)flags3);
	ft_printf("dint = |%lld|\n", (long long)flags3);

	printf("------------------ Strings Cases -----------------------\n\n");
	ft_printf("vacio = |%s|\n", algo);
	ft_printf(" total = |%d|\n", ft_printf("my stuff = |%s|", str));
	printf("string wide char = |%ls|\n", stringwide);
	ft_printf("string wide char = |%ls|\n", stringwide);
	printf("string without l wide char = |%S|\n", stringwide);
	ft_printf("string without l wide char = |%S|\n", stringwide);

	printf("------------------ Characters Cases -----------------------\n\n");
	printf("char = |%c|\n", letra);
	printf("char = |%%%%%%|\n");
	printf("pointer address =\t|%p|\n", str);
	ft_printf("mine ptradrs =\t\t|%p|\n", str);
	ft_putchar('\n');
	printf("mine\n");
	ft_printf("char = |%c|\n", letra);
	ft_printf("char = |%%%%%%|\n");
	printf("wide char = |%C|\n", wide);
	ft_printf("wide char = |%C|\n", wide);
	printf("lwide char = |%lc|\n", wide);
	ft_printf("lwide char = |%lc|\n", wide);


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
	printf("weird integers  minus= |%-40d|\n", flags);
	printf("weird integers  plus = |%+40d|\n", flags);
	printf("weird integers  plus = |% 40d|\n", flags);
	printf("weird integers  minus= |% -40d|\n", flags);
	printf("weird integers  minus= |%+09d|\n", flags);
}
