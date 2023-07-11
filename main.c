/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 09:35:59 by eweiberl          #+#    #+#             */
/*   Updated: 2023/07/11 15:44:27 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
* Values for 16:9
*	fractol.params.xmin = -2.5;
*	fractol.params.xmax = 1;
*	fractol.params.ymin = -1;
*	fractol.params.ymax = 1;
*/

static int	select_set(t_fractol fractol);

int	main(int argc, char *argv[])
{
	t_fractol	fractol;

	init_vals(&fractol, argc, argv);
	fractol.window.mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (fractol.window.mlx == NULL)
		exit (1);
	fractol.window.img = mlx_new_image(fractol.window.mlx, WIDTH, HEIGHT);
	mlx_image_to_window(fractol.window.mlx, fractol.window.img, 0, 0);
	hooks(&fractol);
	select_set(fractol);
	mlx_loop(fractol.window.mlx);
	return (0);
}

/// @brief select which set to display
/// @param fractol 
/// @param argc 
/// @param argv 
/// @return returns 0 on success
static int	select_set(t_fractol fractol)
{
	if (fractol.params.set == JULIA)
		return (julia(fractol.window, fractol.params), 0);
	else if (fractol.params.set == BURNING_SHIP)
		return (burning_ship(fractol.window, fractol.params), 0);
	else
		return (mandelbrot(fractol.window, fractol.params), 0);
}
