/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:49:34 by kasingh           #+#    #+#             */
/*   Updated: 2023/11/17 10:08:50 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_isdigit: Vérifie si un caractère est un chiffre décimal */
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
