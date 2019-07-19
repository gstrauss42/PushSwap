# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/19 09:04:58 by gstrauss          #+#    #+#              #
#    Updated: 2019/07/19 09:10:34 by gstrauss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = libft/libft.a pushswap.c

all :
	make fclean -C libft
	make -C libft
	make clean -C libft
	gcc $(SRCS)

