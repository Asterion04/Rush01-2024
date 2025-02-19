/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iavautra <iavautra@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 06:39:42 by iavautra          #+#    #+#             */
/*   Updated: 2024/06/30 14:45:51 by iavautra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

size_t	ft_strlen(const char *str)
{
	size_t	length;

	if (str == NULL)
		return (0);
	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

void	print_grid(int **grid)
{
	int		x;
	int		y;
	char	c;

	x = 0;
	while (x < ROW_SIZE)
	{
		y = 0;
		while (y < COL_SIZE)
		{
			c = grid[x][y] + '0';
			write(1, &c, 1);
			if (y < COL_SIZE - 1)
				write(1, " ", 1);
			y++;
		}
		write(1, "\n", 1);
		x++;
	}
}

int	print_error(void)
{
	write(1, ERROR_MSG, ft_strlen(ERROR_MSG));
	return (1);
}
