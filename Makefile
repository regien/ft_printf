# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/24 21:34:06 by gmalpart          #+#    #+#              #
#    Updated: 2018/03/03 01:16:57 by gmalpart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#MAKE = make -C
NAME = libftprintf.a
LIB = libft/
CFLAGS = -Wall -Wextra -Werror
CC = gcc
HEADER = libft/includes

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

$(NAME):
	gcc -c -I$(HEADER) $(CFILES)
	ar rc $(NAME) *.o
	ranlib $(NAME)

#clean:
#	$(LIBC)
#	/bin/rm -f ()

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
