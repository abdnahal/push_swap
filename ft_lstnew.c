/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnahal <abdnahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 10:24:58 by abdnahal          #+#    #+#             */
/*   Updated: 2026/01/19 14:26:17 by abdnahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(long num)
{
	t_list	*new;

	if (num > INT_MAX || num < INT_MIN)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->num = num;
	new->next = NULL;
	return (new);
}
