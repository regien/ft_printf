/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_conversions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 05:19:58 by gmalpart          #+#    #+#             */
/*   Updated: 2018/02/21 05:50:44 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//void	print_hexa(unsigned int nbr, int *e)


void    f_hhexa(va_list args, int *e)
{
	unsigned short  holder;

	holder = (unsigned short)va_arg(args, void*);
	print_hexa((unsigned int)holder, e);
	*e = *e - 3;
}

void    f_hhexacap(va_list args, int *e)
{
	unsigned short  holder;

    holder = (unsigned short)va_arg(args, void*);
    print_caphexa((unsigned int)holder, e);
	*e = *e - 3;
}

void    f_hoctal(va_list args, int *e)
{
    unsigned short  holder;
    
    holder = (unsigned short)va_arg(args, void*);
    asd;
	*e = *e - 3;
}
