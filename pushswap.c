/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 10:03:22 by gstrauss          #+#    #+#             */
/*   Updated: 2019/07/29 10:24:04 by gstrauss         ###   ########.fr       */
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
		t_list *tmp;
		t_list *lista;
		t_list *listb;
		lista = ft_lstmake(argv);
		tmp = lista;
		while(tmp->next && atoi((char *)tmp->content)\
				< atoi((char *)tmp->next->content))
				tmp = tmp->next;
		if(!tmp->next)
			return(0);
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
		write(1, "pa\n", 3);
		ft_pa(lista, listb);
	}
}

void	firstpushinstructions(t_list *ttemp, t_list **lista, int count, t_list **listb)
{
	int i;
	int position;
	if(ttemp && *lista)
		position = ft_lstplen(*lista, ttemp);
	i = 0;
	while(*lista && ttemp && ft_strcmp((*lista)->content, ttemp->content) != 0)
	{
		if(count / 2 > position)
		{
			ft_rra(lista);
			write(1, "rra\n", 4);
		}
		else if(count / 2 <= position)
		{
			ft_ra(lista);
			write(1, "ra\n", 3);
		}
	}
	ft_pb(lista, listb);
	write(1, "pb\n", 3);
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
				ttemp = temp;
				check = ft_atoi(temp->content);
				ttemp = ft_lstnew(temp->content, temp->content_size);
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
			ttemp = ft_lstnew((*lista)->content, (*lista)->content_size);
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
