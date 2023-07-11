/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initvals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:47:47 by eweiberl          #+#    #+#             */
/*   Updated: 2023/07/11 16:09:59 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	user_colours(t_fractol *fractol, char *str);
static void	fractal_set(t_fractol *fractol, char *str);
static void	numbers(t_fractol *fractol, char *str);

/// @brief Initialize all values to standart
/// @param fractol 
/// @param argc 
/// @param argv 
void	init_vals(t_fractol *fractol, int argc, char *argv[])
{
	if (argc == 2 && ft_strncmp(ft_strtolower(argv[1]),
			"help", ft_strlen(argv[1])) == 0)
		manual();
	fractol->params.colour = NO_INIT;
	fractol->params.creal = NO_INIT;
	fractol->params.cimg = NO_INIT;
	fractol->params.set = NO_INIT;
	fractol->params.maxiter = NO_INIT;
	fractol->params.zo_mouse = TRUE;
	fractol->params.xmin = -2;
	fractol->params.xmax = 2;
	fractol->params.ymin = -2;
	fractol->params.ymax = 2;
	fractol->params.zoom = 1;
	fractol->params.xmove = 0;
	fractol->params.ymove = 0;
	fractol->params.zoomin = 0;
	fractol->params.zoomout = 0;
	user_vals(fractol, argc, argv);
	standart_vals(fractol);
}

/// @brief Change the values to user preference
/// @param fractol 
/// @param argc 
/// @param argv 
void	user_vals(t_fractol *fractol, int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(ft_strtolower(argv[i]), "iter:", 5) == 0)
			numbers(fractol, argv[i]);
		else if ((ft_strncmp(ft_strtolower(argv[i]), "rainbow", 7) == 0)
			|| (ft_strncmp(ft_strtolower(argv[i]), "shift", 5) == 0)
			|| (ft_strncmp(ft_strtolower(argv[i]), "tuvalu", 6) == 0)
			|| (ft_strncmp(ft_strtolower(argv[i]), "india", 5) == 0))
			user_colours(fractol, argv[i]);
		else if ((ft_strncmp(ft_strtolower(argv[i]), "julia", 5) == 0)
			|| (ft_strncmp(ft_strtolower(argv[i]), "mandelbrot", 10) == 0)
			|| (ft_strncmp(ft_strtolower(argv[i]), "burning_ship", 12) == 0))
			fractal_set(fractol, argv[i]);
		else if (ft_strncmp(ft_strtolower(argv[i]), "creal:", 6) == 0)
			fractol->params.creal = ft_atof(argv[i] + 6);
		else if (ft_strncmp(ft_strtolower(argv[i]), "cimg:", 5) == 0)
			fractol->params.cimg = ft_atof(argv[i] + 5);
		else
			manual();
		i++;
	}
}

static void	user_colours(t_fractol *fractol, char *str)
{
	if (fractol->params.colour != NO_INIT)
		manual();
	if (ft_strncmp(ft_strtolower(str), "rainbow", 7) == 0)
		fractol->params.colour = RAINBOW;
	else if (ft_strncmp(ft_strtolower(str), "shift", 5) == 0)
		fractol->params.colour = SHIFT;
	else if (ft_strncmp(ft_strtolower(str), "tuvalu", 6) == 0)
		fractol->params.colour = TUVALU;
	else if (ft_strncmp(ft_strtolower(str), "india", 5) == 0)
		fractol->params.colour = INDIA;
}

static void	fractal_set(t_fractol *fractol, char *str)
{
	if (fractol->params.set != NO_INIT)
		manual();
	if (ft_strncmp(ft_strtolower(str), "julia", 5) == 0)
		fractol->params.set = JULIA;
	else if (ft_strncmp(ft_strtolower(str), "mandelbrot", 10) == 0)
		fractol->params.set = MANDELBROT;
	else if (ft_strncmp(ft_strtolower(str), "burning_ship", 12) == 0)
		fractol->params.set = BURNING_SHIP;
}

static void	numbers(t_fractol *fractol, char *str)
{
	if (ft_strncmp(ft_strtolower(str), "iter:", 5) == 0)
	{
		if (fractol->params.maxiter != NO_INIT)
			manual();
		fractol->params.maxiter = ft_atoi(str + 5);
		if (fractol->params.maxiter <= 0)
			manual();
	}
}
