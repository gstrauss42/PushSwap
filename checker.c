/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 09:47:38 by gstrauss          #+#    #+#             */
/*   Updated: 2019/07/29 11:32:02 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	check(char *line, t_list **lista, t_list **listb);
void	checks(char *line, t_list **lista, t_list **listb);
void	output(t_list **lista, t_list **listb);
int		error(t_list *lista);

int main(int argc, char **argv)
{
	char *line;
	t_list *lista = NULL;
	t_list *listb = NULL;
	lista = ft_lstmake(argv);
	if(error(lista) == 1)
		return(0);
	while(get_next_line(0, &line))
	{
		if(argc > 1)
		{
			check(line, &lista, &listb);
//			output(&lista, &listb);
		}
		free(line);
	}
	while(!listb && lista->next && atoi((char *)lista->content)\
			< atoi((char *)lista->next->content))
			lista = lista->next;
	if(!lista->next)
		printf("OK");
	if(lista->next)
		printf("KO");
	return(0);
}

int		error(t_list *lista)
{
	t_list *temp;
	while(lista)
	{
		temp = lista->next;
		while(temp && lista != temp)
		{
			if(lista->content && temp->content && ft_strcmp((char *)lista->content, (char *)temp->content) == 0)
			{
				write(1, "Erro1\n", 6);
				return(1);
			}
			if(temp->next)
				temp = temp->next;
			else
				break;
		}
		if(ft_isint(lista->content) == 0)
		{
			write(1, "Erro2\n", 6);
			return(1);
		}
		if(lista->next)
			lista = lista->next;
		else
			break;
	}
	return(0);
}

void	check(char *line, t_list **lista, t_list **listb)
{
		if(ft_strcmp(line, "sa") == 0)
			ft_sa(*lista);
		if(ft_strcmp(line, "sb") == 0)
			ft_sb(*listb);
		if(ft_strcmp(line, "ss") == 0)
		{
			ft_sa(*lista);
			ft_sb(*listb);
		}
		if(ft_strcmp(line, "pa") == 0)
			ft_pa(lista, listb);
		if(ft_strcmp(line, "pb") == 0)
			ft_pb(lista, listb);
		if(ft_strcmp(line, "ra") == 0)
			ft_ra(lista);
		if(ft_strcmp(line, "rb") == 0)
			ft_rb(listb);
		checks(line, lista, listb);
}

void	checks(char *line, t_list **lista, t_list **listb)
{
		if(ft_strcmp(line, "rr") == 0)
		{
			ft_ra(lista);
			ft_rb(listb);
		}
		if(ft_strcmp(line, "rra") == 0)
			ft_rra(lista);
		if(ft_strcmp(line, "rrb") == 0)
			ft_rrb(listb);
		if(ft_strcmp(line, "rrr") == 0)
		{
			ft_rra(lista);
			ft_rrb(listb);
		}
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
