/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 09:35:59 by eweiberl          #+#    #+#             */
/*   Updated: 2023/07/07 14:26:23 by eweiberl         ###   ########.fr       */
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

static int	select_set(t_fractol fractol, int argc, char *argv[]);
static void	init_vals(t_fractol *fractol, int argc, char *argv[]);
static void	user_vals(t_fractol *fractol, int argc, char *argv[]);

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
	select_set(fractol, argc, argv);
	mlx_loop(fractol.window.mlx);
	return (0);
}

/// @brief Initialize all values to standart
/// @param fractol 
/// @param argc 
/// @param argv 
static void	init_vals(t_fractol *fractol, int argc, char *argv[])
{
	if (argc == 2 && ft_strncmp(ft_strtolower(argv[1]),
			"help", ft_strlen(argv[1])) == 0)
		manual();
	fractol->params.maxiter = 30;
	fractol->params.xmin = -2;
	fractol->params.xmax = 2;
	fractol->params.ymin = -2;
	fractol->params.ymax = 2;
	fractol->params.zoom = 1;
	fractol->params.colour = STANDART;
	fractol->params.creal = 0.6;
	fractol->params.cimg = -0.6;
	fractol->params.set = MANDELBROT;
	fractol->params.zo_mouse = TRUE;
	user_vals(fractol, argc, argv);
}

/// @brief Change the values to user preference
/// @param fractol 
/// @param argc 
/// @param argv 
static void	user_vals(t_fractol *fractol, int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(ft_strtolower(argv[i]), "iter:", 5) == 0)
			fractol->params.maxiter = ft_atoi(argv[i] + 5);
		else if (ft_strncmp(ft_strtolower(argv[i]), "rainbow", 7) == 0)
			fractol->params.colour = RAINBOW;
		else if (ft_strncmp(ft_strtolower(argv[i]), "creal:", 6) == 0)
			fractol->params.creal = ft_atof(argv[i] + 6);
		else if (ft_strncmp(ft_strtolower(argv[i]), "cimg:", 5) == 0)
			fractol->params.cimg = ft_atof(argv[i] + 5);
		else if (ft_strncmp(ft_strtolower(argv[i]), "julia", 5) == 0)
			fractol->params.set = JULIA;
		i++;
	}
	printf("cimg: %f\n", fractol->params.cimg);
}

/// @brief select which set to display
/// @param fractol 
/// @param argc 
/// @param argv 
/// @return returns 0 on success
static int	select_set(t_fractol fractol, int argc, char *argv[])
{
	if (fractol.params.set == JULIA)
		return (julia(fractol.window, fractol.params), 0);
	else
		return (mandelbrot(fractol.window, fractol.params), 0);
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
