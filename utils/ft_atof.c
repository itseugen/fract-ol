/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:19:39 by eweiberl          #+#    #+#             */
/*   Updated: 2023/07/04 14:02:50 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	ft_atof(const char *str)
{
	double	num;
	double	comma;
	int		i;
	int		is_n;

	i = 0;
	is_n = 1;
	num = (double)ft_atoi(str);
	while (str[i] != '\0' && str[i] != '.')
	{
		if (str[i] == '-')
			is_n = -1;
		i++;
	}
	if (str[i] == '.')
		comma = (double)ft_atoi(str + i + 1);
	while (comma >= 1)
		comma = comma / 10;
	if (is_n == -1)
		return (num - comma);
	return (num + comma);
}
