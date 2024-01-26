/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:05:22 by kasingh           #+#    #+#             */
/*   Updated: 2024/01/26 17:24:05 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				nbr;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_utils
{
	int				index_a;
	int				index_b;
	int				good_place_in_a;
	int				good_place_in_b;
	int				lst_len_a;
	int				lst_len_b;
	char			s;
}					t_utils;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

void				rotate(t_node **stack);
void				ra(t_node **stack);
void				rb(t_node **stack);
void				rr(t_node **stack_a, t_node **stack_b);
void				rrotate(t_node **stack);
void				rra(t_node **stack);
void				rrb(t_node **stack);
void				rrr(t_node **stack_a, t_node **stack_b);
void				swap(t_node **stack);
void				sa(t_node **stack);
void				sb(t_node **stack);
void				ss(t_node **stack_a, t_node **stack_b);
void				push(t_node **src_stack, t_node **dst_stack);
void				pa(t_node **src_stack, t_node **dst_stack);
void				pb(t_node **src_stack, t_node **dst_stack);

int					is_not_duplicate(t_node *a, int n);
int					is_good_syntax(char *str);
int					is_good_int(char *str);
void				stack_init(t_node **a, char **av, int split);
void				add_node(t_node **stack, int n, char **av, int split);
void				free_stack(t_node **stack);
void				free_split(char **str);
void				free_err(t_node **a, char **av, int split);

int					is_sorted(t_node **a);
void				ft_sort_three(t_node **a);

char				*ft_itoa_nosigne(int n);
t_node				*ft_find_last(t_node *stack);
int					ft_max(t_node *stack);
int					ft_min(t_node *stack);
int					lst_len(t_node *stack);
int					ft_find_index(t_node *a, int nbr);

void				ft_sort(t_node **stack_a, t_node **stack_b);
void				ft_sort_three(t_node **a);
int					good_place_in_a(t_node *stack_a, int nbr_push);
int					good_place_in_b(t_node *stack_b, int nbr_push);
int					rarb(t_node **a, t_node **b, int c, char s);
int					rrarrb(t_node **a, t_node **b, int c, char s);
int					rrarb(t_node **a, t_node **b, int c, char s);
int					rarrb(t_node **a, t_node **b, int c, char s);
int					is_rarb(t_utils **s);
int					is_rrarrb(t_utils **s);
int					is_rrarb(t_utils **s);
int					is_rarrb(t_utils **s);
void				stack_init_utils(t_node *a, t_node *b, int c, t_utils **s);

char				*get_next_line(int fd);
char				*ft_strdup_gnl(const char *src);
char				*ft_strchr_gnl(const char *str, int c);

void				luffy(void);
void				usopp(void);

#endif