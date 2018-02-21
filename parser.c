/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 13:27:02 by regien            #+#    #+#             */
/*   Updated: 2018/01/28 07:52:17 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void		flags_pen(int *i, char const *str, va_list arguments, int *e)
{
	*i = *i + 1;
	str[*i] == 'd' ? f_int(arguments, e) : 0;
	str[*i] == 'i' ? f_int(arguments, e) : 0;
	str[*i] == 'u' ? f_uint(arguments, e) : 0;
	str[*i] == 'o' ? f_octal(arguments, e) : 0;

// strings
	str[*i] == 's' ? f_str(arguments, e) : 0;

	str[*i] == 'c' ? f_char(arguments, e) : 0;
	str[*i] == '%' ? f_per(e) : 0;
	str[*i] == 'x' ? f_hexa(arguments, e) : 0;
	str[*i] == 'X' ? f_caphexa(arguments, e) : 0;
// pointer adr
	str[*i] == 'p' ? f_pointadrs(arguments, e) : 0;

// 
//	str[*i] == 'C' || (str[*i] == 'S' ) ? f_widechar(arguments, e) : 0;

	//str[*i] == 'S' ? f_capstr(argumens, e) : 0;
}

