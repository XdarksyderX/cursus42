SRC = src/format_handlers/ft_char_handler.c src/format_handlers/ft_format.c src/format_handlers/ft_hex_handler.c src/format_handlers/ft_int_handler.c src/format_handlers/ft_pointer_handler.c src/format_handlers/ft_string_handler.c src/format_handlers/ft_unsigned_handler.c src/ft_printf.c src/utils/ft_ceil.c src/utils/ft_count.c src/utils/ft_is_space.c src/utils/ft_put.c
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a

CC = gcc
FLAGS = -Wall -Wextra -Werror
INCLUDES = -I ./includes

all : $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar -r $(NAME) $(OBJ)

$(OBJ): %.o: %.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(OBJ)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all

.PHONY: clean fclean re
