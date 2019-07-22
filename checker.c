/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 09:47:38 by gstrauss          #+#    #+#             */
/*   Updated: 2019/07/22 09:22:48 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	char *line;

	while(get_next_line(1, &line))
	{
		printf("%s\n", line);
		free(line);
	}
	if(argc > 1)
	{
		if(ft_strcmp(argv[1], "sa") == 0)
		{
		}
		if(ft_strcmp(argv[1], "sb") == 0)
		{
		}
		if(ft_strcmp(argv[1], "ss") == 0)
		{
		}
		if(ft_strcmp(argv[1], "pa") == 0)
		{
		}
		if(ft_strcmp(argv[1], "pb") == 0)
		{
		}
		if(ft_strcmp(argv[1], "ra") == 0)
		{
		}
		if(ft_strcmp(argv[1], "rb") == 0)
		{
		}
		if(ft_strcmp(argv[1], "rr") == 0)
		{
		}
		if(ft_strcmp(argv[1], "rra") == 0)
		{
		}
		if(ft_strcmp(argv[1], "rrb") == 0)
		{
		}
		if(ft_strcmp(argv[1], "rrr") == 0)
		{
		}
	}
	return(0);
}
