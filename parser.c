/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 13:27:02 by regien            #+#    #+#             */
/*   Updated: 2018/01/27 13:54:58 by regien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void		flags_pen(int *i, char const *str, va_list arguments, int *e)
{
	*i++;
	str[*i] == 'd' ? f_int(arguments, e) : 0;
}

void		f_int(va_list args, int *p)
{
	int	nbr;

	nbr = va_arg(args, int);
	ft_putnbr(nbr);
}
