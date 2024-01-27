/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_what_action.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:16:28 by kasingh           #+#    #+#             */
/*   Updated: 2024/01/27 11:46:02 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_rarb(t_utils **s)
{
	int	i;

	i = 0;
	if ((*s)->s == 'b')
	{
		i = (*s)->good_place_in_b;
		if (i < (*s)->index_a)
			i = (*s)->index_a;
	}
	else
	{
		i = (*s)->good_place_in_a;
		if (i < (*s)->index_b)
			i = (*s)->index_b;
	}
	return (i);
}

int	is_rrarrb(t_utils **s)
{
	int	i;

	i = 0;
	if ((*s)->s == 'b')
	{
		if ((*s)->good_place_in_b)
			i = (*s)->lst_len_b - (*s)->good_place_in_b;
		if ((i < ((*s)->lst_len_a - (*s)->index_a)))
			i = (*s)->lst_len_a - (*s)->index_a;
	}
	else
	{
		if ((*s)->good_place_in_a)
			i = (*s)->lst_len_a - (*s)->good_place_in_a;
		if ((i < ((*s)->lst_len_b - (*s)->index_b)))
			i = (*s)->lst_len_b - (*s)->index_b;
	}
	return (i);
}

int	is_rrarb(t_utils **s)
{
	int	i;

	i = 0;
	if ((*s)->s == 'b')
	{
		if ((*s)->index_a)
			i = (*s)->lst_len_a - (*s)->index_a;
		i = (*s)->good_place_in_b + i;
	}
	else
	{
		if ((*s)->good_place_in_a)
			i = (*s)->lst_len_a - (*s)->good_place_in_a;
		i = (*s)->index_b + i;
	}
	return (i);
}

int	is_rarrb(t_utils **s)
{
	int	i;

	i = 0;
	if ((*s)->s == 'b')
	{
		if ((*s)->good_place_in_b)
			i = (*s)->lst_len_b - (*s)->good_place_in_b;
		i = (*s)->index_a + i;
	}
	else
	{
		if ((*s)->index_b)
			i = (*s)->lst_len_b - (*s)->index_b;
		i = (*s)->good_place_in_a + i;
	}
	return (i);
}
