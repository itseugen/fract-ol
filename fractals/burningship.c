/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:06:54 by eweiberl          #+#    #+#             */
/*   Updated: 2023/07/11 16:12:26 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int		getiteration(double real, double imag,
					int maxiter, double maxval);

/// Later add a typedef with xmin x max and so on or a define

/// @brief THe mandelbrot set
/// @param window 
/// @param params 
void	burning_ship(t_window window, t_params params)
{
	int		x;
	int		y;
	int		pxlval;

	x = 0;
	y = 0;
	if (params.zoom < 1)
		params.zoom = 1;
	while (y < HEIGHT)
	{
		pxlval = getiteration(params.xmin
				+ (x * (params.xmax - params.xmin) / WIDTH),
				params.ymin + (y * (params.ymax - params.ymin) / HEIGHT),
				params.maxiter * (params.zoom * params.zoom), 2.0);
		mlx_put_pixel(window.img, x, y, getcolor(pxlval,
				params.maxiter * (params.zoom * params.zoom), params));
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
		temp_zreal = zreal * zreal - zimg * zimg;
		temp_zimg = maxval * zreal * zimg;
		if (temp_zimg < 0)
			temp_zimg = temp_zimg * -1;
		zreal = temp_zreal + real;
		zimg = temp_zimg + imag;
		if (sqrt(zreal * zreal + zimg * zimg) > maxval)
			break ;
		iter++;
	}
	return (iter);
}
