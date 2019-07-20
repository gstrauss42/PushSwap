# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/19 09:04:58 by gstrauss          #+#    #+#              #
#    Updated: 2019/07/20 07:10:10 by gstrauss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CMPL = gcc -o

NAME = push_swap

SRCS = libft/libft.a pushswap.c

all :
	make fclean -C libft
	make -C libft
	make clean -C libft
	$(CMPL) $(NAME) $(SRCS)

clean:
	rm -f $(NAME)

re: fclean all
