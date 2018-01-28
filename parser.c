/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 13:27:02 by regien            #+#    #+#             */
/*   Updated: 2018/01/28 00:36:14 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void		flags_pen(int *i, char const *str, va_list arguments, int *e)
{
	*i = *i + 1;
	str[*i] == 'd' ? f_int(arguments, e) : 0;


// strings
	str[*i] == 's' ? f_str(arguments, e) : 0;

	str[*i] == 'c' ? f_char(arguments, e) : 0;
	str[*i] == '%' ? f_per(e) : 0;

	//str[*i] == 'S' ? f_capstr(argumens, e) : 0;
}

void		f_int(va_list args, int *p)
{
	int	nbr;

	nbr = va_arg(args, int);
	ft_putnbr(nbr);
}
