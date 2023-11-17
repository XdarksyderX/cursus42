NAME=push_swap
CC = gcc
CFLAGS = -Wall -Wextra

SRC=src/main.c src/free.c src/operations/push.c src/operations/rev_rot.c src/operations/rotate.c src/operations/swap.c src/parser.c src/parser2.c src/sort/helpers.c src/sort/metadata_utils2.c src/sort/metadata_utils.c src/sort/moving_utils.c src/sort/sort.c src/stack.c 
OBJ=$(SRC:src/%.c=obj/%.o)

SRC_BONUS=src/checker/get_next_line.c src/checker/main.c src/free.c src/operations/push.c src/operations/rev_rot.c src/operations/rotate.c src/operations/swap.c src/parser.c src/parser2.c src/stack.c src/sort/helpers.c src/sort/metadata_utils2.c src/sort/metadata_utils.c src/sort/moving_utils.c
OBJ_BONUS=$(SRC_BONUS:src/%.c=obj/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C libft
	cp libft/libft.a .
	$(CC) $(CFLAGS) $(OBJ) libft.a -o $(NAME)

obj/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C libft
	rm -f $(OBJ) libft.a
	rm -rf obj

fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(NAME)

re: fclean all

bonus: $(OBJ_BONUS)
	$(MAKE) -C libft
	cp libft/libft.a .
	$(CC) $(CFLAGS) $(OBJ_BONUS) libft.a -o checker

.PHONY: all clean fclean re bonus
