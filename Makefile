CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_atoi.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstlast.c ft_lstnew.c ft_lstsize.c ft_split.c parser.c push_swap.c utils.c algo.c main.c
RM = rm -f
OBJ = $(SRC:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all