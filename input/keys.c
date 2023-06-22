/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:34:05 by eweiberl          #+#    #+#             */
/*   Updated: 2023/06/22 15:45:19 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <stdio.h>

static int	close_window(void *param);
static int	close_keys(int keycode, void *param);
static void	zoomdetec(double xdelta, double ydelta, void *param);
static void	zoom_on_cursor(t_params *params, t_window *window, int x, int y);

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
	t_params	*params;
	t_window	*window;
	int32_t		x;
	int32_t		y;

	window = &((t_fractol *)param)->window;
	params = &((t_fractol *)param)->params;
	(void)xdelta;
	params->old_zoom = params->zoom;
	if (ydelta > 0)
		params->zoom = params->zoom + 0.05;
	else if (ydelta < 0)
		params->zoom = params->zoom - 0.05;
	mlx_get_mouse_pos(window->mlx, &x, &y);
	// if (x >= 0 && y >= 0 && x <= WIDTH && y <= HEIGHT)
	// 	zoom_on_cursor(params, window, x, y);
	printf("Current Zoom value: %f\n", params->zoom);
	printf("Mouse Position: (%d, %d)\n", x, y);
	mandelbrot3(*window, *params);
}
/*
void mlx_get_mouse_pos(mlx_t* mlx, int32_t* x, int32_t* y);
*/

// static void	zoom_on_cursor(t_params *params, t_window *window, int x, int y)
// {
// 	double	zoom_ratio;
// 	double	diff_width;
// 	double	diff_height;
// 	double desiredwidth = WIDTH / params->zoom;
// 	double desiredheight = HEIGHT / params->zoom;

// 	(void)window;
// 	zoom_ratio = params->zoom / params->old_zoom;
// 	diff_width = WIDTH / zoom_ratio - WIDTH;
// 	diff_height = HEIGHT / zoom_ratio - HEIGHT;
// 	params->xmin = params->xmin - (desiredwidth / 2.0);
// 	params->xmax = params->xmax + (desiredwidth / 2.0);
// 	params->ymin = params->ymin - (desiredheight / 2.0);
// 	params->ymax = params->ymax + (desiredheight / 2.0);
// }
