/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 09:35:59 by eweiberl          #+#    #+#             */
/*   Updated: 2023/06/22 15:45:14 by eweiberl         ###   ########.fr       */
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
	/*Change to handle user inputs later*/
	fractol.params.xmin = -2.5;
	fractol.params.xmax = 1;
	fractol.params.ymin = -1;
	fractol.params.ymax = 1;
	fractol.params.zoom = 1;
	fractol.window.mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (fractol.window.mlx == NULL)
		exit (1);
	fractol.window.img = mlx_new_image(fractol.window.mlx, WIDTH, HEIGHT);
	mlx_image_to_window(fractol.window.mlx, fractol.window.img, 0, 0);
	hooks(&fractol);
	/*temp*/
	mandelbrot3(fractol.window, fractol.params);
	//julia(fractol.window, fractol.params);
	mlx_loop(fractol.window.mlx);
	return (0);
}
/*
 * Lets you set a custom image as the program icon.
 * 
 * NOTE: In MacOS this function does nothing, you should use the bundles icon to set the dock bar icon.
 * @see: https://9to5mac.com/2021/11/08/change-mac-icons/
 * @see: https://github.com/glfw/glfw/issues/2041
 *
 * @param[in] mlx The MLX instance handle.
 * @param[in] image The image to use as icon.
void mlx_set_icon(mlx_t* mlx, mlx_texture_t* image);

*/
/* FOr RANDOM
 * Gets the elapsed time since MLX was initialized.
 * 
 * @return The amount of time elapsed in seconds.

double mlx_get_time(void);
*/

/** SET TO FULLSCREEN
 * Gets the size of the specified monitor.
 * 
 * @param[in] index Normally 0, in case of multiple windows, can be specified
 * @param[in] width The width of the window.
 * @param[in] height The height of the window.
 
void mlx_get_monitor_size(int32_t index, int32_t* width, int32_t* height);

*/
/**
 * Sets the title of the window.
 * 
 * @param[in] mlx The MLX instance handle.
 * @param[in] title The window title.
void mlx_set_window_title(mlx_t* mlx, const char* title);
 */
/**
 * Returns the current, relative, mouse cursor position on the window, starting
 * from the top left corner.
 * 
 * Negative values or values greater than window width or height 
 * indicate that it is outside the window.
 * 
 * @param[in] mlx The MLX instance handle. 
 * @param[out] x The position.
 * @param[out] y The position.
void mlx_get_mouse_pos(mlx_t* mlx, int32_t* x, int32_t* y);
 */

/**
 * Allows for the creation of custom cursors with a given texture.
 * 
 * Use mlx_set_cursor to select the specific cursor.
 * Cursors are destroyed at mlx_terminate().
 * 
 * @param[in] texture The texture to use as cursor.
 * @returns The cursor object or null on failure.
mlx_win_cursor_t* mlx_create_cursor(mlx_texture_t* texture);
 */
/**
 * Sets the current cursor to the given custom cursor. 
 * 
 * @param[in] mlx The MLX instance handle.
 * @param[in] cursor The cursor object to display, if null default cursor is selected.
void mlx_set_cursor(mlx_t* mlx, mlx_win_cursor_t* cursor);
 */
