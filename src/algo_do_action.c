/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_do_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:13:41 by kasingh           #+#    #+#             */
/*   Updated: 2024/01/26 17:23:52 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	rarb(t_node **a, t_node **b, int c, char s)
{
	if (s == 'b')
	{
		while ((*a)->nbr != c && good_place_in_b(*b, c) > 0)
			rr(a, b);
		while ((*a)->nbr != c)
			ra(a);
		while (good_place_in_b(*b, c) > 0)
			rb(b);
		pb(a, b);
	}
	else
	{
		while ((*b)->nbr != c && good_place_in_a(*a, c) > 0)
			rr(a, b);
		while ((*b)->nbr != c)
			rb(b);
		while (good_place_in_a(*a, c) > 0)
			ra(a);
		pa(b, a);
	}
	return (-1);
}

// This function rotate both stack_a and stack_b in the
// reverse direction as required amount.
int	rrarrb(t_node **a, t_node **b, int c, char s)
{
	if (s == 'b')
	{
		while ((*a)->nbr != c && good_place_in_b(*b, c) > 0)
			rrr(a, b);
		while ((*a)->nbr != c)
			rra(a);
		while (good_place_in_b(*b, c) > 0)
			rrb(b);
		pb(a, b);
	}
	else
	{
		while ((*b)->nbr != c && good_place_in_a(*a, c) > 0)
			rrr(a, b);
		while ((*b)->nbr != c)
			rrb(b);
		while (good_place_in_a(*a, c) > 0)
			rra(a);
		pa(b, a);
	}
	return (-1);
}

// This function rotate the stack_a in reverse direction,
// the stack_b in oppsite direction of stack_a as required amount.
int	rrarb(t_node **a, t_node **b, int c, char s)
{
	if (s == 'b')
	{
		while ((*a)->nbr != c)
			rra(a);
		while (good_place_in_b(*b, c) > 0)
			rb(b);
		pb(a, b);
	}
	else
	{
		while (good_place_in_a(*a, c) > 0)
			rra(a);
		while ((*b)->nbr != c)
			rb(b);
		pa(b, a);
	}
	return (-1);
}

// This function rotate the stack_b in reverse direction,
// the stack_a in oppsite direction of stack_a as required amount.
int	rarrb(t_node **a, t_node **b, int c, char s)
{
	if (s == 'b')
	{
		while ((*a)->nbr != c)
			ra(a);
		while (good_place_in_b(*b, c) > 0)
			rrb(b);
		pb(a, b);
	}
	else
	{
		while (good_place_in_a(*a, c) > 0)
			ra(a);
		while ((*b)->nbr != c)
			rrb(b);
		pa(b, a);
	}
	return (-1);
}
