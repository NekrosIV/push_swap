/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:02:05 by kasingh           #+#    #+#             */
/*   Updated: 2024/01/31 11:08:05 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	add_node(t_node **stack, int n, char **av, int split)
{
	t_node	*node;
	t_node	*last_node;

	node = malloc(sizeof(t_node));
	if (!node)
		free_err(stack, av, split);
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

void	stack_init(t_node **a, char **av, int split)
{
	int	n;
	int	i;

	i = 0;
	if (!av[i])
		free_err(a, av, split);
	while (av[i])
	{
		if (!is_good_syntax(av[i]))
			free_err(a, av, split);
		if (!is_good_int(av[i]))
			free_err(a, av, split);
		n = ft_atoi(av[i]);
		if (!is_not_duplicate(*a, n))
			free_err(a, av, split);
		add_node(a, n, av, split);
		i++;
	}
}
