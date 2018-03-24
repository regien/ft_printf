/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 21:10:39 by gmalpart          #+#    #+#             */
/*   Updated: 2018/03/24 05:15:24 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(char const *str, ...)
{
	int		i;
	int		e;
	va_list		arguments;
	t_total	*total;

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


/*

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
// changing momentanery because of malfunction negatives
//	int flags = 45;
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

	printf("------------------ Integer z Cases -----------------------\n\n");

	printf("hexa = |%zx|\n", (size_t)flags3);
	ft_printf("hexa = |%zx|\n", (size_t)flags3);
	printf("HEXA = |%zX|\n", (size_t)flags3);
	ft_printf("HEXA = |%zX|\n", (size_t)flags3);
	printf("octal = |%zo|\n", (size_t)flags3);
	ft_printf("octal = |%zo|\n", (size_t)flags3);
	printf("uint = |%zu|\n", (size_t)flags3);
	ft_printf("uint = |%zu|\n", (size_t)flags3);
	printf("int = |%zi|\n", (size_t)flags3);
	ft_printf("int = |%zi|\n", (size_t)flags3);

	printf("------------------ Integer j Cases -----------------------\n\n");

	printf("hexa = |%jx|\n", (uintmax_t)flags3);
	ft_printf("hexa = |%jx|\n", (uintmax_t)flags3);
	printf("HEXA = |%jX|\n", (uintmax_t)flags3);
	ft_printf("HEXA = |%jX|\n", (uintmax_t)flags3);
	printf("octal = |%jo|\n", (uintmax_t)flags3);
	ft_printf("octal = |%jo|\n", (uintmax_t)flags3);
	printf("uint = |%ju|\n", (uintmax_t)flags3);
	ft_printf("uint = |%ju|\n", (uintmax_t)flags3);
	printf("int = |%ji|\n", (uintmax_t)flags3);
	ft_printf("int = |%ji|\n", (uintmax_t)flags3);

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

	unsigned int 		rngesus = 250;
	char				*roberto = "Lolapalloza";


	printf("------------------ Padders Cases -----------------------\n\n");

	printf("space cases = |% 15d|\n", -250);
	ft_printf("space cases = |% 15d|\n\n", -250);

	printf("numbers padders =      |%40d|\n", flags);
	ft_printf("numbers padders =      |%40d|\n", flags);
	printf("hexadecimalpadder = |%40x|\n", rngesus);
	ft_printf("hexadecimalpadder = |%40x|\n", rngesus);
	printf("hexadecimalpadder = |%40X|\n", rngesus);
	ft_printf("hexadecimalpadder = |%40X|\n", rngesus);
	printf("hexadecimal hash = |%#X|\n", rngesus);
	ft_printf("hexadecimal hash = |%#X|\n", rngesus);
	printf("hexadecimal hash = |%#x|\n", rngesus);
	ft_printf("hexadecimal hash = |%#x|\n", rngesus);
	printf("octal = |%40o|\n", rngesus);
	ft_printf("octal = |%40o|\n", rngesus);
	printf("unsigned shit = |%40u|\n", rngesus);
	ft_printf("unsigned shit = |%40u|\n", rngesus);
	printf("pointer address = |%40p|\n", roberto);
	ft_printf("pointer address = |%40p|\n", roberto);
	printf("caracter = |%40c|\n", 'a');
	ft_printf("caracter = |%40c|\n", 'a');
	printf("caracter %% = |%40%|\n");
	ft_printf("caracter %% = |%40%|\n");
	printf("weird integers  minus= |%-40d|\n", flags);
	printf("weird integers  plus = |%+40d|\n", flags);
	printf("weird integers  plus = |%+d|\n", flags);
	printf("weird integers  plus = |% 40d|\n", flags);
	printf("weird integers  minus= |% -40d|\n", flags);
// flag zero interaction with + 
	printf("weird testing thecero= |%040d|\n", flags);
	ft_printf("mine testing thecero = |%040d|\n", flags);
	printf("weird thecero with a+= |%0+40d|\n", flags);
	printf("weird integers  minus= |%+09d|\n", flags);
// this flags doesnt works on linux
	printf("capital O = |%O|\n", (unsigned int)flags);
	ft_printf("capital O = |%O|\n", (unsigned int)flags);
	printf("capital U = |%U|\n", (unsigned int)flags);
	ft_printf("capital U = |%U|\n", (unsigned int)flags);
	printf("capital D = |%D|\n", (unsigned int)flags);
	ft_printf("capital D = |%D|\n", (unsigned int)flags);


	printf("------------------ EXTRA Padders Cases -----------------------\n\n");
	printf("pendejada plus test = |%-40d|\n", 155);
	ft_printf("pendejada plus test = |%-40d|\n", 155);
	ft_printf("count test = |%d|\n", ft_printf("pendejada plus test = |%-40d|\n", 15));
	ft_printf("count test = |%d|\n", printf("pendejada plus test = |%-40d|\n", 15));

	printf("------------------ EXTRA Padders Cases -----------------------\n\n");

	printf("hexadecimal plus = |%+40x|\n", rngesus);
	ft_printf("hexadecimal plus = |%+40x|\n", rngesus);

	printf("edge case plus and cero = |%+04d|\n", 42);
	ft_printf("edge case plus and cero = |%+04d|\n", 42);
	printf("same edge case plus and cero = |%04i|\n", 42);
	ft_printf("same edge case plus and cero = |%04i|\n", 42);


	printf("pendejada = |%0+d|\n", 42);
	ft_printf("pendejada = |%0+d|\n", 42);

	printf("------------------ EXTRA Padders Cases -----------------------\n\n");

	// print null
	ft_printf("%ls", NULL);
	printf("%ls", NULL);

//	printf("pendejada plus test = |%+40s|\n", "pendejada");
//	ft_printf("pendejada plus test = |%+40s|\n", "pendejada");
//
//
}
*/
