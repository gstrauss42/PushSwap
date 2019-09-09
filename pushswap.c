/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 10:03:22 by gstrauss          #+#    #+#             */
/*   Updated: 2019/09/09 09:10:17 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	order(t_list **lista);
void	standard(t_list **lista, t_list **listb);
void	lstupdate(t_list **lista);

int		main(int argc, char **argv)
{
	t_list	*tmp;
	t_list	*lista;
	t_list	*listb;
	int		i;

	listb = NULL;
	if (argc > 1 && argv[1][0])
	{
		lista = ft_lstmake(argv);
		tmp = lista;
		i = ft_lstlen(lista);
		order(&lista);
		if (ft_rcheck(lista) == 0)
			return (0);
		if (i <= 5 && i != 4)
			ft_short_sort(&lista, &listb, i);
		else
			standard(&lista, &listb);
	}
	ft_lstdel(&lista, ft_del);
	ft_lstdel(&listb, ft_del);
	return (0);
}

void	standard(t_list **lista, t_list **listb)
{
	while (*lista)
	{
		ft_pb(lista, listb);
		write(1, "pb\n", 3);
	}
	ft_pa(lista, listb);
	write(1, "pa\n", 3);
	algo(lista, listb);
	ft_reorder(lista);
}
