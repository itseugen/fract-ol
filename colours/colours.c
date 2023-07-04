/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:24:24 by eweiberl          #+#    #+#             */
/*   Updated: 2023/07/04 10:48:07 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

/*
* Handle different colour choices in the future
* for example (if intergrad == true) return (intergrad)
*/

uint32_t	getcolor(int iterations, int max_iterations, t_params params)
{
	if (params.colour == RAINBOW)
		return (rainbow(iterations, max_iterations));
	else
		return (intergrad(iterations, max_iterations));
}
