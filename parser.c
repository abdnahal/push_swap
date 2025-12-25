#include "push_swap.h"

int main(int ac, char **av)
{
    int i;
    char **arr;
    t_list *head;

    if (ac <= 2)
        return (0);
    arr = ft_split(av[1], " \t\v");
    i = 0;
    head = NULL;
    while (arr[i++])
        ft_lstadd_back(&head, ft_lstnew(ft_atoi(arr[i])));
}

