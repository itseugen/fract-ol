/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:10:55 by eweiberl          #+#    #+#             */
/*   Updated: 2023/07/08 11:26:50 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int		getiteration(double real, double imag, int maxiter, double maxval);

/// Later add a typedef with xmin x max and so on or a define

/// @brief THe mandelbrot set
/// @param window 
/// @param params 
void	mandelbrot(t_window window, t_params params)
{
	int		x = 0;
	int		y = 0;
	int		pxlval;

	// params.xmin = params.xmin / params.zoom;
	// params.xmax = params.xmax / params.zoom;
	// params.ymin = params.ymin / params.zoom;
	// params.ymax = params.ymax / params.zoom;
	if (params.zoom < 1)
		params.zoom = 1;
	while (y < HEIGHT)
	{
		pxlval = getiteration(params.xmin + (x * (params.xmax - params.xmin) / WIDTH),
				params.ymin + (y * (params.ymax - params.ymin) / HEIGHT), params.maxiter * (params.zoom * params.zoom), 2.0);
		mlx_put_pixel(window.img, x, y, getcolor(pxlval, params.maxiter * (params.zoom * params.zoom), params));
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

/*
It all boils down to the following:

0. Select the point in the bottom left corner of the region (-2,-2)

1. Start with zx=0 and zy=0

2. Calculate:

        xt=zx*zy
        zx=zx*zx-zy*zy+cx
        zy=2*xt+cy

        These calculations are really the formula zn=z2n+1. 
		The reason they look different is because i2=-1, 
		a property of complex numbers.

3. Repeat step 2 if:

a. you haven't reached 255 iterations yet [i<255]
AND
b. the absolute value of the result is lower than 4 [zx*zx+zy*zy)<4]

4. change the color of the point you're calculating (ie. cx,cy) to the color 
corresponding to the number of iterations (the number of times you repeated 
steps 2 and 3)

        We set Red, Green and Blue values of the color
		 of the square to the number of
		iterations, which generates a greyscale picture.

5. Select the next point (go by columns and rows)

6. Go to step 1, until you reach the bottom right corner

Here's the actual code:
*/