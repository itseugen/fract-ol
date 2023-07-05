/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:34:05 by eweiberl          #+#    #+#             */
/*   Updated: 2023/07/05 16:50:33 by eweiberl         ###   ########.fr       */
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
	mlx_key_hook(fractol->window.mlx, (void *)keys, fractol);
	//mlx_key_hook(fractol->window.mlx, (void *)arrow_keys, fractol);
	mlx_loop_hook(fractol->window.mlx, arrow_keys, fractol);
	mlx_scroll_hook(fractol->window.mlx, zoomdetec, fractol);
}

/// @brief Closes the window on 'ESC'
/// @param keycode the key pressed
static int	keys(int keycode, void *param)
{
	if (keycode == MLX_KEY_ESCAPE)
		close_window(param);
	// else if (keycode == MLX_KEY_RIGHT)
	// 	arrow_keys(keycode, param);
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
	// if (x >= 0 && y >= 0 && x <= WIDTH && y <= HEIGHT)
	// 	zoom_on_cursor(params, window, x, y);
	// else
	// {
	printf("Current Zoom value: %f\n", params->zoom);
	printf("Mouse Position: (%d, %d)\n", x, y);
	params->xmin = params->xmin / params->zoomdif;
	params->xmax = params->xmax / params->zoomdif;
	params->ymin = params->ymin / params->zoomdif;
	params->ymax = params->ymax / params->zoomdif;
	// }
	mandelbrot(*window, *params);
	//julia(*window, *params);
}
/*
void mlx_get_mouse_pos(mlx_t* mlx, int32_t* x, int32_t* y);
*/

// static void	zoom_on_cursor(t_params *params, t_window *window, int x, int y)
// {
// 	double	rangex;
// 	double	rangey;
// 	double	midx;
// 	double	midy;
// 	double	cur_width;
// 	double	cur_height;

// 	rangex = (params->xmax - params->xmin) / params->zoomdif;
// 	rangey = (params->ymax - params->ymin) / params->zoomdif;
// 	cur_width = WIDTH / params->zoom;
// 	cur_height = HEIGHT / params->zoom;
// 	if (x < (cur_width / 2))
// 		midx = (cur_width / 2);
// 	else if (x > (WIDTH - (cur_width / 2)))
// 		midx = WIDTH - (cur_width / 2);
// 	else
// 		midx = x;
// 	if (y < (cur_height / 2))
// 		midy = (cur_height / 2);
// 	else if (y > (HEIGHT - (cur_height / 2)))
// 		midy = HEIGHT - (cur_height / 2);
// 	else
// 		midy = y;

// 	double middleDiffX = midx - (2.0 + (-2.0)) / 2.0;
// 	double middleDiffY = midy - (2.0 + (-2.0)) / 2.0;

// 	params->xmin = midx - rangex / 2.0 - middleDiffX;
// 	params->xmax = midx + rangex / 2.0 - middleDiffX;
// 	params->ymin = midy - rangey / 2.0 - middleDiffY;
// 	params->ymax = midy + rangey / 2.0 - middleDiffY;
// }
