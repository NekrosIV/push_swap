/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:08:18 by kasingh           #+#    #+#             */
/*   Updated: 2024/01/08 17:39:37 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate(t_node **stack)
{
	t_node	*first_node;
	t_node	*last_node;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first_node = *stack;
	last_node = ft_find_last(*stack);
	last_node->next = first_node;
	first_node->prev = last_node;
	*stack = last_node;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
}
void	rra(t_node **stack)
{
	rrotate(stack);
	ft_printf("rra\n");
}
void	rrb(t_node **stack)
{
	rrotate(stack);
	ft_printf("rrb\n");
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rrotate(stack_a);
	rrotate(stack_b);
	ft_printf("rrr\n");
}
