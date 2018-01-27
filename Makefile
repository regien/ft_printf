# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/24 21:34:06 by gmalpart          #+#    #+#              #
#    Updated: 2018/01/24 21:38:10 by gmalpart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE = make -C
NAME = libftprintf.a
LIB = libft/
CFLAGS = -Wall -Wextra -Werror
CC = gcc

CFILES = $(LIB)/libft.a\
		 main.c

#These options are here in case the lib needs to be recompiled.
#LIBM, LIBC, LIBF will run rules re, clean and fclean inside the libft folder
LIBM = $(MAKE) $(LIB) re
LIBC = $(MAKE) $(LIB) clean
LIBF = $(MAKE) $(LIB) fclean

all: $(NAME)

$(NAME):
	$(LIBM)
	$(CC) $(CFILES) -I. -o test

clean:
	$(LIBC)
	/bin/rm -f ()
