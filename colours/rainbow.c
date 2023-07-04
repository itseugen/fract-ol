/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:42:02 by eweiberl          #+#    #+#             */
/*   Updated: 2023/07/04 11:06:43 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

uint32_t	rainbow(int iterations, int max_iterations)
{
	if (iterations == max_iterations)
		return (0xE40303FF);
	else if (iterations <= (double)max_iterations * 0.02)
		return (0x732982FF);
	else if (iterations <= (double)max_iterations * 0.05)
		return (0x24408EFF);
	else if (iterations <= (double)max_iterations * 0.15)
		return (0x008026FF);
	else if (iterations <= (double)max_iterations * 0.4)
		return (0xFFED00FF);
	else if (iterations <= (double)max_iterations * 0.8)
		return (0xFF8C00FF);
	else
		return (0xE40303FF);
}

