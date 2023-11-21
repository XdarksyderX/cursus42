NAME=so_long
SRC=
OBJ=$(SRC:.c=.o)

CC=gcc
CFLAGS=-Wall -Wextra -Werror -g

LIBFT_DIR = ./libs/libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	INCLUDES = -I/usr/include -Imlx
	MLX_URL = https://github.com/42Paris/minilibx-linux.git
else
	INCLUDES = -I/opt/X11/include -Imlx
	MLX_URL = https://cdn.intra.42.fr/document/document/22152/minilibx_opengl.tgz
endif

MLX_DIR = ./libs/mlx
MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a

ifeq ($(UNAME), Linux)
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
else
	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

all: $(MLX_LIB) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX_FLAGS)

$(MLX_LIB):
	if [ ! -d "$(MLX_DIR)" ]; then \
		mkdir -p $(MLX_DIR); \
		if [ "$(UNAME)" = "Linux" ]; then \
			git clone $(MLX_URL) $(MLX_DIR); \
		else \
			curl -L $(MLX_URL) | tar -C $(MLX_DIR) --strip-components=1 -xzf -; \
		fi \
	fi
	@make -C $(MLX_DIR)

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

clean:
	@rm -f $(OBJ)
	@make clean -C $(MLX_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re