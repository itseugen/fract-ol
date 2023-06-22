/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:10:55 by eweiberl          #+#    #+#             */
/*   Updated: 2023/06/22 15:52:25 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int		getiteration(double real, double imag, int maxiter, double maxval);
static uint32_t	getcolor(int iterations, int maxIterations);

/// Later add a typedef with xmin x max and so on or a define
void	mandelbrot3(t_window window, t_params params)
{
    params.xmin = params.xmin / params.zoom;
    params.xmax = params.xmax / params.zoom;
    params.ymin = params.ymin / params.zoom;
    params.ymax = params.ymax / params.zoom;
    double range_width = params.xmax - params.xmin;
    double range_height = params.ymax - params.ymin;
    double step_x = range_width / WIDTH;
    double step_y = range_height / HEIGHT;
    int x, y;
    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            double real = ((x * step_x) - (WIDTH / 2));
            double imag = ((y * step_y) - (HEIGHT / 2));
            int pxlval = getiteration(real, imag, 100, 2.0);
            mlx_put_pixel(window.img, x, y, getcolor(pxlval, 100));
        }
    }
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

static uint32_t getcolor(int iterations, int maxIterations)
{
    if (iterations == maxIterations)
        return 0x000000;  // Black

    double t = (double)iterations / maxIterations;
    uint8_t blue = (uint8_t)(9 * (1 - t) * t * t * t * 255);
    uint8_t green = (uint8_t)(15 * (1 - t) * (1 - t) * t * t * 255);
    uint8_t red = (uint8_t)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);

    return (blue << 16) | (green << 8) | red;
}

