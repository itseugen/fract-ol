/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:34:05 by eweiberl          #+#    #+#             */
/*   Updated: 2023/07/07 16:42:45 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	close_window(void *param);
static int	keys(int keycode, void *param);
static void	zoomdetec(double xdelta, double ydelta, void *param);
static void	zoom_on_cursor(t_params *params, t_window *window, int x, int y);

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

	/*Add frees if needed*/
	window = (t_window *)param;
	// mlx_delete_image(window->mlx, window->img);
	// mlx_close_window(window->mlx);
	// mlx_terminate(window->mlx);
	exit(0);
}

static void	zoomdetec(double xdelta, double ydelta, void *param)
{
	t_params	*params;
	t_window	*window;
	int32_t		x;
	int32_t		y;
	double		zoomdif;

	window = &((t_fractol *)param)->window;
	params = &((t_fractol *)param)->params;
	(void)xdelta;
	if (ydelta > 0)
	{
		params->zoom = params->zoom + 0.05;
		params->zoomdif = 1.05;
	}
	else if (ydelta < 0)
	{
		params->zoom = params->zoom - 0.05;
		params->zoomdif = 0.95;
	}
	mlx_get_mouse_pos(window->mlx, &x, &y);
	if (x >= 0 && y >= 0 && x <= WIDTH && y <= HEIGHT && params->zo_mouse == 0)
		zoom_on_cursor(params, window, x, y);
	printf("Current Zoom value: %LF\n", params->zoom);
	printf("Mouse Position: (%d, %d)\n", x, y);
	printf("xmin: %LF,\nxmax: %LF\nymin: %LF\n ymax:%LF\n", params->xmin, params->xmax, params->ymin, params->ymax);
	params->xmin = params->xmin / params->zoomdif;
	params->xmax = params->xmax / params->zoomdif;
	params->ymin = params->ymin / params->zoomdif;
	params->ymax = params->ymax / params->zoomdif;
	choose_set(*window, *params);
}
/*
void mlx_get_mouse_pos(mlx_t* mlx, int32_t* x, int32_t* y);
*/

static void	zoom_on_cursor(t_params *params, t_window *window, int x, int y)
{
	long double	xrange;
	long double	xmovepp;
	long double	xmid;
	long double	yrange;
	long double	ymovepp;
	long double	ymid;

	xmid = WIDTH / 2;
	xrange = params->xmax - params->xmin;
	xmovepp = xrange / WIDTH;
	params->xmin = params->xmin + (xmovepp * (x - xmid));
	params->xmax = params->xmax + (xmovepp * (x - xmid));

	ymid = HEIGHT / 2;
	yrange = params->ymax - params->ymin;
	ymovepp = yrange / HEIGHT;
	params->ymin = params->ymin + (ymovepp * (y - ymid));
	params->ymax = params->ymax + (ymovepp * (y - ymid));
}

// static void	zoomdetec(double xdelta, double ydelta, void *param)
// {
// 	t_params	*params;
// 	t_window	*window;
// 	int32_t		x;
// 	int32_t		y;
// 	double		zoomdif;

// 	window = &((t_fractol *)param)->window;
// 	params = &((t_fractol *)param)->params;
// 	(void)xdelta;
// 	if (ydelta > 0)
// 	{
// 		params->zoom = params->zoom + 0.05;
// 		params->zoomdif = 1.05;
// 	}
// 	else if (ydelta < 0)
// 	{
// 		params->zoom = params->zoom - 0.05;
// 		params->zoomdif = 0.95;
// 	}
// 	params->xmin = -2 / params->zoom;
// 	params->xmax = 2 / params->zoom;
// 	params->ymin = -2 / params->zoom;
// 	params->ymax = 2 / params->zoom;
// 	mlx_get_mouse_pos(window->mlx, &x, &y);
// 	if (x >= 0 && y >= 0 && x <= WIDTH && y <= HEIGHT && params->zo_mouse == 0)
// 		zoom_on_cursor(params, window, x, y);
// 	// else
// 	// {
// 	printf("Current Zoom value: %LF\n", params->zoom);
// 	printf("Mouse Position: (%d, %d)\n", x, y);
// 	printf("xmin: %LF,\nxmax: %LF\nymin: %LF\n ymax:%LF\n", params->xmin, params->xmax, params->ymin, params->ymax);
// 	// params->xmin = params->xmin / params->zoomdif;
// 	// params->xmax = params->xmax / params->zoomdif;
// 	// params->ymin = params->ymin / params->zoomdif;
// 	// params->ymax = params->ymax / params->zoomdif;
// 	// }
// 	choose_set(*window, *params);
// }
// /*
// void mlx_get_mouse_pos(mlx_t* mlx, int32_t* x, int32_t* y);
// */

// static void	zoom_on_cursor(t_params *params, t_window *window, int x, int y)
// {
// 	long double	xrange;
// 	long double	xmovepp;
// 	long double	xmid;
// 	long double	yrange;
// 	long double	ymovepp;
// 	long double	ymid;

// 	xmid = WIDTH / 2;
// 	xrange = (params->xmax + params->xmove) - (params->xmin + params->xmove);
// 	xmovepp = xrange / WIDTH;
// 	ymid = HEIGHT / 2;
// 	yrange = (params->ymax + params->xmove) - (params->ymin + params->xmove);
// 	ymovepp = yrange / HEIGHT;

// 	params->xmove = params->xmove + (xmovepp * (x - xmid));
// 	params->ymove = params->ymove + (ymovepp * (y - ymid));

// 	params->xmin = params->xmin + params->xmove;
// 	params->xmax = params->xmax + params->xmove;

// 	params->ymin = params->ymin + params->ymove;
// 	params->ymax = params->ymax + params->ymove;
// }
