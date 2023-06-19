/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:34:05 by eweiberl          #+#    #+#             */
/*   Updated: 2023/06/19 15:25:26 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <stdio.h>

static int	close_window(void *param);
static int	close_keys(int keycode, void *param);
static void	zoomdetec(double xdelta, double ydelta, void *param);

/// @brief handles input
/// @param window gets the window variables to handle inputs
void	hooks(t_fractol *fractol)
{
	mlx_close_hook(fractol->window.mlx, (void *)close_window, NULL);
	mlx_key_hook(fractol->window.mlx, (void *)close_keys, NULL);
	mlx_scroll_hook(fractol->window.mlx, zoomdetec, fractol);
}

/// @brief Closes the window on 'ESC'
/// @param keycode the key pressed
static int	close_keys(int keycode, void *param)
{
	if (keycode == MLX_KEY_ESCAPE)
		close_window(param);
	return (0);
}

/// @brief Frees everything necessary before closing the window
/// @param void might be replaced in the future
static int	close_window(void *param)
{
	t_window	*window;

	/*Add frees if needed*/
	window = (t_window *)param;
	mlx_delete_image(window->mlx, window->img);
	mlx_close_window(window->mlx);
	mlx_terminate(window->mlx);
	exit(0);
}

static void	zoomdetec(double xdelta, double ydelta, void *param)
{
	t_params		*params;
	t_window		*window;

	window = &((t_fractol *)param)->window;
	params = &((t_fractol *)param)->params;
	(void)xdelta;
	if (ydelta > 0)
		params->zoom = params->zoom + 0.05;
	else if (ydelta < 0)
		params->zoom = params->zoom - 0.05;
	//mlx_image_t *new_img = mlx_new_image(window->mlx, WIDTH, HEIGHT);
	printf("Current Zoom value: %f\n", params->zoom);
	//window->img = new_img;
	mandelbrot(*window, *params);
}
