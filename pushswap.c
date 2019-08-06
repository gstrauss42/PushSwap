/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 10:03:22 by gstrauss          #+#    #+#             */
/*   Updated: 2019/08/06 07:45:27 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	output(t_list **lista, t_list **listb);
void	gate(t_list **lista, t_list **listb);
void	standard(t_list **lista, t_list **listb);
void	lstupdate(t_list **lista);

int main(int argc, char **argv)
{
	if(argc > 1)
	{
		t_list *tmp;
		t_list *lista = NULL;
		t_list *listb = NULL;
		lista = ft_lstmake(argv);
		tmp = lista;
		while(tmp->next && atoi((char *)tmp->content)\
				< atoi((char *)tmp->next->content))
				tmp = tmp->next;
		if(!tmp->next)
			return(0);
//		output(&lista, &listb);
		gate(&lista, &listb);
		output(&lista, &listb);
	}
	return(0);
}

void	gate(t_list **lista, t_list **listb)
{
	int i;
	i = ft_lstlen(*lista);
/*	if(i <= 3)
		
	if(i > 3 && i <= 5)
*/
	if(i > 5)
		standard(lista, listb);
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

void	algo(t_list **lista, t_ist **listb)
{
	t_list *tmpa = *lista;
	t_list *tmpb = *listb;
	while(true)
	{
		while(tmpb)
		{

	}
}

t_list	*order(

void	standard(t_list **lista, t_list **listb)
{
	int i = ft_lstlen;
	t_list *final = order(*lista);
	
	t_list *tmp = *lista;
	ft_pb(lista, listb);
	write(1, "pb\n", 3);
	ft_pb(lista, listb);
	write(1, "pb\n", 3);

	if(ft_atoi((*listb)->content) < ft_atoi((*listb)->next->content))
	{
		ft_sb(listb);
		write(1, "sb\n", 3);
	}
	algo();
}
