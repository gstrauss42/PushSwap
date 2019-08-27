/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 10:03:22 by gstrauss          #+#    #+#             */
/*   Updated: 2019/08/27 13:01:02 by gstrauss         ###   ########.fr       */
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
	{
	}                 //hardcode these solutions	
	if(i > 3 && i <= 5)
	{
	}*/
	if(i > 5)
		standard(lista, listb);
}

void	output(t_list **lista, t_list **listb)
{
	t_list *tmp;
	t_list *ttmp;
	tmp = *lista;
	write(1, "Lista:\n", 7);
	while(tmp && tmp->content)
	{
		ft_putnbr(tmp->fpos);
		write(1, "   ", 3);
		ft_putendl((char *)tmp->content);
		if(tmp->next)
			tmp = tmp->next;
		else
			break;
	}
	ttmp = *listb;
	write(1, "Listb:\n" ,7);
	while(ttmp && ttmp->content)
	{
		ft_putnbr(ttmp->fpos);
		write(1, "   ", 3);
		ft_putendl((char *)ttmp->content);
		if(ttmp->next)
			ttmp = ttmp->next;
		else
			break;
	}
	write(1, "\n", 1);
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
		*lista = ttmp;
	}
	*lista = ttmp;
}

void	perform(t_list **lista, t_list **listb, t_list *node)
{
	if(ft_lstplen(*lista, node) > (ft_lstlen(*lista) / 2))
	{
		while(*lista && node && (*lista)->fpos != node->fpos)
		{
			if(ft_lstlen(*lista) - ft_lstplen(*lista, node) < (ft_lstlen(*lista) / 2) + 1&& *listb != node)
			{
				write(1, (char *)node->content, 8);
				write(1, "\n", 1);
				write(1, ft_itoa(node->fpos), 8);
				ft_rra(lista);
//				output(lista, listb);
				if(ft_posdif(*listb, node) != 0 && ft_lstlen(*listb) / 2 < ft_lstplen(*listb, node))
				{
					ft_rrb(listb);
					write(1, "rrr\n", 4);
				}
				else
					write(1, "rra\n", 4);
			}
			else
			{
				ft_rb(listb);
				if(ft_posdif(*listb, node) != 0 && ft_lstlen(*listb) / 2 < ft_lstplen(*listb, node) && *listb != node)
				{
					ft_rb(listb);
					write(1, "rr\n", 4);
				}
				else
					write(1, "ra\n", 4);
			}
		}
	}
	if(ft_lstplen(*lista, node) <= (ft_lstlen(*lista) / 2))
	{
		while( *lista && node && *lista != node)
		{
			ft_ra(lista);
			if(ft_lstlen(*lista) - ft_lstplen(*lista, node) >= ft_posdif(*listb, node) || ft_posdif(*listb, node) < ft_lstlen(*listb) / 2) 
			{
				ft_rb(listb);
				write(1, "rr\n", 3);
			}
			else
				write(1, "ra\n", 3);
		}
	}
	if(ft_posdif(*listb, node) != 0)
	{
		if(ft_posdif(*listb, node) <= ft_lstlen(*listb) / 2)
		{
			while(ft_posdif(*listb, node) != 0)
			{
				ft_rb(listb);
				write(1, "rb\n", 3);
			}
		}
		if(ft_posdif(*listb, node) > ft_lstlen(*listb) / 2)
		{
			while(ft_posdif(*listb, node) != 0)
			{
				ft_rrb(listb);
				write(1, "rrb\n", 4);
			}
		}
	}
	ft_pb(lista, listb);
}

void	algo(t_list **lista, t_list **listb)
{
	t_list *ret;
	t_list *tmp;
	int check;
	int y = 0;
	tmp = *lista;
	while(tmp && *listb)
	{
		y = 0;
		check = 10000000;
		tmp = *lista;
		while(tmp)
		{
			if(tmp)
			{
				if(ft_lstplen(*lista, tmp) > (ft_lstlen(*lista) / 2 && ft_lstlen(*lista) > 2))
				{
					y = ft_lstlen(*lista) - ft_lstplen(*lista, tmp) + 1;
					if(ft_posdif(*listb, tmp) != 0)
						y = y + ft_posdif(*listb, tmp);
				}
				else if(ft_lstplen(*lista, tmp) <= (ft_lstlen(*lista) / 2))
				{
					y = ft_lstplen(*lista, tmp) + 1;
					if(ft_posdif(*listb, tmp) != 0)
						y = y + ft_posdif(*listb, tmp);
				}
			}
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
		write(1, ft_itoa(y), 1);
		if(*listb)
			perform(lista, listb, ret);
//		output(lista, listb);
		ret = *lista;
	}
}

void	pushback(t_list **lista, t_list **listb)
{
		while(*listb)
	{
		ft_pa(lista, listb);
		write(1, "pa\n", 3);
	}
}

void	standard(t_list **lista, t_list **listb)
{
	order(lista);
	ft_pb(lista, listb);
	write(1, "pb\n", 3);
	algo(lista, listb);
	ft_reorder(listb);
	pushback(lista, listb);
}
