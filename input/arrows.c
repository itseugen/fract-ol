/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:13:21 by eweiberl          #+#    #+#             */
/*   Updated: 2023/07/05 13:58:41 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	arrow_keys(int keycode, void *param)
{
	// t_params	*params;
	// t_window	*window;
	t_fractol	*test;
	double		movement;

	test = (t_fractol *)param;
	// window = &((t_fractol *)param)->window;
	// params = &((t_fractol *)param)->params;
	printf("zoom: %f\n", test->params.zoom);
	if (keycode == MLX_KEY_RIGHT)
	{
		//movement = 0.1 / params->zoom;
		// params->xmin += movement;
		// params->xmax += movement;
		// printf("Right key pressed: xmin: %f, xmax: %f, movement: %f\n", params->xmin, params->xmax, movement);
		// mandelbrot(*window, *params);
	}
}
