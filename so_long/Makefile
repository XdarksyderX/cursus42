NAME=so_long
SRC=src/helpers/error.c src/helpers/util.c src/helpers/clean.c src/main.c src/map/get_next_line.c src/map/map_checker.c src/map/map_parser.c src/map/map_utils.c src/map/map_solvable.c src/rendering/init_mlx.c src/rendering/render.c src/controls/hooks.c src/controls/move.c

OBJ_DIR = ./obj
OBJ=$(SRC:%.c=$(OBJ_DIR)/%.o)

CC=gcc
CFLAGS=-Wall -Wextra -g

LIBFT_DIR = ./libs/libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
    INCLUDES = -I/usr/include -I ./libs/mlx -I$(LIBFT_DIR)
    MLX_URL = https://github.com/42Paris/minilibx-linux.git
    MLX_LIB = mlx_Linux
else
    INCLUDES = -I/opt/X11/include -I ./libs/mlx -I$(LIBFT_DIR)
    MLX_URL = https://cdn.intra.42.fr/document/document/22152/minilibx_opengl.tgz
    MLX_LIB = mlx
endif

MLX_DIR = ./libs/mlx

ifeq ($(UNAME), Linux)
    MLX_FLAGS = -L$(MLX_DIR) -l$(MLX_LIB) -L/usr/lib/X11 -lXext -lX11 -L$(LIBFT_DIR) -lft
else
    MLX_FLAGS = -L$(MLX_DIR) -l$(MLX_LIB) -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit -L$(LIBFT_DIR) -lft
endif

all: $(LIBFT_LIB) $(MLX_LIB) $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
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
	@rm -rf $(OBJ_DIR)
	@make clean -C $(MLX_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
