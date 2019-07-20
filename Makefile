# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/19 09:04:58 by gstrauss          #+#    #+#              #
#    Updated: 2019/07/20 07:30:38 by gstrauss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CMPL = gcc -o

all: lib_ft
	$(CMPL) push_swap libft/libft.a pushswap.c

lib_ft:
	make fclean -C libft
	make -C libft
	make clean -C libft

clean:
	rm -f push_swap

re: fclean all
