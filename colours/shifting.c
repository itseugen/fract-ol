/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shifting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:46:50 by eweiberl          #+#    #+#             */
/*   Updated: 2023/07/11 13:17:19 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static uint32_t	getpartial(int iterations,
					int maxIterations, uint32_t endcolour);
static uint32_t	lerp(double zoom, double endzoom,
					uint32_t start_colour, uint32_t endcolour);

/// @brief Gives back a four colour set that fades
/// @param iterations 
/// @param max_iterations 
/// @return returns the colour
uint32_t	shifting_range(int iterations, int max_iterations, t_params params)
{
	while (params.zoom > 7.0)
		params.zoom = params.zoom - 6.0;
	if (iterations == max_iterations)
		return (0x000000FF);
	else if (params.zoom <= 2.0)
		return (getpartial(iterations, max_iterations,
				lerp(params.zoom, 2.0, 0xE40303, 0xFF8C00)));
	else if (params.zoom <= 3.0)
		return (getpartial(iterations, max_iterations,
				lerp(params.zoom, 3.0, 0xFF8C00, 0xFFED00)));
	else if (params.zoom <= 4.0)
		return (getpartial(iterations, max_iterations,
				lerp(params.zoom, 4.0, 0xFFED00, 0x008026)));
	else if (params.zoom <= 5.0)
		return (getpartial(iterations, max_iterations,
				lerp(params.zoom, 5.0, 0x008026, 0x24408E)));
	else if (params.zoom <= 6.0)
		return (getpartial(iterations, max_iterations,
				lerp(params.zoom, 6.0, 0x24408E, 0x732982)));
	else
		return (getpartial(iterations, max_iterations,
				lerp(params.zoom, 7.0, 0x732982, 0xE40303)));
}

static uint32_t	getpartial(int iterations, int maxIterations,
						uint32_t endcolour)
{
	double		itergrad;
	uint8_t		blue;
	uint8_t		green;
	uint8_t		red;
	uint32_t	start_colour;

	itergrad = (double)iterations / maxIterations;
	start_colour = 0x000000;
	blue = (uint8_t)((1 - itergrad) * ((start_colour >> 16) & 0xFF)
			+ itergrad * ((endcolour >> 16) & 0xFF));
	green = (uint8_t)((1 - itergrad) * ((start_colour >> 8) & 0xFF)
			+ itergrad * ((endcolour >> 8) & 0xFF));
	red = (uint8_t)((1 - itergrad) * (start_colour & 0xFF)
			+ itergrad * (endcolour & 0xFF));
	return ((blue << 24) | (green << 16) | (red << 8) | 0xFF);
}

static uint32_t	lerp(double zoom, double endzoom,
					uint32_t start_colour, uint32_t endcolour)
{
	double		itergrad;
	uint8_t		blue;
	uint8_t		green;
	uint8_t		red;

	itergrad = (zoom - (endzoom - 1.0)) / (endzoom - (endzoom - 1.0));
	blue = (uint8_t)((itergrad) * ((endcolour >> 16) & 0xFF)
			+ (1 - itergrad) * ((start_colour >> 16) & 0xFF));
	green = (uint8_t)((itergrad) * ((endcolour >> 8) & 0xFF)
			+ (1 - itergrad) * ((start_colour >> 8) & 0xFF));
	red = (uint8_t)((itergrad) * (endcolour & 0xFF)
			+ (1 - itergrad) * (start_colour & 0xFF));
	return ((blue << 16) | (green << 8) | red);
}
