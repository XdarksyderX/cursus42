NAME = minitalk

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC = src/client.c src/error.c src/server.c
OBJ = $(SRC:.c=.o)

SRC_BONUS = bonus/src/client_bonus.c bonus/src/error_bonus.c bonus/src/server_bonus.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME):libftprintf.a server client

bonus: libftprintf.a server_bonus client_bonus

libftprintf.a:
	$(MAKE) -C ./ft_printf
	mv ./ft_printf/libftprintf.a .

server: src/server.o src/error.o
	$(CC) $(CFLAGS) src/server.o src/error.o libftprintf.a -o server

client: src/client.o src/error.o
	$(CC) $(CFLAGS) src/client.o src/error.o libftprintf.a -o client

server_bonus: bonus/src/error_bonus.o bonus/src/server_bonus.o
	$(CC) $(CFLAGS) bonus/src/error_bonus.c bonus/src/server_bonus.c libftprintf.a -o server_bonus

client_bonus: bonus/src/client_bonus.o bonus/src/error_bonus.o
	$(CC) $(CFLAGS) bonus/src/client_bonus.o bonus/src/error_bonus.o libftprintf.a -o client_bonus

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean fclean re

clean:
	$(MAKE) clean -C ./ft_printf
	rm -rf $(OBJ)
	rm -rf $(OBJ_BONUS)
	rm -rf libftprintf.a

fclean : clean
	rm -rf server client server_bonus client_bonus

re : fclean all

