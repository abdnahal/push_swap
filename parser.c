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
    push_swap(&head, NULL);
    while (head)
    {
        printf("%d\n", head->num);
        head = head->next;
    }
    
}

void rr(t_list **stack_a, t_list **stack_b)
{
    rotate(stack_a, 'n');
    rotate(stack_b, 'n');
    write(1, "rr\n", 3);
}

void small_sort(t_list **stack_a, t_list **stack_b)
{
    int swapped;
    t_list **p;

    if (!stack_a || !*stack_a)
        return;
    do
    {
        swapped = 0;
        p = stack_a;
        while (*p && (*p)->next)
        {
            if ((*p)->num > (*p)->next->num)
            {
                swap(p, 'a');
                swapped = 1;
            }
            /* advance p to the next node's pointer (works after swap or not) */
            p = &((*p)->next);
        }
    } while (swapped);
}
