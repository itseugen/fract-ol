/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 09:21:20 by eweiberl          #+#    #+#             */
/*   Updated: 2023/07/05 13:50:20 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
/* ************************************************************************** */
/*                               Standart Libraries                           */
/* ************************************************************************** */

# include <math.h>
# include <stdint.h>
# include <fcntl.h>
# include <stdio.h>

/* ************************************************************************** */
/*                               Own Libraries                                */
/* ************************************************************************** */

# include "mlx/include/MLX42/MLX42.h"
# include "libft/libft.h"

/* ************************************************************************** */
/*                                 Defines                                    */
/* ************************************************************************** */

# ifndef WIDTH
#  define WIDTH 1280
# endif
# ifndef HEIGHT
#  define HEIGHT 720
# endif

///add defines for colors
# define STANDART 0
# define RAINBOW 1

/* ************************************************************************** */
/*                                 typedefs                                   */
/* ************************************************************************** */

typedef struct s_window
{
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_window;

typedef struct s_params
{
	int		current_x;
	int		current_y;
	int		maxiter;
	int		colour;
	double	zoom;
	double	old_zoom;
	double	zoomdif;
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	double	creal;
	double	cimg;
}	t_params;

typedef struct s_fractol
{
	t_window		window;
	t_params		params;
}	t_fractol;

/* ************************************************************************** */
/*                                 key Handeling                              */
/* ************************************************************************** */

void		hooks(t_fractol *fractol);
void		manual(void);
void		arrow_keys(int keycode, void *param);

/* ************************************************************************** */
/*                                 fractal sets                               */
/* ************************************************************************** */

void		mandelbrot(t_window window, t_params zoom);
void		julia(t_window window, t_params params);

void		mandelbrot_test(t_window window, t_params params);
void		mandelbrot3(t_window window, t_params params);

/* ************************************************************************** */
/*                                 colouring                                  */
/* ************************************************************************** */

uint32_t	intergrad(int iterations, int max_iterations);
uint32_t	rainbow(int iterations, int max_iterations);
uint32_t	getcolor(int iterations, int max_iterations, t_params params);

/* ************************************************************************** */
/*                                 utilities                                  */
/* ************************************************************************** */

char		*ft_strtolower(char *str);
double		ft_atof(const char *str);

#endif