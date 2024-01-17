/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:38:34 by kasingh           #+#    #+#             */
/*   Updated: 2024/01/06 16:06:14 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **stack)
{
	t_node	*first_node;
	t_node	*second_node;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first_node = *stack;
	second_node = (*stack)->next;
	first_node->next = second_node->next;
	if (second_node->next)
		second_node->next->prev = first_node;
	second_node->next = first_node;
	first_node->prev = second_node;
	second_node->prev = NULL;
	*stack = second_node;
}
void	sa(t_node **stack)
{
	swap(stack);
	ft_printf("sa\n");
}
void	sb(t_node **stack)
{
	swap(stack);
	ft_printf("sb\n");
}
void	ss(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}