# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 14:42:18 by eweiberl          #+#    #+#              #
#    Updated: 2023/07/04 13:59:35 by eweiberl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

USER = eweiberl
CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCE = main.c input/keys.c input/help.c
SOURCE += fractals/mandelbrot.c fractals/julia.c fractals/mandelbrot2.c fractals/mandelbrot3.c
SOURCE += colours/intergrad.c colours/colours.c colours/rainbow.c
SOURCE += utils/ft_strtolower.c utils/ft_atof.c

LIBFT_GIT = https://github.com/itseugen/c_library
LIBFT_DIR = ./libft
LIBFT_LIB = libft.a
LIBFT	  = $(LIBFT_DIR)/$(LIBFT_LIB)

WIDTH = 1000
HEIGHT = 1000


all: $(NAME)

$(NAME): $(SOURCE) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(SOURCE) $(LIBFT) -D WIDTH=$(WIDTH) -D HEIGHT=$(HEIGHT) ./mlx/build/libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -framework Cocoa -framework OpenGL -framework IOKit

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
