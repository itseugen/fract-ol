/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:34:05 by eweiberl          #+#    #+#             */
/*   Updated: 2023/06/16 10:47:35 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	close_window(void);
static int	close_keys(int keycode);

/// @brief handles input
/// @param window gets the window variables to handle inputs
void	hooks(t_window window)
{
	mlx_hook(window.win, 17, 0, close_window, NULL);
	mlx_key_hook(window.win, close_keys, NULL);
}

/// @brief Closes the window on 'ESC'
/// @param keycode the key pressed
static int	close_keys(int keycode)
{
	/*ESC*/
	if (keycode == 53)
		close_window();
	return (0);
}

/// @brief Frees everything necessary before closing the window
/// @param void might be replaced in the future
static int	close_window(void)
{
	/*Add frees if needed*/
	exit(0);
}
