#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef struct s_list{
    int num;
    int index;
    struct s_list *next;
    struct s_list *prv;
}   t_list;

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	**ft_split(char *str, char *charset);
t_list				*ft_lstnew(int num);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
int	ft_atoi(const char *nptr);


#endif

