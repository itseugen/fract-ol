/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intergrad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:23:16 by eweiberl          #+#    #+#             */
/*   Updated: 2023/07/06 15:54:08 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static uint32_t	getpartial(int iterations,
					int maxIterations, uint32_t endcolour);

/// @brief Gives back a four colour set that fades
/// @param iterations 
/// @param max_iterations 
/// @return returns the colour
uint32_t	intergrad(int iterations, int max_iterations)
{
	if (iterations == max_iterations)
		return (0x000000FF);
	else if (iterations <= max_iterations / 4)
		return ((getpartial(iterations, max_iterations / 4, 0xFF0000)));
	else if (iterations <= max_iterations / 2)
		return (getpartial(iterations, max_iterations / 2, 0xFFF700));
	else if (iterations <= max_iterations * (3 / 4))
		return (getpartial(iterations, max_iterations * (3.0 / 4.0), 0x07FF00));
	else
		return (getpartial(iterations, max_iterations, 0x0012FF));
}

static uint32_t	getpartial(int iterations, int maxIterations, uint32_t endcolour)
{
	double		itergrad;
	uint8_t		blue;
	uint8_t		green;
	uint8_t		red;
	uint32_t	start_colour;

	itergrad = (double)iterations / maxIterations;
	start_colour = 0x000000;
	// if (iterations == maxIterations)
	// 	return (0x000000FF);
	blue = (uint8_t)((1 - itergrad) * ((start_colour >> 16) & 0xFF)
			+ itergrad * ((endcolour >> 16) & 0xFF));
	green = (uint8_t)((1 - itergrad) * ((start_colour >> 8) & 0xFF)
			+ itergrad * ((endcolour >> 8) & 0xFF));
	red = (uint8_t)((1 - itergrad) * (start_colour & 0xFF)
			+ itergrad * (endcolour & 0xFF));
	return ((blue << 24) | (green << 16) | (red << 8) | 0xFF);
}
// static uint32_t	getpartial(int iterations, int maxIterations, uint32_t color2)
// {
// 	double		itergrad;
// 	uint8_t		blue;
// 	uint8_t		green;
// 	uint8_t		red;
// 	uint32_t	color1;

// 	if (iterations == maxIterations)
// 		return (0x000000FF);
// 	else
// 	{
// 		itergrad = (double)iterations / maxIterations;
// 		color1 = 0x000000;
// 		blue = (uint8_t)((1 - itergrad) * ((color1 >> 16) & 0xFF) + itergrad * ((color2 >> 16) & 0xFF));
// 		green = (uint8_t)((1 - itergrad) * ((color1 >> 8) & 0xFF) + itergrad * ((color2 >> 8) & 0xFF));
// 		red = (uint8_t)((1 - itergrad) * (color1 & 0xFF) + itergrad * (color2 & 0xFF));
// 		return ((blue << 24) | (green << 16) | (red << 8) | 0xFF);
// 	}
// }
