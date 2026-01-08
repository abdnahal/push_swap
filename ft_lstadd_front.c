/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnahal <abdnahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 10:30:20 by abdnahal          #+#    #+#             */
/*   Updated: 2026/01/08 11:11:03 by abdnahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list **new)
{
	t_list *temp;
	if (!*lst && *new)
	{
		*lst = *new;
		return ;
	}
	else if(!*new)
		return ;
	temp = *new;
	(*new) = (*new)->next;
	temp->next = *lst;
	*lst = temp;
}
