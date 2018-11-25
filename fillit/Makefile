# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jucapik <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/25 10:04:56 by jucapik           #+#    #+#              #
#    Updated: 2018/11/25 12:48:39 by jucapik          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fillit

LIBFT		=	libft.a

LIBFTPATH	=	libft/

TESTNAME	=	test

CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	error.c		get_tetriminos.c	s_dbs.c		maintest.c \
				getpdir.c

OBJ			=	$(SRCS:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(LIBFT)
				gcc $(FLAGS) -c $(SRCS)

test		:	$(LIBFT) $(OBJ)
				gcc $(CFLAGS) $(OBJ) -o $(TESTNAME)

%.o         :   %.c
	            gcc -o $@ -c $< $(CFLAGS)

$(LIBFT)	:
				$(MAKE) -C libft/ all

clean		:
				/bin/rm -f *.o # A CHANGER
				$(MAKE) -C libft/ clean

fclean		:	clean
				/bin/rm -f $(NAME)
				$(MAKE) -C libft/ fclean

re			:	fclean all
