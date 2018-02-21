/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 21:11:12 by gmalpart          #+#    #+#             */
/*   Updated: 2018/01/29 15:50:41 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft/includes/libft.h"
# include <wchar.h>

/*
** main
*/

int		ft_printf(char const *str, ...);

/*
** parser
*/
void		flags_pen(int *i, char const *str, va_list arguments, int *e);
void		f_int(va_list args, int *e);
void		ft_putnbrcont(long long nbr, int *e);

void		f_octal(va_list arguments, int *e);
void		ft_putnbroct(unsigned int hold, int *e);

void		f_uint(va_list arguments, int *e);
void		ft_putnbruint(unsigned int nbr, int *e);

// solucion base de las pendejadas
void		ft_putnbrbase(long long nbr, int base, int *e);
/*
** strings
*/

void	f_char(va_list arguments, int *e);
void	f_str(va_list arguments, int *e);
void	print_str(char *str, int *e);

void	f_per(int *e);

void	f_hexa(va_list arguments, int *e);
void	print_hexa(unsigned int nbr, int *e);
void	f_caphexa(va_list arguments, int *e);
void	print_caphexa(unsigned int nbr, int *e);

/*
** pointer adress
*/

void	f_pointadrs(va_list arguments, int *e);
void	print_address(unsigned long adr, int *e);

#endif
