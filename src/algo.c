/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:20:43 by kasingh           #+#    #+#             */
/*   Updated: 2024/01/26 17:57:27 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Cette fonction calcule le nombre minimal de
// rotations nécessaires pour placer un élément
// de la pile A dans la pile B de manière optimisée.
// Elle explore différentes combinaisons
// de rotations et retourne le nombre minimal de rotations requis.
//
// @param a - Pointeur vers la pile A.
// @param b - Pointeur vers la pile B.
// @return Le nombre minimal de rotations nécessaires.
int	ft_rotate_type(t_node *a, t_node *b, t_utils **s)
{
	int		i;
	t_node	*tmp;

	if ((*s)->s == 'b')
		tmp = a;
	else
		tmp = b;
	i = INT_MAX;
	while (tmp)
	{
		stack_init_utils(a, b, tmp->nbr, s);
		if (i > is_rarb(s))
			i = is_rarb(s);
		if (i > is_rrarrb(s))
			i = is_rrarrb(s);
		if (i > is_rarrb(s))
			i = is_rarrb(s);
		if (i > is_rrarb(s))
			i = is_rrarb(s);
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

void	push_sort_b(t_node **stack_a, t_node **stack_b, t_utils **s)
{
	int		i;
	t_node	*current;

	(*s)->s = 'b';
	while (lst_len(*stack_a) > 3 && !is_sorted(stack_a))
	{
		current = *stack_a;
		i = ft_rotate_type(*stack_a, *stack_b, s);
		while (i >= 0)
		{
			stack_init_utils(*stack_a, *stack_b, current->nbr, s);
			if (i == is_rarb(s))
				i = rarb(stack_a, stack_b, current->nbr, (*s)->s);
			else if (i == is_rrarrb(s))
				i = rrarrb(stack_a, stack_b, current->nbr, (*s)->s);
			else if (i == is_rarrb(s))
				i = rarrb(stack_a, stack_b, current->nbr, (*s)->s);
			else if (i == is_rrarb(s))
				i = rrarb(stack_a, stack_b, current->nbr, (*s)->s);
			else
				current = current->next;
		}
	}
}

void	push_sort_a(t_node **stack_a, t_node **stack_b, t_utils **s)
{
	int		i;
	t_node	*tmp;

	(*s)->s = 'a';
	while (*stack_b)
	{
		tmp = *stack_b;
		i = ft_rotate_type(*stack_a, *stack_b, s);
		while (i >= 0)
		{
			stack_init_utils(*stack_a, *stack_b, tmp->nbr, s);
			if (i == is_rarb(s))
				i = rarb(stack_a, stack_b, tmp->nbr, (*s)->s);
			else if (i == is_rarrb(s))
				i = rarrb(stack_a, stack_b, tmp->nbr, (*s)->s);
			else if (i == is_rrarrb(s))
				i = rrarrb(stack_a, stack_b, tmp->nbr, (*s)->s);
			else if (i == is_rrarb(s))
				i = rrarb(stack_a, stack_b, tmp->nbr, (*s)->s);
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

void	sort_b(t_node **stack_a, t_node **stack_b, t_utils **s)
{
	while (lst_len(*stack_b) < 2 && lst_len(*stack_a) > 3
		&& !is_sorted(stack_a))
		pb(stack_a, stack_b);
	if (lst_len(*stack_a) > 3 && !is_sorted(stack_a))
		push_sort_b(stack_a, stack_b, s);
	if (!is_sorted(stack_a))
		ft_sort_three(stack_a);
}

void	ft_sort(t_node **stack_a, t_node **stack_b)
{
	int		i;
	t_utils	*s;

	s = malloc(sizeof(t_utils));
	if (!s)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	sort_b(stack_a, stack_b, &s);
	push_sort_a(stack_a, stack_b, &s);
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
	free(s);
}
