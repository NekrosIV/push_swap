/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:33:50 by kasingh           #+#    #+#             */
/*   Updated: 2024/01/05 17:54:01 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **src_stack, t_node **dst_stack)
{
	t_node	*src_top;

	if (!src_stack || !(*src_stack))
		return ;
	src_top = *src_stack;
	*src_stack = src_top->next;
	if (*src_stack)
		(*src_stack)->prev = NULL;
	src_top->next = *dst_stack;
	src_top->prev = NULL;
	if (*dst_stack)
		(*dst_stack)->prev = src_top;
	*dst_stack = src_top;
}

void	pa(t_node **src_stack, t_node **dst_stack)
{
	push(src_stack, dst_stack);
	ft_printf("pa\n");
}
void	pb(t_node **src_stack, t_node **dst_stack)
{
	push(src_stack, dst_stack);
	ft_printf("pb\n");
}
