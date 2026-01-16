/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnahal <abdnahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:09:31 by abdnahal          #+#    #+#             */
/*   Updated: 2026/01/16 11:13:23 by abdnahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **stack_a, t_list **stack_b, char c, char flag)
{
	if (c == 'a')
		ft_lstadd_front(stack_a, stack_b);
	else if (c == 'b')
		ft_lstadd_front(stack_b, stack_a);
	if (flag == 'a')
		write(1, "pa\n", 3);
	else if (flag == 'b')
		write(1, "pb\n", 3);
}

void	swap(t_list **head, char c)
{
	t_list	*tmp;

	if (!*head || !(*head)->next)
		return ;
	tmp = *head;
	*head = (*head)->next;
	tmp->next = tmp->next->next;
	(*head)->next = tmp;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}

void	rotate(t_list **head, char c)
{
	t_list	*last;
	t_list	*new_head;

	if (!*head || !(*head)->next)
		return ;
	new_head = (*head)->next;
	last = ft_lstlast(*head);
	last->next = *head;
	(*head)->next = NULL;
	*head = new_head;
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b, char c)
{
	swap(stack_a, 'a');
	swap(stack_b, 'b');
	if (c == 's')
		write(1, "ss\n", 3);
}

void ft_error(t_list **stack, char **arr)
{
	write(2, "Error", 5);
	free_all(arr);
	ft_lstclear(stack);
	exit(1);
}