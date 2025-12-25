/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnahal <abdnahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 06:53:32 by abdnahal          #+#    #+#             */
/*   Updated: 2025/10/26 09:37:21 by abdnahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	int i, (sign), (nbr);
	i = 0;
	sign = 1;
	nbr = 0;
	while (nptr[i])
	{
		if (nptr[i] == '-' || nptr[i] == '+')
		{
			if (nptr[i] == '-')
				sign *= -1;
			i++;
		}
        if (!(nptr[i] >= '0' && nptr[i] <= '9'))
        {
            write(2, "ERROR", 5);
            exit(1);
        }
		while (nptr[i] >= '0' && nptr[i] <= '9')
			nbr = nbr * 10 + nptr[i++] - '0';
		break ;
	}
	return (nbr * sign);
}
