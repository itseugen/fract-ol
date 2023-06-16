/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 09:35:59 by eweiberl          #+#    #+#             */
/*   Updated: 2023/06/16 15:57:23 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *argv[])
{
	t_window	window;
	/*Void for now, add handeling later*/
	(void)argc;
	(void)argv;
	window.mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (window.mlx == NULL)
		exit (1);
	window.img = mlx_new_image(window.mlx, WIDTH, HEIGHT);
	mlx_image_to_window(window.mlx, window.img, 0, 0);
	//window.win = mlx_new_window(window.mlx, WIDTH, HEIGHT, "fract-ol");
	hooks(window);
	/*temp*/
	mandelbrot(window);
	mlx_loop(window.mlx);
	return (0);
}
