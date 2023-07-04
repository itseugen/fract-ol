/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:09:02 by eweiberl          #+#    #+#             */
/*   Updated: 2023/07/04 14:07:22 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int		getiteration(double x, double y, int maxiter, double creal, double cimg);


///!FIX ZOOM
void	julia(t_window window, t_params params)
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
		pxlval = getiteration(params.xmin + (x * ((params.xmax - params.xmin) / WIDTH)),
				params.ymin + (y * ((params.ymax - params.ymin) / HEIGHT)), params.maxiter * (params.zoom * params.zoom), params.creal, params.cimg);
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

static int	getiteration(double x, double y, int maxiter, double creal, double cimg)
{
	double	zreal;
	double	zimg;
	double	temp;
	int		iter;

	iter = 0;
	zreal = x;
	zimg = y;
	while (iter < maxiter)
	{
		temp = zreal * zreal - zimg * zimg + creal;
		zimg = 2 * zreal * zimg + cimg;
		zreal = temp;
		if (sqrt(zreal * zreal + zimg * zimg) > 4)
			break ;
		iter++;
	}
	return (iter);
}
