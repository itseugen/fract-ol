/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:17:51 by eweiberl          #+#    #+#             */
/*   Updated: 2023/07/07 14:30:19 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	key_handle(void *param)
{
	t_params	*params;
	t_window	*window;

	window = &((t_fractol *)param)->window;
	params = &((t_fractol *)param)->params;
	arrow_keys(params, window);
	if (mlx_is_key_down(window->mlx, MLX_KEY_Z))
	{
		if (params->zo_mouse == FALSE)
		{
			params->zo_mouse = TRUE;
			ft_printf("Zoom on cursor enabled!\n");
		}
	}
	if (mlx_is_key_down(window->mlx, MLX_KEY_X))
	{
		if (params->zo_mouse == TRUE)
		{
			params->zo_mouse = FALSE;
			ft_printf("Zoom on cursor disabled!\n");
		}
	}
}
