#include "push_swap.h"

void printer(t_list *stack)
{
    while (stack)
    {
        printf("Num: %d, Index: %d\n", stack->num, stack->index);
        stack = stack->next;
    }
}