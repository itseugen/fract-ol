/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:09:02 by eweiberl          #+#    #+#             */
/*   Updated: 2023/06/19 14:41:14 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int		getiteration(int x, int y, int maxiter, double creal, double cimg);
static uint32_t	getcolor(int iterations, int maxIterations);

/// Later add a typedef with xmin x max and so on or a define
void	julia(t_window window, t_params params)
{
	// double	xmin = -2.5 / params.zoom;
	// double	xmax = 1 / params.zoom;
	// double	ymin = -1 / params.zoom;
	// double	ymax = 1 / params.zoom;
	int		x = 0;
	int		y = 0;
	int		pxlval;

	(void)params.zoom;
	while (y < HEIGHT)
	{
		pxlval = getiteration(x, y, 100, -0.5, 0.5);
		mlx_put_pixel(window.img, x, y, getcolor(pxlval, 100));
		x++;
		if (x == WIDTH)
		{
			x = 0;
			y++;
		}
	}
	return ;
}

static int	getiteration(int x, int y, int maxiter, double creal, double cimg)
{
	double	zreal;
	double	zimg;
	int		iter;

	iter = 0;
	zreal = x;
	zimg = y;
	while (iter < maxiter)
	{
		zreal = (zreal * zreal) + creal;
		zimg = (zimg * zimg) + cimg;
		if (sqrt(zreal * zreal + zimg * zimg) > 4)
			break ;
		iter++;
	}
	return (iter);
}

static uint32_t	getcolor(int iterations, int maxIterations)
{
	double	itergrad;
	uint8_t	blue;
	uint8_t	green;
	uint8_t	red;

	if (iterations == maxIterations)
		return (0x000000);
	else
	{
		// Map the iteration count to a color gradient
		itergrad = (double)iterations / maxIterations;
		// Define color gradients in hexadecimal values
		uint32_t color1 = 0x000000;  // Start color (black)
		uint32_t color2 = 0xFFA100;  // End color
		// Interpolate between color1 and color2 based on t
		blue = (uint8_t)((1 - itergrad) * ((color1 >> 16) & 0xFF) + itergrad * ((color2 >> 16) & 0xFF));
		green = (uint8_t)((1 - itergrad) * ((color1 >> 8) & 0xFF) + itergrad * ((color2 >> 8) & 0xFF));
		red = (uint8_t)((1 - itergrad) * (color1 & 0xFF) + itergrad * (color2 & 0xFF));
		return ((blue << 24) | (green << 16) | (red << 8) | 0xFF);
	}
}

