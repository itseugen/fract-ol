/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:10:55 by eweiberl          #+#    #+#             */
/*   Updated: 2023/06/19 17:30:29 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int		getiteration(double real, double imag, int maxiter, double maxval);
static uint32_t	getcolor(int iterations, int maxIterations);

/// Later add a typedef with xmin x max and so on or a define
void	mandelbrot(t_window window, t_params params)
{
	int		x = 0;
	int		y = 0;
	int		pxlval;

	params.xmin = params.xmin / params.zoom;
	params.xmax = params.xmax / params.zoom;
	params.ymin = params.ymin / params.zoom;
	params.ymax = params.ymax / params.zoom;
	while (y < HEIGHT)
	{
		pxlval = getiteration(params.xmin + (x * (params.xmax - params.xmin) / WIDTH),
				params.ymin + (y * (params.ymax - params.ymin) / HEIGHT), 100, 2.0);
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

static int	getiteration(double real, double imag, int maxiter, double maxval)
{
	double	zreal;
	double	zimg;
	double	temp_zreal;
	double	temp_zimg;
	int		iter;

	zreal = 0.0;
	zimg = 0.0;
	iter = 0;
	while (iter < maxiter)
	{
		temp_zreal = zreal * zreal - zimg * zimg + real;
		temp_zimg = maxval * zreal * zimg + imag;
		zreal = temp_zreal;
		zimg = temp_zimg;
		if (sqrt(zreal * zreal + zimg * zimg) > maxval)
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
