/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_strings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 00:06:40 by gmalpart          #+#    #+#             */
/*   Updated: 2018/01/29 15:00:09 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	hexstr[] = "0123456789abcdef";
char	caphexstr[] = "0123456789ABCDEF";

//			HEXADECIMAL PRINT

void	f_hexa(va_list arguments, t_total *e)
{
	unsigned int	hold;

	hold = va_arg(arguments, unsigned int);
	print_hexa(hold, e);
	e->e = e->e - 2;
}

void	print_hexa(unsigned int nbr, t_total *e)
{
	if (nbr > 15)
	{
		print_hexa(nbr / 16, e);
		print_hexa(nbr % 16, e);
	}
	else
	{
		e->e = e->e + 1;
		ft_putchar(hexstr[nbr]);
	}
}

void	f_caphexa(va_list arguments, t_total *e)
{
	unsigned int	hold;

	hold = va_arg(arguments, unsigned int);
	print_caphexa(hold, e);
	e->e = e->e - 2;
}

void	print_caphexa(unsigned int nbr, t_total *e)
{
	if (nbr > 15)
	{
		print_caphexa(nbr / 16, e);
		print_caphexa(nbr % 16, e);
	}
	else
	{
		e->e = e->e + 1;
		ft_putchar(caphexstr[nbr]);
	}
}

//			POINTER ADDRESS


void	f_pointadrs(va_list arguments, t_total *e)
{
	void	*out;
	unsigned long	adr;
	
	out = va_arg(arguments, void*);
	adr = (unsigned long)out;
	ft_putstr("0x");
	print_address(adr, e);
}

void	print_address(unsigned long adr, t_total *e)
{
	if(adr > 15)
	{
		print_address(adr / 16, e);
		print_address(adr % 16, e);
	}
	else
	{
		e->e = e->e + 1;
		ft_putchar(hexstr[adr]);
	}
}


// CHAR - Single one

void	f_char(va_list arguments, t_total *e)
{
	char	hold;

	hold = (char)va_arg(arguments, int);
	ft_putchar(hold);
//	if (hold <= 0)
//		e->e = ((e->e) - 2);
//	else
		e->e = ((e->e + 1) - 2);
}
// 			single  %
void	f_per(t_total *e)
{
	ft_putchar('%');
	e->e = ((e->e + 1) - 2);
}


// CHAR STRING

void	f_str(va_list arguments, t_total *e)
{
	char *str;

	str = (char *)va_arg(arguments, char*);
	print_str(str, e);
}

void	print_str(char *str, t_total *e)
{
	if (str)
	{
		ft_putstr(str);
		e->e = ((e->e + ft_strlen(str)) - 2);
	}
	else
		ft_putstr("(null)");
}

/// WIDE CHAR

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

	if (str[*i] ==  'S' || str[*i + 1] == 's')
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