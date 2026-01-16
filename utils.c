/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnahal <abdnahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:18:11 by abdnahal          #+#    #+#             */
/*   Updated: 2026/01/16 16:54:29 by abdnahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **stack_a)
{
	t_list	*tmp;

	if (is_sorted(*stack_a))
		return ;
	tmp = *stack_a;
	if (tmp->num > tmp->next->num && tmp->num < tmp->next->next->num)
		swap(stack_a, 'a');
	else if (tmp->num > tmp->next->num && tmp->next->num > tmp->next->next->num)
	{
		swap(stack_a, 'a');
		reverse_rotate(stack_a, 'a');
	}
	else if (tmp->num > tmp->next->num && tmp->next->next->num > tmp->next->num)
		rotate(stack_a, 'a');
	else if (tmp->num < tmp->next->num && tmp->num < tmp->next->next->num)
	{
		swap(stack_a, 'a');
		rotate(stack_a, 'a');
	}
	else if (tmp->num < tmp->next->num && tmp->num > tmp->next->next->num)
		reverse_rotate(stack_a, 'a');
}

int	get_pos(t_list *stack, int index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == index)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

void	sort_4(t_list **stack_a, t_list **stack_b)
{
	if (get_pos(*stack_a, 0) > ft_lstsize(*stack_a) / 2)
	{
		while ((*stack_a)->index != 0)
			reverse_rotate(stack_a, 'a');
	}
	else
	{
		while ((*stack_a)->index != 0)
			rotate(stack_a, 'a');
	}
	push(stack_a, stack_b, 'b', 'b');
	sort_3(stack_a);
	push(stack_a, stack_b, 'a', 'a');
}

void	free_all(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
