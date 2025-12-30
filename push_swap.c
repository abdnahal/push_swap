#include "push_swap.h"

void    push_swap(t_list **stack_a, t_list **stack_b)
{
    if (ft_lstsize(*stack_a) <= 5)
        small_sort(stack_a, stack_b);
    // ft_lstclear(&stack_a);
    // ft_lstclear(&stack_b);
}

void push(t_list **stack_a, t_list **stack_b, char c)
{
    if (c == 'a')
    {
        ft_lstadd_front(stack_a, *stack_b);
        write(1, "pa\n", 3);
    }
    else
    {
        ft_lstadd_front(stack_b, *stack_a);
        write(1, "pb\n", 3);
    }
}

void    swap(t_list **head, char c)
{
    t_list *tmp;
    
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

void rotate(t_list **head, char c)
{
    t_list *last;
    t_list *new_head;

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

void ss(t_list **stack_a, t_list **stack_b)
{
    swap(stack_a, 'a');
    swap(stack_b, 'b');
    write(1, "ss\n", 3);
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