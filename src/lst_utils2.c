/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:36:51 by kasingh           #+#    #+#             */
/*   Updated: 2024/01/23 11:39:37 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(t_node **a)
{
	t_node	*current;

	if (!a || !(*a) || !(*a)->next)
		return (1);
	current = *a;
	while (current->next)
	{
		if (current->nbr > current->next->nbr)
			return (0);
		current = current->next;
	}
	return (1);
}

int	ft_find_index(t_node *a, int nbr)
{
	int	i;

	i = 0;
	while (a->nbr != nbr)
	{
		a = a->next;
		i++;
	}
	a->index = 0;
	return (i);
}
