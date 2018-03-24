/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_conversions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 02:41:05 by gmalpart          #+#    #+#             */
/*   Updated: 2018/03/24 02:42:21 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		flag_parsh(int *i, char const *str, va_list arg, t_total *e)
{
	*i = *i + 1;
	str[*i] == 'd' ? f_hint(arg, e) : 0;
	str[*i] == 'i' ? f_hint(arg, e) : 0;
	str[*i] == 'u' ? f_huint(arg, e) : 0;
	str[*i] == 'o' ? f_hoctal(arg, e) : 0;
	str[*i] == 'x' ? f_hhexa(arg, e) : 0;
	str[*i] == 'X' ? f_hhexacap(arg, e) : 0;
}

void		flag_parshh(int *i, char const *str, va_list arg, t_total *e)
{
	*i = *i + 2;
	str[*i] == 'd' ? f_hhint(arg, e) : 0;
	str[*i] == 'i' ? f_hhint(arg, e) : 0;
	str[*i] == 'u' ? f_hhuint(arg, e) : 0;
	str[*i] == 'o' ? f_hhoctal(arg, e) : 0;
	str[*i] == 'x' ? f_hhhexa(arg, e) : 0;
	str[*i] == 'X' ? f_hhhexacap(arg, e) : 0;
}

void		flag_parsl(int *i, char const *str, va_list arg, t_total *e)
{
	*i = *i + 1;
	str[*i] == 'd' ? f_lint(arg, e) : 0;
	str[*i] == 'i' ? f_lint(arg, e) : 0;
	str[*i] == 'u' ? f_luint(arg, e) : 0;
	str[*i] == 'o' ? f_loctal(arg, e) : 0;
	str[*i] == 'x' ? f_lhexa(arg, e) : 0;
	str[*i] == 'X' ? f_lhexacap(arg, e) : 0;
}

void		flag_parsll(int *i, char const *str, va_list arg, t_total *e)
{
	*i = *i + 2;
	str[*i] == 'd' ? f_llint(arg, e) : 0;
	str[*i] == 'i' ? f_llint(arg, e) : 0;
	str[*i] == 'u' ? f_lluint(arg, e) : 0;
	str[*i] == 'o' ? f_lloctal(arg, e) : 0;
	str[*i] == 'x' ? f_llhexa(arg, e) : 0;
	str[*i] == 'X' ? f_llhexacap(arg, e) : 0;
}

void		flag_parsz(int *i, char const *str, va_list arg, t_total *e)
{
	*i = *i + 1;
	str[*i] == 'd' ? f_zint(arg, e) : 0;
	str[*i] == 'i' ? f_zint(arg, e) : 0;
	str[*i] == 'u' ? f_zuint(arg, e) : 0;
	str[*i] == 'o' ? f_zoctal(arg, e) : 0;
	str[*i] == 'x' ? f_zhexa(arg, e) : 0;
	str[*i] == 'X' ? f_zhexacap(arg, e) : 0;
}
