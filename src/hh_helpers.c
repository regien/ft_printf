/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hh_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 02:49:00 by gmalpart          #+#    #+#             */
/*   Updated: 2018/03/24 06:47:08 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthhhexa(unsigned int nbr, t_total *e)
{
	if (nbr > 15)
	{
		ft_puthhhexa(nbr / 16, e);
		ft_puthhhexa(nbr % 16, e);
	}
	else
	{
		e->e = e->e + 1;
		ft_putchar(g_hexstr[nbr]);
	}
}

void	ft_puthhhexacap(unsigned int nbr, t_total *e)
{
	if (nbr > 15)
	{
		ft_puthhhexacap(nbr / 16, e);
		ft_puthhhexacap(nbr % 16, e);
	}
	else
	{
		e->e = e->e + 1;
		ft_putchar(g_caphexstr[nbr]);
	}
}

void	ft_puthhoctal(unsigned int hold, t_total *e)
{
	if (hold > 7)
	{
		ft_puthhoctal(hold / 8, e);
		ft_puthhoctal(hold % 8, e);
	}
	else
	{
		e->e = e->e + 1;
		ft_putchar(hold + '0');
	}
}

void	ft_puthhuint(unsigned int nbr, t_total *e)
{
	if (nbr >= 10)
	{
		ft_puthhuint(nbr / 10, e);
		ft_puthhuint(nbr % 10, e);
	}
	else
	{
		e->e = e->e + 1;
		ft_putchar(nbr + '0');
	}
}
