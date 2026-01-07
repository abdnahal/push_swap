/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnahal <abdnahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:19:56 by abdnahal          #+#    #+#             */
/*   Updated: 2026/01/07 14:49:27 by abdnahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    int i;
    char **arr;
    t_list *head;

    if (ac < 2)
        return (0);
    arr = ft_split(av[1], "         \v\f\r\n");
    i = 0;
    head = NULL;
    while (arr[i])
        ft_lstadd_back(&head, ft_lstnew(ft_atoi(arr[i++])));
    i = 0;
    while (arr[i])
        free(arr[i++]);
    free(arr);
    indexing(head);
    push_swap(&head, NULL);
}

int is_sorted(t_list *stack)
{
    while (stack->next)
    {
        if (stack->num > stack->next->num)
            return (0);
        stack = stack->next;
    }
    return (1);
}

void reverse_rotate(t_list **stack, char c)
{
    t_list *tmp;

    tmp = *stack; 
    while (tmp->next->next)
        tmp = tmp->next;
    tmp->next->next = *stack;
    tmp->next = NULL;
    if (c == 'a')
        write(1, "rra\n", 4);
    else 
        write(1, "rrb\n", 4);
}

void rr(t_list **stack_a, t_list **stack_b)
{
    rotate(stack_a, 'a');
    rotate(stack_b, 'b');
    write(1, "rr\n", 3);
}

void sort_3(t_list **stack_a)
{
    t_list *tmp;

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
