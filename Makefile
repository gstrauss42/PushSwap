# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/19 09:04:58 by gstrauss          #+#    #+#              #
#    Updated: 2019/08/23 14:00:10 by gstrauss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CMPL = gcc -o

all: lib_ft
	$(CMPL) push_swap libft/libft.a pushswap.c -Wall -Werror -Wextra
	$(CMPL) checker libft/libft.a checker.c -Wall -Werror -Wextra

lib_ft:
	make fclean -C libft
	make -C libft
	make clean -C libft

clean:
	rm -f push_swap

debug: 
	$(CMPL) push_swap libft/*.c libft/pushswap_functions/*.c pushswap.c -Wall -Werror -Wextra -g
	$(CMPL) checker libft/*.c libft/pushswap_functions/*.c checker.c -Wall -Werror -Wextra -g

re: fclean all
