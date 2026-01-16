/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnahal <abdnahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:13:09 by abdnahal          #+#    #+#             */
/*   Updated: 2026/01/16 17:19:49 by abdnahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicates(t_list *stack_a, char **arr)
{
	t_list	*temp;
	
	if (!stack_a)
		ft_error(&stack_a, arr);
	while (stack_a)
	{
		temp = stack_a->next;
		while (temp)
		{
			if ((stack_a->num == temp->num) || (stack_a->num > INT_MAX)
				|| (stack_a->num < INT_MIN))
			{
				ft_lstclear(&stack_a);
				write(2, "Error\n", 5);
				exit(EXIT_FAILURE);
			}
			temp = temp->next;
		}
		stack_a = stack_a->next;
	}
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a, '2');
	reverse_rotate(stack_b, '2');
}

int	is_sorted(t_list *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	reverse_rotate(t_list **stack, char c)
{
	t_list	*tmp;
	t_list	*temp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	temp = tmp->next;
	tmp->next->next = *stack;
	tmp->next = NULL;
	*stack = temp;
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}

void	rr(t_list **stack_a, t_list **stack_b, char flag)
{
	rotate(stack_a, 'a');
	rotate(stack_b, 'b');
	if (flag == '1')
		write(1, "rr\n", 3);
}
