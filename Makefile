# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 14:42:18 by eweiberl          #+#    #+#              #
#    Updated: 2023/06/16 09:24:58 by eweiberl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract-ol

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SOURCE = main.c

LIBFT_GIT = https://github.com/itseugen/c_library
LIBFT_DIR = ./libft
LIBFT_LIB = libft.a
LIBFT	  = $(LIBFT_DIR)/$(LIBFT_LIB)

all: $(NAME)

$(NAME): $(SOURCE)
	$(CC) $(CFLAGS) -o $(NAME) $(SOURCE) $(LIBFT) -L./mlx -lmlx -framework OpenGL -framework AppKit

$(LIBFT):
	git clone $(LIBFT_GIT) $(LIBFT_DIR); make -C $(LIBFT_DIR)

libclean:
	rm -rf $(LIBFT_DIR)

clean:
	@rm -f $(OBJS)
	@cd libft && make clean

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re clean_obj
