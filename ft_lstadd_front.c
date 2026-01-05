/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnahal <abdnahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 10:30:20 by abdnahal          #+#    #+#             */
/*   Updated: 2026/01/05 14:50:47 by abdnahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst && new)
	{
		lst = &new;
		return ;
	}
	else if(!new)
		return ;
	new->next = *lst;
	*lst = new;
}
