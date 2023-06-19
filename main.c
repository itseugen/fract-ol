/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 09:35:59 by eweiberl          #+#    #+#             */
/*   Updated: 2023/06/19 14:41:25 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *argv[])
{
	// t_window	window;
	// t_zoom		zoom;
	t_fractol	fractol;
	/*Void for now, add handeling later*/
	(void)argc;
	(void)argv;
	fractol.params.zoom = 1;
	fractol.window.mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (fractol.window.mlx == NULL)
		exit (1);
	fractol.window.img = mlx_new_image(fractol.window.mlx, WIDTH, HEIGHT);
	mlx_image_to_window(fractol.window.mlx, fractol.window.img, 0, 0);
	hooks(&fractol);
	/*temp*/
	mandelbrot(fractol.window, fractol.params);
	//julia(fractol.window, fractol.params);
	mlx_loop(fractol.window.mlx);
	return (0);
}
