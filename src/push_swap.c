/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:19:56 by kasingh           #+#    #+#             */
/*   Updated: 2024/01/25 16:43:18 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	int		i;

	a = 0;
	b = 0;
	i = 1;
	if (ac < 2 || !av[1][0])
		return (0);
	else if (ac == 2)
		av = ft_split(av[i--], ' ');
	stack_init(&a, av + i, i);
	if (!is_sorted(&a))
	{
		if (lst_len(a) <= 3)
			ft_sort_three(&a);
		else
			ft_sort(&a, &b);
	}
	if (i == 0)
		free_split(av);
	free_stack(&a);
}
