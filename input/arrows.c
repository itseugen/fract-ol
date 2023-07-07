/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:13:21 by eweiberl          #+#    #+#             */
/*   Updated: 2023/07/07 14:21:21 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	wasd(t_params *params, t_window *window, double movement);

/// @brief Makes the arrow/wasd keys move the set
/// @param param the fractols typedef
void	arrow_keys(t_params *params, t_window *window)
{
	double		movement;

	if (mlx_is_key_down(window->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(window->mlx, MLX_KEY_D))
	{
		movement = 0.1 / (2 * params->zoom);
		params->xmin += movement;
		params->xmax += movement;
		choose_set(*window, *params);
	}
	if (mlx_is_key_down(window->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(window->mlx, MLX_KEY_A))
	{
		movement = 0.1 / (2 * params->zoom);
		params->xmin -= movement;
		params->xmax -= movement;
		choose_set(*window, *params);
	}
	wasd(params, window, movement);
}

/// @brief A norm proof extenstion to arrows
/// @param params 
/// @param window 
/// @param movement 
static void	wasd(t_params *params, t_window *window, double movement)
{
	if (mlx_is_key_down(window->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(window->mlx, MLX_KEY_W))
	{
		movement = 0.1 / (2 * params->zoom);
		params->ymin -= movement;
		params->ymax -= movement;
		choose_set(*window, *params);
	}
	if (mlx_is_key_down(window->mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(window->mlx, MLX_KEY_S))
	{
		movement = 0.1 / (2 * params->zoom);
		params->ymin += movement;
		params->ymax += movement;
		choose_set(*window, *params);
	}
}
