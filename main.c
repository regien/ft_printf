/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 21:10:39 by gmalpart          #+#    #+#             */
/*   Updated: 2018/01/26 13:17:30 by regien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	int		i;
	
	va_start(args, str);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
			parser(&i, str);
		else
			ft_putchar(str[i]);
	}
	return (i);
}
