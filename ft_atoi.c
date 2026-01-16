/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnahal <abdnahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 06:53:32 by abdnahal          #+#    #+#             */
/*   Updated: 2026/01/16 11:13:05 by abdnahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *nptr, t_list **stack, char **arr)
{
	long i, (sign), (nbr);
	i = 0;
	sign = 1;
	nbr = 0;
	if (ft_strlen(nptr) > 10)
		ft_error(stack, arr);	
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (!(nptr[i+1] >= '0' && nptr[i+1] <= '9'))
			ft_error(stack, arr);
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		nbr = nbr * 10 + nptr[i++] - '0';
	if (nptr[i] && !(nptr[i] >= '0' && nptr[i] <= '9'))
		ft_error(stack, arr);
	return (nbr * sign);
}

int ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
