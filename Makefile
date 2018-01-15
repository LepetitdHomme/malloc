# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csellier <csellier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/19 08:28:40 by csellier          #+#    #+#              #
#    Updated: 2017/09/19 08:28:46 by csellier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_malloc_$(HOSTTYPE).so

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

FLAGS = -Wall -Wextra -Werror

SCR = malloc.c free.c

LINK = libft_malloc.so

OBJ = $(SCR:.c=.o)

$(NAME) : link $(OBJ)
	make -C libft/
	gcc $(FLAGS) -fPIC -shared -o $(NAME) $(OBJ) -L libft -lft

all : $(NAME)

link :
	ln -s $(NAME) $(LINK)

%.o: %.c
	gcc $(FLAGS) -c -I. $<
clean :
	make -C libft/ clean
	rm -f $(OBJ)

fclean : clean
	make -C libft/ fclean
	rm -rf $(NAME) $(LINK)

re : fclean all

