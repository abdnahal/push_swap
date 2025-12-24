/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnahal <abdnahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 10:20:33 by abdnahal          #+#    #+#             */
/*   Updated: 2025/10/25 17:15:34 by abdnahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*curr;
	t_list	*head;
	void	*cont;

	if (!lst || !f || !del)
		return (NULL);
	head = NULL;
	while (lst)
	{
		cont = f(lst->content);
		curr = ft_lstnew(cont);
		if (!curr)
		{
			ft_lstclear(&head, del);
			del(cont);
			return (NULL);
		}
		ft_lstadd_back(&head, curr);
		lst = lst->next;
	}
	return (head);
}
