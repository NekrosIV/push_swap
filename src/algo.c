/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:20:43 by kasingh           #+#    #+#             */
/*   Updated: 2024/01/26 12:18:29 by kasingh          ###   ########.fr       */
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
		while (stack_b->nbr < nbr_push || tmp->nbr > nbr_push)
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
	int		i;
	t_node	*tmp;

	i = 1;
	if (nbr_push < stack_a->nbr && nbr_push > ft_find_last(stack_a)->nbr)
		i = 0;
	else if (nbr_push > ft_max(stack_a) || nbr_push < ft_min(stack_a))
		i = ft_find_index(stack_a, ft_min(stack_a));
	else
	{
		tmp = stack_a->next;
		while (stack_a->nbr > nbr_push || tmp->nbr < nbr_push)
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}

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

// This function calculates how many times
// we should rotate the stacks together.
// Because after a certain amoun of rotate, we will
// proceed only with one stack rotation.
int	is_rarb(t_node *a, t_node *b, int c, char s)
{
	int	i;

	i = 0;
	if (s == 'b')
	{
		i = good_place_in_b(b, c);
		if (i < ft_find_index(a, c))
			i = ft_find_index(a, c);
	}
	else
	{
		i = good_place_in_a(a, c);
		if (i < ft_find_index(b, c))
			i = ft_find_index(b, c);
	}
	return (i);
}

// This function calculates how many times we should rotate the stacks together.
// Because after a certain amoun of rotate, we will proceed only with one stack
// rotation. Since here we have reverse rotate,rather than index number,
// we check reverse index number which is
// calculated by list_size - index_number.
int	is_rrarrb(t_node *a, t_node *b, int c, char s)
{
	int	i;

	i = 0;
	if (s == 'b')
	{
		if (good_place_in_b(b, c))
			i = lst_len(b) - good_place_in_b(b, c);
		if ((i < (lst_len(a) - ft_find_index(a, c))))
			i = lst_len(a) - ft_find_index(a, c);
	}
	else
	{
		if (good_place_in_a(a, c))
			i = lst_len(a) - good_place_in_a(a, c);
		if ((i < (lst_len(b) - ft_find_index(b, c))))
			i = lst_len(b) - ft_find_index(b, c);
	}
	return (i);
}

// Again, this function makes similar calculations.
// This function do same calculations for rra+rb case.
int	is_rrarb(t_node *a, t_node *b, int c, char s)
{
	int	i;

	i = 0;
	if (s == 'b')
	{
		if (ft_find_index(a, c))
			i = lst_len(a) - ft_find_index(a, c);
		i = good_place_in_b(b, c) + i;
	}
	else
	{
		if (good_place_in_a(a, c))
			i = lst_len(a) - good_place_in_a(a, c);
		i = ft_find_index(b, c) + i;
	}
	return (i);
}

// Again, this function makes similar calculations.
// This function do same calculations for ra+rrb case.
int	is_rarrb(t_node *a, t_node *b, int c, char s)
{
	int	i;

	i = 0;
	if (s == 'b')
	{
		if (good_place_in_b(b, c))
			i = lst_len(b) - good_place_in_b(b, c);
		i = ft_find_index(a, c) + i;
	}
	else
	{
		if (ft_find_index(b, c))
			i = lst_len(b) - ft_find_index(b, c);
		i = good_place_in_a(a, c) + i;
	}
	return (i);
}

// Cette fonction calcule le nombre minimal de
// rotations nécessaires pour placer un élément
// de la pile A dans la pile B de manière optimisée.
// Elle explore différentes combinaisons
// de rotations et retourne le nombre minimal de rotations requis.
//
// @param a - Pointeur vers la pile A.
// @param b - Pointeur vers la pile B.
// @return Le nombre minimal de rotations nécessaires.
int	ft_rotate_type(t_node *a, t_node *b, char s)
{
	int		i;
	t_node	*tmp;

	if (s == 'b')
		tmp = a;
	else
		tmp = b;
	i = INT_MAX;
	while (tmp)
	{
		if (i > is_rarb(a, b, tmp->nbr, s))
			i = is_rarb(a, b, tmp->nbr, s);
		if (i > is_rrarrb(a, b, tmp->nbr, s))
			i = is_rrarrb(a, b, tmp->nbr, s);
		if (i > is_rarrb(a, b, tmp->nbr, s))
			i = is_rarrb(a, b, tmp->nbr, s);
		if (i > is_rrarb(a, b, tmp->nbr, s))
			i = is_rrarb(a, b, tmp->nbr, s);
		tmp = tmp->next;
	}
	return (i);
}
//
// Cette fonction transfère et trie les éléments de la pile A
// vers la pile B de manière optimisée.
// Elle s'assure de minimiser le nombre de rotations nécessaires
// pour placer chaque élément
// dans la pile B à la bonne position.
//
// Paramètres :
// - stack_a : Adresse de la pile A
// - stack_b : Adresse de la pile B
//

void	push_sort_b(t_node **stack_a, t_node **stack_b)
{
	int		i;
	char	s;
	t_node	*current;

	s = 'b';
	while (lst_len(*stack_a) > 3 && !is_sorted(stack_a))
	{
		current = *stack_a;
		i = ft_rotate_type(*stack_a, *stack_b, s);
		while (i >= 0)
		{
			if (i == is_rarb(*stack_a, *stack_b, current->nbr, s))
				i = rarb(stack_a, stack_b, current->nbr, s);
			else if (i == is_rrarrb(*stack_a, *stack_b, current->nbr, s))
				i = rrarrb(stack_a, stack_b, current->nbr, s);
			else if (i == is_rarrb(*stack_a, *stack_b, current->nbr, s))
				i = rarrb(stack_a, stack_b, current->nbr, s);
			else if (i == is_rrarb(*stack_a, *stack_b, current->nbr, s))
				i = rrarb(stack_a, stack_b, current->nbr, s);
			else
				current = current->next;
		}
	}
}

void	push_sort_a(t_node **stack_a, t_node **stack_b)
{
	int		i;
	char	s;
	t_node	*tmp;

	s = 'a';
	while (*stack_b)
	{
		tmp = *stack_b;
		i = ft_rotate_type(*stack_a, *stack_b, s);
		while (i >= 0)
		{
			if (i == is_rarb(*stack_a, *stack_b, tmp->nbr, s))
				i = rarb(stack_a, stack_b, tmp->nbr, s);
			else if (i == is_rarrb(*stack_a, *stack_b, tmp->nbr, s))
				i = rarrb(stack_a, stack_b, tmp->nbr, s);
			else if (i == is_rrarrb(*stack_a, *stack_b, tmp->nbr, s))
				i = rrarrb(stack_a, stack_b, tmp->nbr, s);
			else if (i == is_rrarb(*stack_a, *stack_b, tmp->nbr, s))
				i = rrarb(stack_a, stack_b, tmp->nbr, s);
			else
				tmp = tmp->next;
		}
	}
}
//
// Fonction de tri pour déplacer des éléments de la pile A vers la pile B
// en utilisant des opérations spécifiques pour optimiser le processus.
// Cette fonction effectue un transfert 2 éléments de stack_a vers stack_b
// tout en maintenant certaines conditions, puis elle applique un tri
// avancé sur stack_a si nécessaire. Enfin, elle effectue un tri final
// sur les trois éléments restants de stack_a.
//
// Paramètres :
// - stack_a : Adresse de la pile A
// - stack_b : Adresse de la pile B
//

void	sort_b(t_node **stack_a, t_node **stack_b)
{
	while (lst_len(*stack_b) < 2 && lst_len(*stack_a) > 3
		&& !is_sorted(stack_a))
		pb(stack_a, stack_b);
	if (lst_len(*stack_a) > 3 && !is_sorted(stack_a))
		push_sort_b(stack_a, stack_b);
	if (!is_sorted(stack_a))
		ft_sort_three(stack_a);
}

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

void	ft_sort(t_node **stack_a, t_node **stack_b)
{
	int	i;

	sort_b(stack_a, stack_b);
	push_sort_a(stack_a, stack_b);
	i = ft_find_index(*stack_a, ft_min(*stack_a));
	if (i < lst_len(*stack_a) - i)
	{
		while ((*stack_a)->nbr != ft_min(*stack_a))
			ra(stack_a);
	}
	else
	{
		while ((*stack_a)->nbr != ft_min(*stack_a))
			rra(stack_a);
	}
}
