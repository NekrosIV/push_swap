/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:22:30 by kasingh           #+#    #+#             */
/*   Updated: 2024/01/26 17:22:56 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	stack_init_utils(t_node *a, t_node *b, int c, t_utils **s)
{
	(*s)->index_a = ft_find_index(a, c);
	(*s)->index_b = ft_find_index(b, c);
	(*s)->good_place_in_a = good_place_in_a(a, c);
	(*s)->good_place_in_b = good_place_in_b(b, c);
	(*s)->lst_len_a = lst_len(a);
	(*s)->lst_len_b = lst_len(b);
}
