/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:34:05 by eweiberl          #+#    #+#             */
/*   Updated: 2023/07/11 16:51:05 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	close_window(void *param);
static int	keys(int keycode, void *param);
static void	zoomdetec(double xdelta, double ydelta, void *param);
static void	zoom_on_cursor(t_params *params, int x, int y);

/// @brief handles input
/// @param window gets the window variables to handle inputs
void	hooks(t_fractol *fractol)
{
	mlx_close_hook(fractol->window.mlx, (void *)close_window, NULL);
	mlx_key_hook(fractol->window.mlx, (void *)keys, NULL);
	mlx_loop_hook(fractol->window.mlx, key_handle, fractol);
	mlx_scroll_hook(fractol->window.mlx, zoomdetec, fractol);
}

/// @brief Closes the window on 'ESC'
/// @param keycode the key pressed
static int	keys(int keycode, void *param)
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

	window = (t_window *)param;
	exit(0);
}

/*
	// mlx_delete_image(window->mlx, window->img);
	// mlx_close_window(window->mlx);
	// mlx_terminate(window->mlx);
*/

static void	zoomdetec(double xdelta, double ydelta, void *param)
{
	t_params	*params;
	int32_t		x;
	int32_t		y;

	params = &((t_fractol *)param)->params;
	(void)xdelta;
	if (ydelta > 0)
	{
		params->zoom = params->zoom + 0.05;
		params->zoomin++;
	}
	else if (ydelta < 0)
	{
		params->zoom = params->zoom - 0.05;
		params->zoomout++;
	}
	params->xmin = -2 / pow(1.05, params->zoomin) * pow(0.95, params->zoomout);
	params->xmax = 2 / pow(1.05, params->zoomin) * pow(0.95, params->zoomout);
	params->ymin = -2 / pow(1.05, params->zoomin) * pow(0.95, params->zoomout);
	params->ymax = 2 / pow(1.05, params->zoomin) * pow(0.95, params->zoomout);
	mlx_get_mouse_pos(((t_fractol *)param)->window.mlx, &x, &y);
	if (x >= 0 && y >= 0 && x <= WIDTH && y <= HEIGHT && params->zo_mouse == 0)
		zoom_on_cursor(params, x, y);
	choose_set(((t_fractol *)param)->window, *params);
}

/*
void mlx_get_mouse_pos(mlx_t* mlx, int32_t* x, int32_t* y);
	printf("Current Zoom value: %LF\n", params->zoom);
	printf("Mouse Position: (%d, %d)\n", x, y);
	printf("xmin: %LF,\nxmax: %LF\nymin: %LF\n ymax:%LF\n",
		params->xmin, params->xmax, params->ymin, params->ymax);
*/

static void	zoom_on_cursor(t_params *params, int x, int y)
{
	long double	xrange;
	long double	xmovepp;
	long double	yrange;
	long double	ymovepp;

	xrange = (params->xmax + params->xmove) - (params->xmin + params->xmove);
	xmovepp = xrange / WIDTH;
	yrange = (params->ymax + params->xmove) - (params->ymin + params->xmove);
	ymovepp = yrange / HEIGHT;
	params->xmove = params->xmove + (xmovepp * (x - (WIDTH / 2)));
	params->ymove = params->ymove + (ymovepp * (y - (HEIGHT / 2)));
	params->xmin = params->xmin + params->xmove;
	params->xmax = params->xmax + params->xmove;
	params->ymin = params->ymin + params->ymove;
	params->ymax = params->ymax + params->ymove;
}
