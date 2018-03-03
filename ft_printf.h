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
# include <stdint.h>


extern char	hexstr[];
extern char	caphexstr[];

typedef struct     s_total
{
//    int             *i;
    int             wd;
    int             e;
}                   t_total;


/*
** main
*/

int		ft_printf(char const *str, ...);

/*
** parser
*/
void		flags_pen(int *i, char const *str, va_list arguments, t_total *e);
void		flag_parshh(int *i, char const *str, va_list arg, t_total *e);
void		flag_parsh(int *i, char const *str, va_list arg, t_total *e);
void		flag_parsl(int *i, char const *str, va_list arg, t_total *e);
void		flag_parsll(int *i, char const *str, va_list arg, t_total *e);
void		flag_parsz(int *i, char const *str, va_list arg, t_total *e);
void		flag_parsj(int *i, char const *str, va_list arg, t_total *e);

void		flags_extra(int *i, char const *str, va_list arg, t_total *e);

void		f_int(va_list args, t_total *e);
void		ft_putnbrcont(long long nbr, t_total *e);

void		f_octal(va_list arguments, t_total *e);
void		ft_putnbroct(unsigned int hold, t_total *e);

void		f_uint(va_list arguments, t_total *e);
void		ft_putnbruint(unsigned int nbr, t_total *e);

// solucion base de las pendejadas
void		ft_putnbrbase(long long nbr, int base, t_total *e);
/*
** strings
*/

void	f_char(va_list arguments, t_total *e);
void	f_str(va_list arguments, t_total *e);
void	print_str(char *str, t_total *e);

void	f_per(t_total *e);

void	f_hexa(va_list arguments, t_total *e);
void	print_hexa(unsigned int nbr, t_total *e);
void	f_caphexa(va_list arguments, t_total *e);
void	print_caphexa(unsigned int nbr, t_total *e);

// wide chars
void	f_widechar(const char *str, int *i, va_list arguments, t_total *e);
void	ft_putstrwide(wchar_t *str, t_total *e);
void	f_widestr(const char *str, int *i, va_list arguments, t_total *e);
/*
** pointer adress
*/

void	f_pointadrs(va_list arguments, t_total *e);
void	print_address(unsigned long adr, t_total *e);

/*
**  HH Conversions
*/

void	f_hhhexa(va_list args, t_total *e);
void	ft_puthhhexa(unsigned int nbr, t_total *e);

void	ft_puthhhexacap(unsigned int nbr, t_total *e);
void	f_hhhexacap(va_list args, t_total *e);

void		ft_puthhoctal(unsigned int hold, t_total *e);
void	f_hhoctal(va_list args, t_total *e);

void		ft_puthhuint(unsigned int nbr, t_total *e);
void	f_hhuint(va_list args, t_total *e);
void	f_hhint(va_list args, t_total *e);

/*
**  H Conversions
*/

void    f_hhexa(va_list args, t_total *e);

void    f_hhexacap(va_list args, t_total *e);

void    f_hoctal(va_list args, t_total *e);
void    f_huint(va_list args, t_total *e);
void    f_hint(va_list args, t_total *e);

/*
**  L Conversions
*/

void    f_lhexa(va_list args, t_total *e);
void    f_lhexacap(va_list args, t_total *e);
void    f_loctal(va_list args, t_total *e);
void    f_luint(va_list args, t_total *e);
void    f_lint(va_list args, t_total *e);

/*
**  LL Conversions
*/

void	ft_putllhexa(unsigned long long nbr, t_total *e);
void    f_llhexa(va_list args, t_total *e);

void	ft_putllhexacap(unsigned long long nbr, t_total *e);
void    f_llhexacap(va_list args, t_total *e);

void	ft_putlloctal(unsigned long long nbr, t_total *e);
void    f_lloctal(va_list args, t_total *e);

void	ft_putlluint(unsigned long long nbr, t_total *e);
void    f_lluint(va_list args, t_total *e);

void	ft_putllint(long long nbr, t_total *e);
void    f_llint(va_list args, t_total *e);

/*
**  Z conversions
*/

void    f_zhexa(va_list args, t_total *e);
void    f_zhexacap(va_list args, t_total *e);
void    f_zoctal(va_list args, t_total *e);
void    f_zuint(va_list args, t_total *e);
void    f_zint(va_list args, t_total *e);

/*
** J conversions 
*/

void    f_jhexa(va_list args, t_total *e);
void    f_jhexacap(va_list args, t_total *e);
void    f_joctal(va_list args, t_total *e);
void    f_juint(va_list args, t_total *e);
void    f_jint(va_list args, t_total *e);

/*
**  PADDERS
*/

int     len_number(int nbr, int base);
void    f_putzeros(t_total *e, int size);
void    f_zeroleft(int *i, const char *str, va_list arg, t_total *e);
void    f_zero(int *i, char const *str, va_list arg, t_total *e);

void    f_zeroleftdebug(int *i, char const *str, va_list arg, t_total *e);
void    f_zerodebug(int *i, char const *str, va_list arg, t_total *e);
/*
**  J NUMBERS
*/

int    len_unsignumber(unsigned int nbr, int base);
void        put_paddin(t_total *e, int size);
void        ft_putunbase(unsigned int nbr, int base, t_total *e);
void        ft_putcapunbase(unsigned int nbr, int base, t_total *e);
void        f_alignrextra(int *i, char const *str, void* holder, t_total *e);
void        f_alignr(int *i, char const *str, va_list arg, t_total *e);
void        f_right(int *i, char const *str, va_list arg, t_total *e);

/*
**  F SPACES  / HASH
*/

void        f_space(int *i, const char *str, va_list arg, t_total *e);
void        f_hash(int *i, const char *str, va_list arg, t_total *e);

/*
**  LEFT ALIGN
*/

void    f_plus(int *i, const char *str, va_list arg, t_total *e);
void    f_left(int *i, const char *str, va_list arg, t_total *e);

#endif
