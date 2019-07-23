/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 10:03:22 by gstrauss          #+#    #+#             */
/*   Updated: 2019/07/23 10:49:54 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"

int main(int argc, char **argv)
{
	if(argc > 1)
	{
		t_list *lista;
//		t_list *listb;
		lista = ft_lstmake(argv, ' ', 1);
		while(lista)
		{
			printf("lista: %s\n", lista->content);
			if(lista->next)
				lista = lista->next;
			else
				break;
		}
/*		if(listb->content)
		{
			printf("\n");
			printf("listb: %s\n", listb->content);
		}*/
	}
	return(0);
}
