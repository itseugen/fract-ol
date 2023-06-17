/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:34:05 by eweiberl          #+#    #+#             */
/*   Updated: 2023/06/17 18:37:21 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

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
	if (keycode == 256)
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
	mlx_terminate(window->mlx);
	exit(0);
}

static void	zoomdetec(double xdelta, double ydelta, void *param)
{
	t_zoom		*zoom;
	t_window	*window;

	window = (t_window *)param;
	zoom = (t_zoom *)param;
	(void)xdelta;
	if (ydelta > 0)
		zoom->zoom = zoom->zoom + 0.1;
	else if (ydelta < 0)
		zoom->zoom = zoom->zoom - 0.1;
	mlx_image_t *new_img = mlx_new_image(window->mlx, WIDTH, HEIGHT);
	window->img = new_img;
	mandelbrot(*window, *zoom);
	mlx_image_to_window(window->mlx, window->img, 0, 0);
	window->img->instances[0].z += 1;
}
