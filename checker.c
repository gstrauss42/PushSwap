/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 09:47:38 by gstrauss          #+#    #+#             */
/*   Updated: 2019/08/28 14:04:50 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int		check(char *line, t_list **lista, t_list **listb);
int		checks(char *line, t_list **lista, t_list **listb, int i);
void	output(t_list **lista, t_list **listb);
int		error(t_list *lista);

int		main(int argc, char **argv)
{
	char	*line;
	t_list	*lista;
	t_list	*listb;

	lista = NULL;
	listb = NULL;
	if (!argv[1] || !argv[1][0])
		return (0);
	lista = ft_lstmake(argv);
	if (error(lista) == 1)
		return (0);
	while (get_next_line(0, &line))
	{
		if (argc > 1)
		{
			if (check(line, &lista, &listb) == 0)
				return (0);
		}
		ft_strdel(&line);
	}
	while (!listb && lista->next && atoi((char *)lista->content)\
			< atoi((char *)lista->next->content))
		lista = lista->next;
	if (!lista->next)
		printf("OK");
	if (lista->next)
		printf("KO");
	return (0);
}

int		error(t_list *lista)
{
	t_list *temp;

	while (lista)
	{
		temp = lista->next;
		while (temp && lista != temp)
		{
			if (lista->content && temp->content &&\
					ft_strcmp((char *)lista->content,\
						(char *)temp->content) == 0)
			{
				write(1, "Error\n", 6);
				return (1);
			}
			if (temp->next)
				temp = temp->next;
			else
				break ;
		}
		if (ft_isint(lista->content) == 0)
		{
			write(1, "Error\n", 6);
			return (1);
		}
		if (lista->next)
			lista = lista->next;
		else
			break ;
	}
	return (0);
}

int		check(char *line, t_list **lista, t_list **listb)
{
	int i;

	i = 0;
	if (ft_strcmp(line, "sa") == 0)
		ft_sa(lista);
	else if (ft_strcmp(line, "sb") == 0)
		ft_sb(listb);
	else if (ft_strcmp(line, "ss") == 0)
	{
		ft_sa(lista);
		ft_sb(listb);
	}
	else if (ft_strcmp(line, "pa") == 0)
		ft_pa(lista, listb);
	else if (ft_strcmp(line, "pb") == 0)
		ft_pb(lista, listb);
	else if (ft_strcmp(line, "ra") == 0)
		ft_ra(lista);
	else if (ft_strcmp(line, "rb") == 0)
		ft_rb(listb);
	else
		i = 1;
	return (checks(line, lista, listb, i));
}

int		checks(char *line, t_list **lista, t_list **listb, int i)
{
	if (ft_strcmp(line, "rr") == 0)
	{
		ft_ra(lista);
		ft_rb(listb);
	}
	else if (ft_strcmp(line, "rra") == 0)
		ft_rra(lista);
	else if (ft_strcmp(line, "rrb") == 0)
		ft_rrb(listb);
	else if (ft_strcmp(line, "rrr") == 0)
	{
		ft_rra(lista);
		ft_rrb(listb);
	}
	else if (i == 1)
	{
		write(1, "Error", 5);
		return (0);
	}
	return (1);
}

void	output(t_list **lista, t_list **listb)
{
	t_list *tmp;
	t_list *ttmp;

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
