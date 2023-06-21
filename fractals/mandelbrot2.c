/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:24:49 by eweiberl          #+#    #+#             */
/*   Updated: 2023/06/21 16:17:30 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	getiteration(double Z_re, double Z_im, int maxiter, double c_im, double c_re);
static uint32_t	getcolor(int iterations, int maxIterations);

/// Later add a typedef with xmin x max and so on or a define
void	mandelbrot_test(t_window window, t_params params)
{
double MinRe = -2.0;
double MaxRe = 1.0;
double MinIm = -1.2;
double MaxIm = MinIm + (MaxRe - MinRe) * HEIGHT/ WIDTH;
double Re_factor = (MaxRe - MinRe) / (WIDTH - 1);
double Im_factor = (MaxIm - MinIm) / (HEIGHT - 1);
unsigned int y = 0;
int			pxlval;
unsigned int x = 0;

	while (y < HEIGHT)
	{
		double c_im = MaxIm - y * Im_factor;
		double c_re = MinRe + x * Re_factor;
		double z_re = c_re;
		double Z_im = c_im;
		pxlval = getiteration(z_re, Z_im, 100, c_im, c_re);
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

static int	getiteration(double Z_re, double Z_im, int maxiter, double c_im, double c_re)
{
	unsigned int n = 0;
	while (++n < maxiter)
	{
		double Z_re2 = Z_re * Z_re;
		double Z_im2 = Z_im * Z_im;
		if (Z_re2 + Z_im2 > 4)
			return (n);
		Z_im = 2*Z_re*Z_im + c_im;
		Z_re = Z_re2 - Z_im2 + c_re;
	}
	return (maxiter);
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
