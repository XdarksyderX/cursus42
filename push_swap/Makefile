NAME=push_swap
CC = gcc
CFLAGS = -Wall -Wextra

SRC=src/main.c src/free.c src/operations/push.c src/operations/rev_rot.c src/operations/rotate.c src/operations/swap.c src/parser.c src/parser2.c src/sort/helpers.c src/sort/helpers2.c src/sort/helpers3.c src/sort/sort.c src/stack.c 
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C libft
	cp libft/libft.a .
	$(CC) $(CFLAGS) $(OBJ) libft.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C libft
	rm -f $(OBJ) libft.a

fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re