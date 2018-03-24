/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 02:58:18 by gmalpart          #+#    #+#             */
/*   Updated: 2018/03/24 02:59:20 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putllhexa(unsigned long long nbr, t_total *e)
{
	if (nbr > 15)
	{
		ft_putllhexa(nbr / 16, e);
		ft_putllhexa(nbr % 16, e);
	}
	else
	{
		e->e = e->e + 1;
		ft_putchar(hexstr[nbr]);
	}
}

void	ft_putllhexacap(unsigned long long nbr, t_total *e)
{
	if (nbr > 15)
	{
		ft_putllhexacap(nbr / 16, e);
		ft_putllhexacap(nbr % 16, e);
	}
	else
	{
		e->e = e->e + 1;
		ft_putchar(caphexstr[nbr]);
	}
}

void	ft_putlloctal(unsigned long long nbr, t_total *e)
{
	if (nbr > 7)
	{
		ft_putlloctal(nbr / 8, e);
		ft_putlloctal(nbr % 8, e);
	}
	else
	{
		e->e = e->e + 1;
		ft_putchar(hexstr[nbr]);
	}
}

void	ft_putlluint(unsigned long long nbr, t_total *e)
{
	if (nbr >= 10)
	{
		ft_putlluint(nbr / 10, e);
		ft_putlluint(nbr % 10, e);
	}
	else
	{
		e->e = e->e + 1;
		ft_putchar(hexstr[nbr]);
	}
}

void	ft_putllint(long long nbr, t_total *e)
{
	if (nbr >= 10)
	{
		ft_putllint(nbr / 10, e);
		ft_putllint(nbr % 10, e);
	}
	else
	{
		e->e = e->e + 1;
		ft_putchar(hexstr[nbr]);
	}
}
