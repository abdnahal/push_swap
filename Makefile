CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_atoi.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstlast.c ft_lstnew.c ft_lstsize.c ft_split.c parser.c push_swap.c utils.c algo.c main.c moves.c
B_SRC = checker.c get_next_line.c get_next_line_utils.c ft_atoi.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstlast.c ft_lstnew.c ft_lstsize.c ft_split.c main.c moves.c utils.c
RM = rm -f
OBJ = $(SRC:.c=.o)
B_OBJS = $(B_SRC:.c=.o)
NAME = push_swap
B_NAME = checker

all: $(NAME)

bonus : $(B_NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(B_NAME) : $(B_OBJS)
	$(CC) $(CFLAGS) $(B_OBJS) -o $(B_NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ) $(B_OBJS)

fclean: clean
	$(RM) $(NAME) $(B_NAME)

re: fclean all

.PHONY: all bonus clean fclean re