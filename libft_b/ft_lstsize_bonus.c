/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnahal <abdnahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:15:22 by abdnahal          #+#    #+#             */
/*   Updated: 2025/10/21 14:01:30 by abdnahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*curr;
	int		size;

	if (!lst)
		return (0);
	size = 0;
	curr = lst;
	while (curr)
	{
		size++;
		curr = curr->next;
	}
	return (size);
}

// int main()
// {
//     t_list beef;
//     t_list streak;
//     t_list dead;
//     t_list fuckoff;
//     beef.next = &streak;
//     streak.next = &dead;
//     dead.next = &fuckoff;
//     fuckoff.next = NULL;
//     printf("%d\n", ft_lstsize(&beef));
// }