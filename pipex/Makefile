# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: migarci2 <migarci2@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 16:17:36 by migarci2          #+#    #+#              #
#    Updated: 2023/09/26 16:17:39 by migarci2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC = src/pipex.c src/command.c src/main.c
OBJ = $(SRC:.c=.o)

SRC_BONUS= src/pipex_bonus.c src/command_bonus.c src/main_bonus.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

libft/libft.a:
	$(MAKE) -C libft

$(NAME): libft/libft.a $(OBJ)
	cp libft/libft.a .
	$(CC) $(CFLAGS) $(OBJ) libft.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: libft/libft.a $(OBJ_BONUS)
	cp libft/libft.a .
	$(CC) $(CFLAGS) $(OBJ_BONUS) libft.a -o $(NAME)

.PHONY: clean fclean re rebonus

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)
	$(MAKE) clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f libft.a
	$(MAKE) fclean -C libft

re: fclean all

rebonus: fclean bonus
