/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 21:11:12 by gmalpart          #+#    #+#             */
/*   Updated: 2018/01/28 00:36:49 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft/includes/libft.h"

/*
** main
*/

int		ft_printf(char const *str, ...);

/*
** parser
*/
void		flags_pen(int *i, char const *str, va_list arguments, int *e);
void		f_int(va_list args, int *e);

/*
** strings
*/

void	f_char(va_list arguments, int *e);
void	f_str(va_list arguments, int *e);
void	print_str(char *str, int *e);

void	f_per(int *e);
#endif
