# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/24 21:34:06 by gmalpart          #+#    #+#              #
#    Updated: 2018/03/24 05:14:55 by gmalpart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#MAKE = make -C
NAME = libftprintf.a
LIB = libft/
CFLAGS = -Wall -Wextra -Werror
CC = gcc
HEADER = libft/includes

FLAGSHEAD = -I libft/includes -I includes/

FTFILES = ft_memalloc.c \
		  ft_putnbr.c \
		  ft_putchar.c \
		  ft_putstr.c \
		  ft_strlen.c

LIBFTFILES = $(addprefix libft/, $(FTFILES))

FILES = parser.c \
		f_conversions.c \
		z_conversions.c \
		l_conversions.c \
		ll_conversions.c \
		ll_helpers.c \
		h_conversions.c \
		hh_conversions.c \
		hh_helpers.c \
		j_conversions.c \
		parse_intfloat.c \
		help_intfloat.c \
		parser_strings.c \
		help_strings.c \
		help_widechar.c \
		j_numbers.c \
		f_align.c \
		f_leftalign.c \
		f_space.c \
		f_zero.c \
		main.c 

SRCFILES = $(addprefix src/, $(FILES))

CFILES =  ./libft/*.c ./*.c


#These options are here in case the lib needs to be recompiled.
#LIBM, LIBC, LIBF will run rules re, clean and fclean inside the libft folder
LIBM = $(MAKE) $(LIB) re
LIBC = $(MAKE) $(LIB) clean
LIBF = $(MAKE) $(LIB) fclean

all: $(NAME)

#$(NAME):
#	$(LIBM)
#	$(CC) $(CFILES) -I. -o test

#$(NAME):
#	gcc -c -I$(HEADER) $(CFILES)
#	ar rc $(NAME) *.o
#	ranlib $(NAME)

$(NAME):
	gcc -c $(FLAGSHEAD) $(LIBFTFILES) $(SRCFILES)
	ar rc $(NAME) *.o
	ranlib $(NAME)


comp:
	gcc $(FLAGSHEAD) $(LIBFTFILES) $(SRCFILES) -o test

#clean:
#	$(LIBC)
#	/bin/rm -f ()

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
