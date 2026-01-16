/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnahal <abdnahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:19:56 by abdnahal          #+#    #+#             */
/*   Updated: 2026/01/16 17:18:25 by abdnahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		arr = ft_split(av[i], "         \t\v\f\r\n");
		if (arr)
			while (arr[k])
				ft_lstadd_back(&head, ft_lstnew(ft_atoi(arr[k++], &head, arr)));
		free_all(arr);
		arr = NULL;
		i++;
	}
	(check_duplicates(head, arr), indexing(head));
	stack_b = NULL;
	push_swap(&head, &stack_b);
}
