/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:05:22 by kasingh           #+#    #+#             */
/*   Updated: 2024/01/23 16:17:32 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>

typedef struct s_node
{
	int				nbr;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

void				ra(t_node **stack);
void				rb(t_node **stack);
void				rr(t_node **stack_a, t_node **stack_b);
void				rra(t_node **stack);
void				rrb(t_node **stack);
void				rrr(t_node **stack_a, t_node **stack_b);
void				sa(t_node **stack);
void				sb(t_node **stack);
void				ss(t_node **stack_a, t_node **stack_b);
void				pa(t_node **src_stack, t_node **dst_stack);
void				pb(t_node **src_stack, t_node **dst_stack);

int					is_not_duplicate(t_node *a, int n);
int					is_good_syntax(char *str);
int					is_good_int(char *str);
void				free_stack(t_node **stack);
void				free_split(char **str);
void				free_err(t_node **a);

int					is_sorted(t_node **a);
void				ft_sort_three(t_node **a);

char				*ft_itoa_nosigne(int n);
t_node				*ft_find_last(t_node *stack);
int					ft_max(t_node *stack);
int					ft_min(t_node *stack);
int					lst_len(t_node *stack);
int					ft_find_index(t_node *a, int nbr);

void				ft_sort(t_node **stack_a, t_node **stack_b);

#endif