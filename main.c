#include "push_swap.h"

void check_duplicates(t_list *head)
{
    t_list *temp;
    while (head)
    {
        temp = head->next;
        while (temp)
        {
            if (head->num == temp->num)
            {
                ft_lstclear(&head);
                write(2, "ERROR", 5);
                exit(EXIT_FAILURE);
            }
            temp = temp->next;
        }
        head = head->next;
    }
}