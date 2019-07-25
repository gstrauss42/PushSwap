/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 10:03:22 by gstrauss          #+#    #+#             */
/*   Updated: 2019/07/25 09:36:37 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	output(t_list **lista, t_list **listb);
void	checks(t_list **lista, t_list **listb);
void	firstpushinstructions(t_list *ttemp, t_list **lista, int count, t_list **listb);

int main(int argc, char **argv)
{
	if(argc > 1)
	{
		t_list *lista;
		t_list *listb;
		lista = ft_lstmake(argv);
//		output(&lista, &listb);
		checks(&lista, &listb);
//		output(&lista, &listb);
	}
	return(0);
}

void	pushback(t_list **lista, t_list **listb)
{
	while(*listb)
	{
//		write(1, "pa\n", 3);
		pa(lista, listb);
	//	output(lista, listb);
	}
}

void	firstpushinstructions(t_list *ttemp, t_list **lista, int count, t_list **listb)
{
	int i;
	int position;
	if(ttemp && lista)
		position = ft_lstplen(*lista, ttemp);
	i = 0;
	if(ttemp->content)
		printf("%s\n", ttemp->content);
	while(*lista != ttemp)
	{
		if(count / 2 > position)
		{
			rra(lista);
//			write(1, "rra\n", 4);
		}
		else if(count / 2 <= position)
		{
			ft_ra(lista);
//			write(1, "ra\n", 3);
		}
	//	output(lista, listb);
	}
	pb(lista, listb);
//	write(1, "pb\n", 3);
//	output(lista, listb);
}

void	checks(t_list **lista, t_list **listb)
{
	t_list *temp;
	t_list *ttemp = NULL;
	int check;
	int count;
	count = 0;
	temp = *lista;
	check = ft_atoi((*lista)->content);
	while(*lista)
	{
		while(temp)
		{
			if(temp->content && check > ft_atoi(temp->content))
			{
				check = ft_atoi(temp->content);
				ttemp = temp;
			}
			count++;
			if(temp->next)
				temp = temp->next;
			else
				break;
		}
		firstpushinstructions(ttemp, lista, count, listb);
		if(*lista)
		{
			count = 0;
			check = ft_atoi((*lista)->content);
			temp = *lista;
			ttemp = NULL;
			ttemp = *lista;
		}
	}
	pushback(lista, listb);
}

void	output(t_list **lista, t_list **listb)
{
	t_list *tmp;
	t_list *ttmp;
	tmp = *lista;
	while(tmp && tmp->content)
	{
		write(1, "Lista:", 6);
		ft_putendl((char *)tmp->content);
		if(tmp->next)
			tmp = tmp->next;
		else
			break;
	}
	ttmp = *listb;
	while(ttmp && ttmp->content)
	{
		write(1, "Listb:", 6);
		ft_putendl((char *)ttmp->content);
		if(ttmp->next)
			ttmp = ttmp->next;
		else
			break;
	}
}
