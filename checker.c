#include "push_swap.h"
#include "get_next_line.h"

void    checker(t_list **stack_a, t_list **stack_b)
{
    char *str;

    str = get_next_line(0);
    if (str)
    {
        if (!(ft_strncmp(str, "ra\n", 3)))
            rotate(stack_a, 'a');
        else if(!(ft_strncmp(str, "rb\n", 3)))
            rotate(stack_b, 'b');
        else if(!(ft_strncmp(str, "sa\n", 3)))
            swap(stack_a, 'a');
        else if(!(ft_strncmp(str, "sb\n", 3)))
            swap(stack_b, 'a');
        else if (!(ft_strncmp(str, "rra\n", 3)))
            reverse_rotate(stack_a, 'a');
        else if (!(ft_strncmp(str, "rrb\n", 3)))
            reverse_rotate(stack_b, 'b');
        else
            checker2(stack_a, stack_b, str);
    }
    else if (is_sorted(*stack_a) && !*stack_b)
        write(1, "OK\n", 3);
    else 
        write(1, "KO\n", 3);
}

void    checker2(t_list **stack_a, t_list **stack_b, char *str)
{
    if (!(ft_strncmp(str, "rrr\n", 3)))
    {
        reverse_rotate(stack_a, 'a');
        reverse_rotate(stack_b, 'b');
    }
    else if (!(ft_strncmp(str, "rrr\n", 3)))
    {
        swap(stack_a, 'a');
        swap(stack_b, 'b');
    }
    else    
        write(2, "ERROR", 5);
}


int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int main()
{
    while (true)
    {
        
    }
    
}