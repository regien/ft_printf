/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 13:27:02 by regien            #+#    #+#             */
/*   Updated: 2018/03/24 06:01:43 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		flag_parsj(int *i, char const *str, va_list arg, t_total *e)
{
	*i = *i + 1;
	str[*i] == 'd' ? f_jint(arg, e) : 0;
	str[*i] == 'i' ? f_jint(arg, e) : 0;
	str[*i] == 'u' ? f_juint(arg, e) : 0;
	str[*i] == 'o' ? f_joctal(arg, e) : 0;
	str[*i] == 'x' ? f_jhexa(arg, e) : 0;
	str[*i] == 'X' ? f_jhexacap(arg, e) : 0;
}

void		flags_extra(int *i, char const *str, va_list arg, t_total *e)
{
	e->e = e->e + 1;
	if (str[*i] == 'D')
		f_lint(arg, e);
	else if (str[*i] == 'U')
		f_luint(arg, e);
	else if (str[*i] == 'O')
		f_loctal(arg, e);
}

void		flags_pen_2(int *i, char const *str, va_list arg, t_total *e)
{
	str[*i] == '0' ? f_zero(i, str, arg, e) : 0;
	str[*i] == ' ' ? f_space(i, str, arg, e) : 0;
	str[*i] == '#' ? f_hash(i, str, arg, e) : 0;
	str[*i] > '0' && str[*i] <= '9' ? f_right(i, str, arg, e) : 0;
	str[*i] == '-' ? f_left(i, str, arg, e) : 0;
	str[*i] == '+' ? f_plus(i, str, arg, e) : 0;
}

void		flags_pen(int *i, char const *str, va_list arg, t_total *e)
{
	*i = *i + 1;
	str[*i] == 'd' ? f_int(arg, e) : 0;
	str[*i] == 'i' ? f_int(arg, e) : 0;
	str[*i] == 'u' ? f_uint(arg, e) : 0;
	str[*i] == 'o' ? f_octal(arg, e) : 0;
	str[*i] == 's' ? f_str(arg, e) : 0;
	str[*i] == 'c' ? f_char(arg, e) : 0;
	str[*i] == '%' ? f_per(e) : 0;
	str[*i] == 'x' ? f_hexa(arg, e) : 0;
	str[*i] == 'X' ? f_caphexa(arg, e) : 0;
	str[*i] == 'p' ? f_pointadrs(arg, e) : 0;
	str[*i] == 'z' ? flag_parsz(i, str, arg, e) : 0;
	str[*i] == 'j' ? flag_parsj(i, str, arg, e) : 0;
	str[*i] == 'U' ? flags_extra(i, str, arg, e) : 0;
	str[*i] == 'D' || str[*i] == 'O' ? flags_extra(i, str, arg, e) : 0;
	str[*i] == 'C' || str[*i] == 'S' ? f_widechar(str, i, arg, e) : 0;
	str[*i] == 'l' && str[*i + 1] == 's' ? f_widestr(str, i, arg, e) : 0;
	str[*i] == 'l' && str[*i + 1] == 'c' ? f_widechar(str, i, arg, e) : 0;
	str[*i] == 'h' && str[*i + 1] == 'h' ? flag_parshh(i, str, arg, e) : 0;
	str[*i] == 'h' && str[*i + 1] != 'h' ? flag_parsh(i, str, arg, e) : 0;
	str[*i] == 'l' && str[*i + 1] != 'l' ? flag_parsl(i, str, arg, e) : 0;
	str[*i] == 'l' && str[*i + 1] == 'l' ? flag_parsll(i, str, arg, e) : 0;
	flags_pen_2(i, str, arg, e);
}
