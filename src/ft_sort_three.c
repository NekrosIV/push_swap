/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:20:25 by kasingh           #+#    #+#             */
/*   Updated: 2024/01/26 17:21:37 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort_three(t_node **a)
{
	if (ft_max(*a) == (*a)->nbr)
		ra(a);
	else if (ft_max(*a) == (*a)->next->nbr)
	{
		rra(a);
	}
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}
