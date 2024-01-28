/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:43:08 by kasingh           #+#    #+#             */
/*   Updated: 2024/01/28 11:32:23 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
		return (free(int_limit), 0);
	if (len_str == max_len)
		if (ft_strncmp(&str[i], int_limit, len_str) > 0)
			return (free(int_limit), 0);
	return (free(int_limit), 1);
}
