/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_strings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 00:06:40 by gmalpart          #+#    #+#             */
/*   Updated: 2018/03/24 04:31:43 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	hexstr[] = "0123456789abcdef";
char	caphexstr[] = "0123456789ABCDEF";

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

void	f_per(t_total *e)
{
	ft_putchar('%');
	e->e = ((e->e + 1) - 2);
}
