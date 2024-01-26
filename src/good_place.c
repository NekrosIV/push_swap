/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_place.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:11:06 by kasingh           #+#    #+#             */
/*   Updated: 2024/01/26 17:11:12 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// This function finds the correct place of the number in stack_b.
// In other words, it check what index number nbr_push will get
// after it is being pushed to the stack_b.
int	good_place_in_b(t_node *stack_b, int nbr_push)
{
	int		i;
	t_node	*tmp;

	i = 1;
	if (nbr_push > stack_b->nbr && nbr_push < ft_find_last(stack_b)->nbr)
		i = 0;
	else if (nbr_push > ft_max(stack_b) || nbr_push < ft_min(stack_b))
		i = ft_find_index(stack_b, ft_max(stack_b));
	else
	{
		tmp = stack_b->next;
		while (tmp != NULL && (stack_b->nbr < nbr_push || tmp->nbr > nbr_push))
		{
			stack_b = stack_b->next;
			tmp = stack_b->next;
			i++;
		}
	}
	return (i);
}

// This function finds the correct place of the number in stack_a.
// In other words, it check what index number nbr_push will get
// after it is being pushed to the stack_a.
int	good_place_in_a(t_node *stack_a, int nbr_push)
{
	int i;
	t_node *tmp;

	i = 1;
	if (nbr_push < stack_a->nbr && nbr_push > ft_find_last(stack_a)->nbr)
		i = 0;
	else if (nbr_push > ft_max(stack_a) || nbr_push < ft_min(stack_a))
		i = ft_find_index(stack_a, ft_min(stack_a));
	else
	{
		tmp = stack_a->next;
		while (tmp != NULL && (stack_a->nbr > nbr_push || tmp->nbr < nbr_push))
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}