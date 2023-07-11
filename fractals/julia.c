/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:09:02 by eweiberl          #+#    #+#             */
/*   Updated: 2023/07/11 16:36:23 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	getiteration(double x, double y, int maxiter, t_params params);

void	julia(t_window window, t_params params)
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
				+ (x * ((params.xmax - params.xmin) / WIDTH)),
				params.ymin + (y * ((params.ymax - params.ymin) / HEIGHT)),
				params.maxiter * (params.zoom * params.zoom), params);
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

static int	getiteration(double x, double y, int maxiter, t_params params)
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
		temp = zreal * zreal - zimg * zimg + params.creal;
		zimg = 2 * zreal * zimg + params.cimg;
		zreal = temp;
		if (sqrt(zreal * zreal + zimg * zimg) > 4)
			break ;
		iter++;
	}
	return (iter);
}
