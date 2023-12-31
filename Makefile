# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 14:42:18 by eweiberl          #+#    #+#              #
#    Updated: 2023/07/11 18:31:18 by eweiberl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

MLX = ./mlx/build/libmlx42.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCE = main.c input/keys.c input/help.c input/arrows.c input/keys2.c
SOURCE += fractals/mandelbrot.c fractals/julia.c fractals/choose_set.c fractals/burningship.c
SOURCE += colours/intergrad.c colours/colours.c colours/rainbow.c colours/shifting.c
SOURCE += utils/ft_strtolower.c utils/ft_atof.c
SOURCE += variables/initvals.c variables/stdvals.c

LIBFT_GIT = https://github.com/itseugen/c_library
LIBFT_DIR = ./libft
LIBFT_LIB = libft.a
LIBFT	  = $(LIBFT_DIR)/$(LIBFT_LIB)

WIDTH = 1000
HEIGHT = 1000

all: $(NAME)

$(NAME): $(SOURCE) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(SOURCE) $(LIBFT) -D WIDTH=$(WIDTH) -D HEIGHT=$(HEIGHT) ./mlx/build/libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -framework Cocoa -framework OpenGL -framework IOKit

$(MLX):
	@cd mlx && cmake -B build && cmake --build build -j4

nflag: $(SOURCE) $(LIBFT)
	$(CC) -o $(NAME) $(SOURCE) $(LIBFT) -D WIDTH=$(WIDTH) -D HEIGHT=$(HEIGHT) ./mlx/build/libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -framework Cocoa -framework OpenGL -framework IOKit

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
