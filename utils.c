/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnahal <abdnahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:17:57 by abdnahal          #+#    #+#             */
/*   Updated: 2026/01/05 14:44:38 by abdnahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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