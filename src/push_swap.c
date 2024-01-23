/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:19:56 by kasingh           #+#    #+#             */
/*   Updated: 2024/01/23 11:52:37 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	add_node(t_node **stack, int n)
{
	t_node	*node;
	t_node	*last_node;

	node = malloc(sizeof(t_node));
	if (!node)
		free_err(stack);
	node->next = NULL;
	node->nbr = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = ft_find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	stack_init(t_node **a, char **av)
{
	int	n;
	int	i;

	i = 0;
	while (av[i])
	{
		if (!is_good_syntax(av[i]))
			free_err(a);
		if (!is_good_int(av[i]))
			free_err(a);
		n = ft_atoi(av[i]);
		if (!is_not_duplicate(*a, n))
			free_err(a);
		add_node(a, n);
		i++;
	}
}

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
	stack_init(&a, av + i);
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
