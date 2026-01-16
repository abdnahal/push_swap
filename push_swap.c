/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnahal <abdnahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:19:49 by abdnahal          #+#    #+#             */
/*   Updated: 2026/01/16 11:24:27 by abdnahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a) == NULL)
		return ;
	if (!is_sorted(*stack_a) && ft_lstsize(*stack_a) == 2)
		swap(stack_a, 'a');
	else if (!is_sorted(*stack_a) && ft_lstsize(*stack_a) == 3)
		sort_3(stack_a);
	else if (!is_sorted(*stack_a) && ft_lstsize(*stack_a) == 4)
		sort_4(stack_a, stack_b);
	else if (!is_sorted(*stack_a) && ft_lstsize(*stack_a) <= 5)
		sort_5(stack_a, stack_b);
	else if (!is_sorted(*stack_a) && ft_lstsize(*stack_a) <= 150)
	{
		sort_push_a(stack_a, stack_b, 0, 15);
		sort_push_b(stack_a, stack_b);
	}
	else if (!is_sorted(*stack_a))
	{
		sort_push_a(stack_a, stack_b, 0, 25);
		sort_push_b(stack_a, stack_b);
	}
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
}

// int main()
// {
//     t_list *head;
//     t_list bar;
//     t_list bare;
//     t_list bared;
//     t_list bareda;

//     bar.next = &bare;
//     bare.next = &bared;
//     bared.next = &bareda;
//     bareda.next = NULL;
//     head = &bar;
//     sa(head);
// }