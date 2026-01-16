/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnahal <abdnahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:36:45 by abdnahal          #+#    #+#             */
/*   Updated: 2026/01/16 10:19:00 by abdnahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

void	ft_strcpy(char *dest, char *src);
char	*ft_return(char **save);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	f_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
int		ft_strchr(const char *s, char c);
char	*extract_line(char **save);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif