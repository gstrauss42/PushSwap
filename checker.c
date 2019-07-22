/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 09:47:38 by gstrauss          #+#    #+#             */
/*   Updated: 2019/07/22 14:08:02 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

void	check(char *line, t_list *lista, t_list *listb);
void	checks(char *line, t_list *lista, t_list *listb);

int main(int argc, char **argv)
{
	char *line;
	
	t_list *lista;
	t_list *listb = NULL;
	lista = ft_lstmake(argv, ' ', 1);
	while(get_next_line(1, &line))
	{
		if(argc > 1)
		{
			check(line, lista, listb);
			while(lista)
			{
				printf("lista: %s\n", lista->content);
				if(lista->next)
					lista = lista->next;
				else
					break;
			}
			/*if(listb->content)
			{
				printf("\n");
				printf("listb: %s\n", listb->content);
			}*/
		}
		free(line);
	}
	return(0);
}

void	check(char *line, t_list *lista, t_list *listb)
{
		if(ft_strcmp(line, "sa") == 0)
			sa(lista);
		if(ft_strcmp(line, "sb") == 0)
			sb(listb);
		if(ft_strcmp(line, "ss") == 0)
		{
			sa(lista);
			sb(listb);
		}
		if(ft_strcmp(line, "pa") == 0)
			pa(&lista, &listb);
		if(ft_strcmp(line, "pb") == 0)
			pb(&lista, &listb);
		if(ft_strcmp(line, "ra") == 0)
			ra(&lista);
		if(ft_strcmp(line, "rb") == 0)
			rb(&listb);
		checks(line, lista, listb);
}

void	checks(char *line, t_list *lista, t_list *listb)
{
		if(ft_strcmp(line, "rr") == 0)
		{
			ra(&lista);
			rb(&listb);
		}
		if(ft_strcmp(line, "rra") == 0)
			rra(&lista);
		if(ft_strcmp(line, "rrb") == 0)
			rrb(&listb);
		if(ft_strcmp(line, "rrr") == 0)
		{
			rra(&lista);
			rrb(&listb);
		}
}
