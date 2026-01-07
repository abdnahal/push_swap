/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnahal <abdnahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:17:57 by abdnahal          #+#    #+#             */
/*   Updated: 2026/01/07 16:15:33 by abdnahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int max_index(t_list *stack)
{
    int index;
    while (stack)
    {
        if (stack->next && stack->index > stack->next->index)
            index = stack->index;
        stack = stack->next;
    }
    return (index);
}

void sort_5(t_list **stack_a, t_list **stack_b)
{
    if (is_sorted(*stack_a))
        return ;
    push(stack_a, stack_b, 'b');
    push(stack_a, stack_b, 'b');
    sort_3(stack_a);
    push(stack_a, stack_b, 'a');
    sort_3(stack_a);
    push(stack_a, stack_b, 'a');
}

void indexing(t_list *stack)
{
    t_list *curr;
    t_list *head;
    
    head = stack;
    while (stack)
    {
        stack->index = 0;
        curr = head;
        while (curr)
        {
            if (stack->num > curr->num)
                stack->index += 1;
            curr = curr->next;
        }
        stack = stack->next;
    }
}

void    sort_push_a(t_list **stack_a, t_list **stack_b, int min, int max)
{
    t_list *curr;
    while (*stack_a)
    {
        curr = *stack_a;
        if (curr->index >= min && curr->index <= max)
        {
            if (curr->index < max - min / 2)
            {
                push(stack_a, stack_b, 'b');
                rotate(stack_b, 'b');
            }
            else
                push(stack_a, stack_b, 'b');
            min++;
            max++;
        }
    }
}

void sort_push_b(t_list **stack_a, t_list **stack_b)
{
    int max;

    max = max_index(*stack_b);
}