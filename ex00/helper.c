/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iavautra <iavautra@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 06:39:42 by iavautra          #+#    #+#             */
/*   Updated: 2024/06/29 18:24:23 by iavautra         ###   ########.fr       */
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
	int	x;
	int	y;

	x = 0;
	while (x < ROW_SIZE)
	{
		y = 0;
		while (y < COL_SIZE)
		{
			printf("%d ", grid[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}
}

int	print_error(void)
{
	write(1, ERROR_MSG, ft_strlen(ERROR_MSG));
	return (1);
}

bool	is_safe(int **grid, int row, int col, int value)
{
	int	x;
	int	y;
	int	i;

	x = row;
	y = col;
	while (x >= 0)
	{
		if (grid[x][y] == value)
			return (false);
		x--;
	}
	x = row;
	y = col;
	while (x < ROW_SIZE)
	{
		if (grid[x][y] == value)
			return (false);
		x++;
	}
	x = row;
	y = col;
	while (y < ROW_SIZE)
	{
		if (grid[x][y] == value)
			return (false);
		y++;
	}
	x = row;
	y = col;
	while (y >= 0)
	{
		if (grid[x][y] == value)
			return (false);
		y--;
	}
	return (true);
}
