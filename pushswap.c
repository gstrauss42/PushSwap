/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 10:03:22 by gstrauss          #+#    #+#             */
/*   Updated: 2019/08/19 13:39:12 by gstrauss         ###   ########.fr       */
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
		ft_putnbr(tmp->fpos);
		write(1, "   ", 3);
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
		ft_putnbr(ttmp->fpos);
		write(1, "   ", 3);
		ft_putendl((char *)ttmp->content);
		if(ttmp->next)
			ttmp = ttmp->next;
		else
			break;
	}
}

void	order(t_list **lista)
{
	t_list *tmp;
	t_list *ttmp = *lista;
	int p = 1;
	int i = ft_atoi((*lista)->content);
	while(true)
	{
		(*lista)->fpos = 0;
		if((*lista)->next)
			*lista = (*lista)->next;
		else
			break;
	}
	*lista = ttmp;
	while(p < ft_lstlen(ttmp) + 2)
	{
		while(true)
		{
			if(i >= ft_atoi((*lista)->content) && (*lista)->fpos == 0)
			{
				i = ft_atoi((*lista)->content);
				tmp = *lista;
			}
			if((*lista)->next)
				*lista = (*lista)->next;
			else
				break;
		}
		*lista = ttmp;
		tmp->fpos = p;
		while((*lista)->fpos != 0)
		{
			if((*lista)->next)
				*lista = (*lista)->next;
			else
				break;
		}
		if(!(*lista)->next && (*lista)->fpos != 0)
			break;
		i = ft_atoi((*lista)->content);
		p++;
	}
	*lista = ttmp;
}

void	perform(t_list **lista, t_list **listb, t_list *node)
{
	int count = ft_lstlen(*lista);
	while(count == ft_lstlen(*lista))
	{
		if(ft_lstplen(*lista, tmp) > (ft_lstlen(*lista) / 2))
		{
			if(ft_lstlen(*listb) < (ft_lstlen(*lista)) - ft_lstplen(*lista, node))
			{
				while(*lista != node)
				{
					ft_rra(*lista);
					if(ft_posdif(*listb, node) != 0)
					{
						ft_rrb(*listb);
						write(1, "rrr\n", 4);
					}
					else
						write(1, "rra\n", 4);
				}
			}
		}
		else if(ft_lstplen(*lista, tmp) <= (ft_lstlen(*lista) / 2))
			y = ft_lstplen(*lista);
	}
	if(ft_lstlen(*listb) <= y)
		y = y;
	if(ft_lstlen(*listb) > y)
	{
		if(ft_lstplen(*lista, tmp) > (ft_lstlen(*lista) / 2) && ft_posdif(*listb, tmp) > ft_lstlen(*listb) / 2)
		{
			if((ft_lstlen(*listb) - ft_posdif(*listb, tmp)) - y >= 0)
				y = ft_lstlen(*listb) - ft_posdif(*listb, tmp) - y;
			else
				y = y + ft_posdif(*listb, tmp) - y;
		}
	}	
}

void	algo(t_list **lista, t_list **listb)
{
	t_list *ret;
	t_list *tmp;
	t_list *tmpa = ft_lstdup(*lista);
	t_list *tmpb = ft_lstdup(*listb);
	int check = 10000000;
	int y = 0;
	while(tmpa)
	{
//		tmpa = ft_lstdup(*lista);
		tmp = *lista;
		while(tmp)
		{
			if(tmp)
			{
				while(tmp != lista)
				{
					if(ft_lstplen(*lista, tmp) > (ft_lstlen(*lista) / 2))
						y = ft_lstlen(*lista) - ft_lstplen(*lista, tmp);
					else if(ft_lstplen(*lista, tmp) <= (ft_lstlen(*lista) / 2))
						y = ft_lstplen(*lista);
				}
				if(ft_lstlen(*listb) <= y)
					y = y;
				if(ft_lstlen(*listb) > y)
				{
					if(ft_lstplen(*lista, tmp) > (ft_lstlen(*lista) / 2) && ft_posdif(*listb, tmp) > ft_lstlen(*listb) / 2)
					{
						if((ft_lstlen(*listb) - ft_posdif(*listb, tmp)) - y >= 0)
							y = ft_lstlen(*listb) - ft_posdif(*listb, tmp) - y;
						else
							y = y + ft_posdif(*listb, tmp) - y;
					}
				}
			}
			//LOGIC FOR FINDING EACH OPTIMUM PATH
			if(y < check) // y is number of steps vs current least steps
			{
				check = y;
				ret = tmp;	//ret is to pass to the operation part of the algo
			}
			if(tmp->next)
				tmp = tmp->next;
			else
				break;
		}
		perform(lista, listb, ret);
		y = 1000000;
//		ft_lstdel(&tmpa, ft_del);
	}
}

void	standard(t_list **lista, t_list **listb)
{
	order(lista);	
	ft_pb(lista, listb);
	write(1, "pb\n", 3);
	ft_pb(lista, listb);
	write(1, "pb\n", 3);
	if(ft_atoi((*listb)->content) < ft_atoi((*listb)->next->content))
	{
		ft_sb(listb);
		write(1, "sb\n", 3);
	}
	algo(lista, listb);
}
