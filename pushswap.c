/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 10:03:22 by gstrauss          #+#    #+#             */
/*   Updated: 2019/07/17 15:32:14 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"

int main(int argc, char **argv)
{
	t_list *lista;
	t_list *listb;
	
	lista = ft_lstmake(argv, ' ');
	rra(&lista);
	while(lista)
	{
		printf("lista: %s\n", lista->content);
		if(lista->next)
			lista = lista->next;
		else
			break;
	}
//	printf("\n");
//	printf("listb: %s\n", listb->content);
	return(0);
}
