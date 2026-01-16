/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnahal <abdnahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:13:17 by abdnahal          #+#    #+#             */
/*   Updated: 2026/01/16 17:41:18 by abdnahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"

void	checker2(t_list **stack_a, t_list **stack_b, char *str)
{
	if (!(ft_strncmp(str, "ra\n", 3)))
		rotate(stack_a, 'h');
	else if (!(ft_strncmp(str, "rb\n", 3)))
		rotate(stack_b, 'h');
	else if (!(ft_strncmp(str, "sa\n", 3)))
		swap(stack_a, 'x');
	else if (!(ft_strncmp(str, "sb\n", 3)))
		swap(stack_b, 'x');
	else if (!(ft_strncmp(str, "rra\n", 3)))
		reverse_rotate(stack_a, 'k');
	else if (!(ft_strncmp(str, "rrb\n", 3)))
		reverse_rotate(stack_b, 'k');
	else if (!(ft_strncmp(str, "rrr\n", 3)))
		rrr(stack_a, stack_b);
	else if (!(ft_strncmp(str, "ss\n", 3)))
		ss(stack_a, stack_b, 'a');
	else
		checker3(stack_a, stack_b, str);
}

void	checker(t_list **stack_a, t_list **stack_b, char **arr)
{
	char	*str;

	check_duplicates(*stack_a, arr);
	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		checker2(stack_a, stack_b, str);
		free(str);
		str = NULL;
	}
	if (!is_sorted(*stack_a) || *stack_b)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
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

int	main(int ac, char **av)
{
	char	**arr;
	t_list	*head;
	t_list	*stack_b;

	int i, (k);
	if (ac < 2)
		return (0);
	i = 1;
	head = NULL;
	while (i < ac)
	{
		k = 0;
		arr = ft_split(av[i], "         \v\f\r\n");
		while (arr[k])
			ft_lstadd_back(&head, ft_lstnew(ft_atoi(arr[k++], &head, arr)));
		free_all(arr);
		arr = NULL;
		i++;
	}
	stack_b = NULL;
	checker(&head, &stack_b, arr);
}

void	checker3(t_list **stack_a, t_list **stack_b, char *str)
{
	if (!(ft_strncmp(str, "pa\n", 3)))
		push(stack_a, stack_b, 'a', '2');
	else if (!(ft_strncmp(str, "pb\n", 3)))
		push(stack_a, stack_b, 'b', '2');
	else
	{
		ft_lstclear(stack_a);
		ft_lstclear(stack_b);
		free(str);
		write(2, "Error\n", 6);
		exit(1);
	}
}

// void	free_all(char **arr)
// {
// 	int	i;

// 	i = 0;
// 	while (arr[i])
// 		free(arr[i++]);
// 	free(arr);
// }
