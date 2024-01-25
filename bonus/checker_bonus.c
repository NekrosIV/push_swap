/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:59:36 by kasingh           #+#    #+#             */
/*   Updated: 2024/01/25 17:20:58 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	which_action2(char *str, t_node **a, t_node **b)
{
	if (ft_strncmp(str, "ra", 2) == 0)
		rotate(a);
	else if (ft_strncmp(str, "rb", 2) == 0)
		rotate(b);
	else if (ft_strncmp(str, "rr", 2) == 0)
	{
		rotate(a);
		rotate(b);
	}
	else if (ft_strncmp(str, "rra", 3) == 0)
		rrotate(a);
	else if (ft_strncmp(str, "rrb", 3) == 0)
		rrotate(b);
	else if (ft_strncmp(str, "rrr", 3) == 0)
	{
		rrotate(a);
		rrotate(b);
	}
	else
		return (-1);
	return (0);
}

int	which_action(char *str, t_node **a, t_node **b)
{
	int	i;

	i = 0;
	if (ft_strncmp(str, "sa", 2) == 0)
		swap(a);
	else if (ft_strncmp(str, "sa", 2) == 0)
		swap(b);
	else if (ft_strncmp(str, "sb", 2) == 0)
	{
		swap(a);
		swap(b);
	}
	else if (ft_strncmp(str, "pa", 2) == 0)
		push(b, a);
	else if (ft_strncmp(str, "pb", 2) == 0)
		push(a, b);
	else
		i = which_action2(str, a, b);
	return (i);
}

void	gnl_call(t_node **a, t_node **b, int flag, char **av)
{
	char	*str;
	int		i;

	i = 0;
	str = 0;
	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
			break ;
		i = which_action(str, a, b);
		if (i < 0)
		{
			free(str);
			if (flag == 0)
				free_split(av);
			free_stack(a);
			free_stack(b);
			ft_putendl_fd("Error", 2);
			usopp();
			exit(1);
		}
		free(str);
	}
	free(str);
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
	stack_init(&a, av + i, i);
	gnl_call(&a, &b, i, av);
	if (is_sorted(&a) == 1 && lst_len(b) == 0)
		luffy();
	else
		usopp();
	if (i == 0)
		free_split(av);
	free_stack(&a);
	free_stack(&b);
}
