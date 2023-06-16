/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:34:05 by eweiberl          #+#    #+#             */
/*   Updated: 2023/06/16 16:14:40 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	close_window(void *param);
static int	close_keys(int keycode, void *param);

/// @brief handles input
/// @param window gets the window variables to handle inputs
void	hooks(t_window window)
{
	mlx_close_hook(window.mlx, (void *)close_window, NULL);
	mlx_key_hook(window.mlx, (void *)close_keys, NULL);
}

/// @brief Closes the window on 'ESC'
/// @param keycode the key pressed
static int	close_keys(int keycode, void *param)
{
	/*ESC*/
	if (keycode == 256)
		close_window(param);
	// if (keycode == 53)
	// 	g_zoom += 0.1;
	// if (keycode == 53)
	// 	g_zoom -= 0.1;
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
