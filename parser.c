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

void		flag_parsh(int *i, char const *str, va_list arg, int *e)	
{
	*i = *i + 1;
	str[*i] == 'd' ? f_hint(arg, e) : 0;
	str[*i] == 'i' ? f_hint(arg, e) : 0;
	str[*i] == 'u' ? f_huint(arg, e) : 0;
	str[*i] == 'o' ? f_hoctal(arg, e) : 0;
	str[*i] == 'x' ? f_hhexa(arg, e) : 0;
	str[*i] == 'X' ? f_hhexacap(arg, e) : 0;
}

void		flag_parshh(int *i, char const *str, va_list arg, int *e)	
{
	*i = *i + 2;
	str[*i] == 'd' ? f_hhint(arg, e) : 0;
	str[*i] == 'i' ? f_hhint(arg, e) : 0;
	str[*i] == 'u' ? f_hhuint(arg, e) : 0;
	str[*i] == 'o' ? f_hhoctal(arg, e) : 0;
	str[*i] == 'x' ? f_hhhexa(arg, e) : 0;
	str[*i] == 'X' ? f_hhhexacap(arg, e) : 0;
}

void		flags_pen(int *i, char const *str, va_list arg, int *e)
{
	*i = *i + 1;
	str[*i] == 'd' ? f_int(arg, e) : 0;
	str[*i] == 'i' ? f_int(arg, e) : 0;
	str[*i] == 'u' ? f_uint(arg, e) : 0;
	str[*i] == 'o' ? f_octal(arg, e) : 0;

// strings
	str[*i] == 's' ? f_str(arg, e) : 0;

	str[*i] == 'c' ? f_char(arg, e) : 0;
	str[*i] == '%' ? f_per(e) : 0;
	str[*i] == 'x' ? f_hexa(arg, e) : 0;
	str[*i] == 'X' ? f_caphexa(arg, e) : 0;
// pointer adr
	str[*i] == 'p' ? f_pointadrs(arg, e) : 0;

// 
	str[*i] == 'C' || str[*i] == 'S' ? f_widechar(str, i, arg, e) : 0;
	str[*i] == 'l' && str[*i + 1] == 's' ? f_widestr(str, i, arg, e) : 0;
	str[*i] == 'l' && str[*i + 1] == 'c' ? f_widechar(str, i, arg, e) : 0;
	str[*i] == 'h' && str[*i + 1] == 'h' ? flag_parshh(i, str, arg, e) : 0;
	str[*i] == 'h' && str[*i + 1] != 'h' ? flag_parsh(i, str, arg, e) : 0;
	//str[*i] == 'S' ? f_capstr(argumens, e) : 0;
}