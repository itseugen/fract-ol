/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdvals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:27:31 by eweiberl          #+#    #+#             */
/*   Updated: 2023/07/11 15:31:06 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	standart_vals(t_fractol *fractol, int argc, char *argv[])
{
	if (fractol->params.colour == NO_INIT)
		fractol->params.colour = STANDART;
	if (fractol->params.creal == NO_INIT && fractol->params.set == JULIA)
		fractol->params.creal = 0.6;
	if (fractol->params.cimg == NO_INIT && fractol->params.set == JULIA)
		fractol->params.cimg = -0.6;
	if (fractol->params.set == NO_INIT)
		fractol->params.set = MANDELBROT;
	if (fractol->params.maxiter == NO_INIT)
		fractol->params.maxiter = 30;
}
