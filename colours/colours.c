/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:24:24 by eweiberl          #+#    #+#             */
/*   Updated: 2023/07/11 14:34:41 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

/*
* Handle different colour choices in the future
* for example (if intergrad == true) return (intergrad)
*/

/// @brief chooses what colours to apply based on user input
/// @param iterations amount of iterations
/// @param max_iterations the max iterations
/// @param params 
/// @return 
uint32_t	getcolor(int iterations, int max_iterations, t_params params)
{
	if (params.colour == RAINBOW)
		return (rainbow(iterations, max_iterations));
	else if (params.colour == SHIFT)
		return (shifting_range(iterations, max_iterations, params));
	else if (params.colour == TUVALU)
		return (tuvalu(iterations, max_iterations));
	else if (params.colour == INDIA)
		return (india(iterations, max_iterations));
	else
		return (intergrad(iterations, max_iterations));
}
