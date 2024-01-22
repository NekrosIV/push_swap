/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:54:08 by kasingh           #+#    #+#             */
/*   Updated: 2024/01/17 12:34:26 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_find_last(t_node *stack)
{
	if (stack == 0)
		return (0);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	ft_max(t_node *stack)
{
	int	i;

	i = stack->nbr;
	while (stack)
	{
		if (stack->nbr > i)
			i = stack->nbr;
		stack = stack->next;
	}
	return (i);
}

int	ft_min(t_node *stack)
{
	int	i;

	i = stack->nbr;
	while (stack)
	{
		if (stack->nbr < i)
			i = stack->nbr;
		stack = stack->next;
	}
	return (i);
}

int	lst_len(t_node *stack)
{
	int	count;

	if (NULL == stack)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}
