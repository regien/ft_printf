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

void	f_hexa(va_list arguments, int *e)
{
	unsigned int	hold;

	hold = va_arg(arguments, unsigned int);
	print_hexa(hold, e);
	*e = *e - 2;
}

void	print_hexa(unsigned int nbr, int *e)
{
	if (nbr > 15)
	{
		print_hexa(nbr / 16, e);
		print_hexa(nbr % 16, e);
	}
	else
	{
		*e = *e + 1;
		ft_putchar(hexstr[nbr]);
	}
}

void	f_caphexa(va_list arguments, int *e)
{
	unsigned int	hold;

	hold = va_arg(arguments, unsigned int);
	print_caphexa(hold, e);
	*e = *e - 2;
}

void	print_caphexa(unsigned int nbr, int *e)
{
	if (nbr > 15)
	{
		print_caphexa(nbr / 16, e);
		print_caphexa(nbr % 16, e);
	}
	else
	{
		*e = *e + 1;
		ft_putchar(caphexstr[nbr]);
	}
}

//			POINTER ADDRESS


void	f_pointadrs(va_list arguments, int *e)
{
	void	*out;
	unsigned long	adr;
	
	out = va_arg(arguments, void*);
	adr = (unsigned long)out;
	ft_putstr("0x");
	print_address(adr, e);
}

void	print_address(unsigned long adr, int *e)
{
	if(adr > 15)
	{
		print_address(adr / 16, e);
		print_address(adr % 16, e);
	}
	else
	{
		*e = *e + 1;
		ft_putchar(hexstr[adr]);
	}
}


// CHAR - Single one

void	f_char(va_list arguments, int *e)
{
	char	hold;

	hold = va_arg(arguments, int);
	ft_putchar(hold);
	if (hold <= 0)
		*e = ((*e) - 2);
	else
		*e = ((*e + 1) - 2);
}
// 			single  %
void	f_per(int *e)
{
	ft_putchar('%');
	*e = ((*e + 1) - 2);
}


// CHAR STRING

void	f_str(va_list arguments, int *e)
{
	char *str;

	str = va_arg(arguments, char*);
	print_str(str, e);
}

void	print_str(char *str, int *e)
{
	if (str)
	{
		ft_putstr(str);
		*e = ((*e + ft_strlen(str)) - 2);
	}
	else
		ft_putstr("(null)");
}

/// WIDE CHAR

void	f_widechar(const char *str, int *i, va_list arguments, int *e)
{
	void *holder;

	if (str[*i] == 'C' || str[*i + 1] == 'c')
	{
		if (str[*i] == 'l')
		{
			*i = *i + 1;
			*e = *e - 3;
		}
		else
			*e = *e - 2;
		holder = va_arg(arguments, void*);
		*e = *e + 1;
		ft_putchar((char)holder);
	}
	else
		f_widestr(str, i, arguments, e);
}

void	ft_putstrwide(wchar_t *str, int *e)
{
		int i;

		i = -1;
		while (str[++i])
		{
			ft_putchar(str[i]);
			*e = *e + 1;
		}
}

void	f_widestr(const char *str, int *i, va_list arguments, int *e)
{
	wchar_t		*holder;

	if (str[*i] ==  'S' || str[*i + 1] == 's')
		{
			if (str[*i] == 'l')
			{
				*i = *i + 1;
				*e = *e - 3;
			}
			else
				*e = *e - 2;
			holder = va_arg(arguments, wchar_t*);
			if (holder != NULL)
				ft_putstrwide(holder, e);
		}
}

/// ------------- HH CONVERSION ----------------


void	ft_puthhhexa(unsigned int nbr, int *e)
{
	if (nbr > 15)
	{
		print_hexa(nbr / 16, e);
		print_hexa(nbr % 16, e);
	}
	else
	{
		*e = *e + 1;
		ft_putchar(hexstr[nbr]);
	}
}

void	f_hhhexa(va_list args, int *e)
{
	unsigned char	holder;
	
	holder = (unsigned char)va_arg(args, void*);
	ft_puthhhexa((unsigned int)holder, e);
	*e = *e - 4;
}

void	ft_puthhhexacap(unsigned int nbr, int *e)
{
	if (nbr > 15)
	{
		print_hexa(nbr / 16, e);
		print_hexa(nbr % 16, e);
	}
	else
	{
		*e = *e + 1;
		ft_putchar(caphexstr[nbr]);
	}
}
void	f_hhhexacap(va_list args, int *e)
{
	unsigned char	holder;
	
	holder = (unsigned char)va_arg(args, void*);
	ft_puthhhexacap((unsigned int)holder, e);
	*e = *e - 4;
}