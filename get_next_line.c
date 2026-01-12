/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnahal <abdnahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:36:48 by abdnahal          #+#    #+#             */
/*   Updated: 2026/01/12 15:07:02 by abdnahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*save;
	ssize_t		n;
	char		*s;

	if (fd > 1024)
		return (NULL);
	while (1)
	{
		s = malloc((size_t)BUFFER_SIZE + 1);
		if (!s)
			return (NULL);
		n = read(fd, s, BUFFER_SIZE);
		if (n <= 0 && (!save || !*save))
		{
			(free(s), free(save), save = NULL);
			return (NULL);
		}
		s[n] = '\0';
		save = ft_strjoin(save, s);
		if (!save)
			return (NULL);
		if (ft_strchr(save, '\n') || n == 0)
			return (extract_line(&save));
	}
}

char	*extract_line(char **save)
{
	char	*s;
	char	*temp;
	int		i;
	int		k;

	i = 0;
	while ((*save)[i] && (*save)[i] != '\n')
		i++;
	s = ft_substr(*save, 0, i + 1);
	if (!s)
		return (ft_return(save));
	if ((*save)[i] == '\n')
		i++;
	k = 0;
	while ((*save)[i + k])
		k++;
	temp = malloc(k + 1);
	if (!temp)
		return (ft_return(save));
	ft_strcpy(temp, &(*save)[i]);
	free(*save);
	*save = temp;
	return (s);
}

char	*ft_return(char **save)
{
	free(*save);
	*save = NULL;
	return (NULL);
}

void	ft_strcpy(char *dest, char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

// int	main(void)
// {
// 	int fd;
// 	char *line;
// 	//fd = open("file.txt", O_RDWR);
// 	while ((line = get_next_line(0)))
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// }