#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naali <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/09 11:18:25 by naali             #+#    #+#              #
#    Updated: 2018/11/26 15:09:35 by jucapik          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	fillit

CC			=	gcc

CFLAGS		+=	-Wall -Wextra -Werror

SRC			=	error.c		s_dbs.c		get_tetriminos.c	getpdir.c	\
				maintest.c	init.c	backtrack.c

HEADNAME	=	s_dbs.h		error.h		get_tetriminos.h	getpdir.h	\
				init.h	backtrack.h

SRCPATH		= 	./

HEADPATH	=	./

LIBNAME		=	ft

LIBPATH		=	libft/

LIBHEAD		=	includes

SOURCES		=	$(addprefix $(SRCPATH), $(SRCS))

HEADERS		=	$(addprefix $(HEADPATH), $(HEADNAME))

OBJ			=	$(SRC:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJ) $(HEADERS)
				@(cd $(LIBPATH) && $(MAKE))
				$(CC) -o $(NAME) $(OBJ) -I $(LIBPATH)$(LIBHEAD) -L $(LIBPATH) -l$(LIBNAME)

%.o			:	$(SRCPATH)/%.c
				$(CC) -o $@ -c $< $(CFLAGS)

.PHONY		:	clean fclean re

clean		:
				@(cd $(LIBPATH) && $(MAKE) clean)
				/bin/rm -rf $(OBJ)

fclean		:	clean
				/bin/rm -rf $(NAME)
				/bin/rm -rf libft/libft.a

re			:	fclean all
