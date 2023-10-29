NAME = fdf

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC=main.c
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): MLX $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)


%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

MLX:
	@$(MAKE) -C mlx_linux

run: all
	./$(NAME)