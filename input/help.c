/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 08:58:23 by eweiberl          #+#    #+#             */
/*   Updated: 2023/07/11 16:51:37 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

//!remove If mem leaks

/// @brief Gives description on all possible modifiers
void	manual(void)
{
	char	*str;
	int		fd;

	fd = open("./input/help.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		exit(1);
	}
	str = get_next_line(fd);
	while (str != NULL)
	{
		ft_printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	exit(0);
}
