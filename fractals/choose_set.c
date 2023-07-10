/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:43:39 by eweiberl          #+#    #+#             */
/*   Updated: 2023/07/10 15:48:47 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

/// @brief Chooses which set to plot
/// @param window 
/// @param params 
void	choose_set(t_window window, t_params params)
{
	if (params.set == JULIA)
		julia(window, params);
	else if (params.set == BURNING_SHIP)
		burning_ship(window, params);
	else
		mandelbrot(window, params);
}
