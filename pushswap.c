/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 10:03:22 by gstrauss          #+#    #+#             */
/*   Updated: 2019/08/29 08:37:06 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	output(t_list **lista, t_list **listb);
void	gate(t_list **lista, t_list **listb);
void	standard(t_list **lista, t_list **listb);
void	lstupdate(t_list **lista);

int		main(int argc, char **argv)
{
	t_list *tmp;
	t_list *lista;
	t_list *listb;

	if (argc > 1)
	{
		listb = NULL;
		lista = ft_lstmake(argv);
		tmp = lista;
		while (tmp->next && atoi((char *)tmp->content)\
				< atoi((char *)tmp->next->content))
			tmp = tmp->next;
		if (!tmp->next)
			return (0);
		gate(&lista, &listb);
//		output(&lista, &listb);
	}
	return (0);
}

void	gate(t_list **lista, t_list **listb)
{
	int i;

	i = ft_lstlen(*lista);
/*	if(i <= 3)
	{
	}       */
	if(i > 3 && i <= 5)
	{
		standard(lista, listb);
	}
	if (i > 5)
		standard(lista, listb);
}

void	output(t_list **lista, t_list **listb)
{
	t_list	*tmp;
	t_list	*ttmp;

	tmp = *lista;
	write(1, "Lista:\n", 7);
	while (tmp && tmp->content)
	{
		ft_putnbr(tmp->fpos);
		write(1, "   ", 3);
		ft_putendl((char *)tmp->content);
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
	}
	ttmp = *listb;
	write(1, "Listb:\n", 7);
	while (ttmp && ttmp->content)
	{
		ft_putnbr(ttmp->fpos);
		write(1, "   ", 3);
		ft_putendl((char *)ttmp->content);
		if (ttmp->next)
			ttmp = ttmp->next;
		else
			break ;
	}
	write(1, "\n", 1);
}

void	order(t_list **lista)
{
	t_list	*tmp;
	t_list	*ttmp;
	int		p;
	int		i;

	ttmp = *lista;
	p = 1;
	i = ft_atoi((*lista)->content);
	while (true)
	{
		(*lista)->fpos = 0;
		if ((*lista)->next)
			*lista = (*lista)->next;
		else
			break ;
	}
	*lista = ttmp;
	while (p < ft_lstlen(ttmp) + 2)
	{
		while (true)
		{
			if (i >= ft_atoi((*lista)->content) && (*lista)->fpos == 0)
			{
				i = ft_atoi((*lista)->content);
				tmp = *lista;
			}
			if ((*lista)->next)
				*lista = (*lista)->next;
			else
				break ;
		}
		*lista = ttmp;
		tmp->fpos = p;
		while ((*lista)->fpos != 0)
		{
			if ((*lista)->next)
				*lista = (*lista)->next;
			else
				break ;
		}
		if (!(*lista)->next && (*lista)->fpos != 0)
			break ;
		i = ft_atoi((*lista)->content);
		p++;
		*lista = ttmp;
	}
	*lista = ttmp;
}

void	perform(t_list **lista, t_list **listb, t_list *node)
{
	if (ft_lstplen(*listb, node) > (ft_lstlen(*listb) / 2))
	{
		while (*listb && node && (*listb)->fpos != node->fpos)
		{
			if (ft_lstlen(*listb) - ft_lstplen(*listb, node) < (ft_lstlen(*listb) / 2) + 1 && *lista != node)
			{
				ft_rrb(listb);
				if (ft_posdif(*lista, node) != 0 && ft_lstlen(*lista) / 2 < ft_lstplen(*lista, node))
				{
					ft_rra(lista);
					write(1, "rrr\n", 4);
				}
				else
					write(1, "rrb\n", 4);
			}
			else
			{
				ft_rb(listb);
				if (ft_posdif(*lista, node) != 0 && ft_lstlen(*listb) / 2 < ft_lstplen(*listb, node) && *listb != node)
				{
					ft_ra(lista);
					write(1, "rr\n", 4);
				}
				else
					write(1, "rb\n", 4);
			}
		}
	}
	if (ft_lstplen(*listb, node) <= (ft_lstlen(*listb) / 2))
	{
		while (*listb && node && *listb != node)
		{
			ft_rb(listb);
			if (ft_lstlen(*listb) - ft_lstplen(*listb, node)\
					>= ft_posdif(*lista, node)\
					|| ft_posdif(*lista, node) < ft_lstlen(*lista) / 2)
			{
				ft_ra(lista);
				write(1, "rr\n", 3);
			}
			else
				write(1, "rb\n", 3);
		}
	}
	if (ft_posdif(*lista, node) != 0)
	{
		if (ft_posdif(*lista, node) <= ft_lstlen(*lista) / 2)
		{
			while (ft_posdif(*lista, node) != 0)
			{
				ft_ra(lista);
				write(1, "ra\n", 3);
			}
		}
		if (ft_posdif(*lista, node) > ft_lstlen(*lista) / 2)
		{
			while (ft_posdif(*lista, node) != 0)
			{
				ft_rra(lista);
				write(1, "rra\n", 4);
			}
		}
	}
	if (ft_isgreater(*lista, *listb) == 1 && (*lista)->next)
	{
		ft_ra(lista);
		write(1, "ra\n", 3);
	}
	ft_pa(lista, listb);
	write(1, "pa\n", 3);
}

void	algo(t_list **lista, t_list **listb)
{
	t_list	*ret;
	t_list	*tmp;
	int		check;
	int		y;

	y = 0;
	tmp = *listb;
	while (tmp && *lista)
	{
		y = 0;
		check = 10000000;
		tmp = *listb;
		while (tmp)
		{
			if (tmp)
			{
				if (ft_lstplen(*listb, tmp) > (ft_lstlen(*listb) / 2 && ft_lstlen(*listb) > 2))
				{
					y = ft_lstlen(*listb) - ft_lstplen(*listb, tmp) + 1;
					if (ft_posdif(*lista, tmp) != 0)
						y = y + ft_posdif(*lista, tmp);
				}
				else if (ft_lstplen(*listb, tmp) <= (ft_lstlen(*listb) / 2))
				{
					y = ft_lstplen(*listb, tmp) + 1;
					if (ft_posdif(*lista, tmp) != 0)
						y = y + ft_posdif(*lista, tmp);
				}
			}
			if (y < check)
			{
				check = y;
				ret = tmp;
			}
			if (tmp->next)
				tmp = tmp->next;
			else
				break ;
		}
		if (*lista)
			perform(lista, listb, ret);
		ret = *listb;
	}
}

void	pushforward(t_list **lista, t_list **listb)
{
	while (*lista)
	{
		ft_pb(lista, listb);
		write(1, "pb\n", 3);
	}
}

void	standard(t_list **lista, t_list **listb)
{
	order(lista);
	pushforward(lista, listb);
	ft_pa(lista, listb);
	write(1, "pa\n", 3);
	algo(lista, listb);
	ft_reorder(lista);
}
