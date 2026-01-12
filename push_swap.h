#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef struct s_list{
    int num;
    int index;
    struct s_list *next;
}   t_list;

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	**ft_split(char *str, char *charset);
t_list				*ft_lstnew(int num);
void				ft_lstadd_front(t_list **lst, t_list **new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst);
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
int	ft_atoi(const char *nptr);
void ss(t_list **stack_a, t_list **stack_b);
void rotate(t_list **head, char c);
void   swap(t_list **head, char c);
void push(t_list **stack_a, t_list **stack_b, char c);
void sort_3(t_list **stack_a);
void    push_swap(t_list **stack_a, t_list **stack_b);
void reverse_rotate(t_list **stack, char c);
int is_sorted(t_list *stack);
void sort_5(t_list **stack_a, t_list **stack_b);
void printer(t_list *stack);
void indexing(t_list *stack);
int max_index(t_list *stack);
void sort_push_b(t_list **stack_a, t_list **stack_b);
void    sort_push_a(t_list **stack_a, t_list **stack_b, int min, int max);
t_list *locate_index(t_list *head, int index);
int    is_in(t_list *stack, int min, int max);
int get_pos(t_list *stack, int index);
int get_pos_range(t_list *stack, int min, int max);
void check_duplicates(t_list *head);
void    checker(t_list **stack_a, t_list **stack_b);
void    checker2(t_list **stack_a, t_list **stack_b, char *str);

#endif
