/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:19:56 by kasingh           #+#    #+#             */
/*   Updated: 2024/01/22 10:30:22 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	free_stack(t_node **stack)
{
	t_node	*tmp;
	t_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_err(t_node **a)
{
	free_stack(a);
	ft_putendl_fd("Error", 2);
	exit(1);
}

int	is_not_duplicate(t_node *a, int n)
{
	if (!a)
		return (1);
	while (a)
	{
		if (a->nbr == n)
			return (0);
		a = a->next;
	}
	return (1);
}

int	is_good_syntax(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	if ((str[i] == '+' || str[i] == '-') && str[i + 1] != '\0')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_good_int(char *str)
{
	int		len_str;
	char	*int_limit;
	int		max_len;
	int		i;

	i = 0;
	if (str[i] == '-')
		int_limit = ft_itoa_nosigne(INT_MIN);
	else
		int_limit = ft_itoa_nosigne(INT_MAX);
	if (!int_limit)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] == '0' && str[i + 1] != '\0')
		i++;
	max_len = ft_strlen(int_limit);
	len_str = ft_strlen(&str[i]);
	if (len_str > max_len)
		return (0);
	if (len_str == max_len)
		if (ft_strncmp(&str[i], int_limit, len_str) > 0)
			return (0);
	free(int_limit);
	return (1);
}

void	add_node(t_node **stack, int n)
{
	t_node	*node;
	t_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
		return ;
	}
	last_node = ft_find_last(*stack);
	last_node->next = node;
	node->prev = last_node;
}

void	stack_init(t_node **a, char **av)
{
	int	n;
	int	i;

	i = 0;
	while (av[i])
	{
		if (!is_good_syntax(av[i]))
			free_err(a);
		if (!is_good_int(av[i]))
			free_err(a);
		n = ft_atoi(av[i]);
		if (!is_not_duplicate(*a, n))
			free_err(a);
		add_node(a, n);
		i++;
	}
}

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

void	print_stack(const char *stack_name, t_node *stack)
{
	printf("%s: ", stack_name);
	while (stack)
	{
		printf("%d ", stack->nbr);
		stack = stack->next;
	}
	printf("\n");
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

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	int		i;

	a = 0;
	b = 0;
	i = 1;
	if (ac < 2 || !av[1][0])
		return (0);
	else if (ac == 2)
		av = ft_split(av[i--], ' ');
	stack_init(&a, av + i);
	if (!is_sorted(&a))
	{
		if (lst_len(a) <= 3)
			ft_sort_three(&a);
		else
			ft_sort(&a, &b);
	}
	if (i == 0)
		free_split(av);
	free_stack(&a);
}
