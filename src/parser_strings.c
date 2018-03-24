/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_strings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 04:08:50 by gmalpart          #+#    #+#             */
/*   Updated: 2018/03/24 06:48:27 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	f_hexa(va_list arguments, t_total *e)
{
	unsigned int	hold;

	hold = va_arg(arguments, unsigned int);
	print_hexa(hold, e);
	e->e = e->e - 2;
}

void	f_caphexa(va_list arguments, t_total *e)
{
	unsigned int	hold;

	hold = va_arg(arguments, unsigned int);
	print_caphexa(hold, e);
	e->e = e->e - 2;
}

void	f_pointadrs(va_list arguments, t_total *e)
{
	void			*out;
	unsigned long	adr;

	out = va_arg(arguments, void*);
	adr = (unsigned long)out;
	ft_putstr("0x");
	print_address(adr, e);
}

void	f_char(va_list arguments, t_total *e)
{
	char	hold;

	hold = (char)va_arg(arguments, int);
	ft_putchar(hold);
	e->e = ((e->e + 1) - 2);
}

void	f_str(va_list arguments, t_total *e)
{
	char *str;

	str = (char *)va_arg(arguments, char*);
	print_str(str, e);
}
