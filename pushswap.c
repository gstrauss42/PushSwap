/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 10:03:22 by gstrauss          #+#    #+#             */
/*   Updated: 2019/07/24 08:41:01 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"

void	output(t_list **lista, t_list **listb);

int main(int argc, char **argv)
{
	if(argc > 1)
	{
		t_list *lista;
		t_list *listb;
		lista = ft_lstmake(argv, ' ', 1);
		output(&lista, &listb);
	}
	return(0);
}

void	output(t_list **lista, t_list **listb)
{
	t_list *tmp;
	t_list *ttmp;
	tmp = *lista;
	while(tmp && tmp->content)
	{
		printf("lista: %s\n", tmp->content);
		if(tmp->next)
			tmp = tmp->next;
		else
			break;
	}
	ttmp = *listb;
	printf("\n");
	while(ttmp && ttmp->content)
	{
		printf("listb: %s\n", ttmp->content);
		if(ttmp->next)
			ttmp = ttmp->next;
		else
			break;
	}
}
