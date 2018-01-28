/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_strings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 00:06:40 by gmalpart          #+#    #+#             */
/*   Updated: 2018/01/28 00:37:35 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


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
