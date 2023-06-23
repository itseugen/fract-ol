/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:09:02 by eweiberl          #+#    #+#             */
/*   Updated: 2023/06/23 14:44:56 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int		getiteration(int x, int y, int maxiter, double creal, double cimg);


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
		mlx_put_pixel(window.img, x, y, getcolor(pxlval, 100, params));
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

