/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iavautra <iavautra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 07:03:45 by iavautra          #+#    #+#             */
/*   Updated: 2024/06/29 08:57:14 by iavautra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	solve_default_case(int **grid, const char	*str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < 4)
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '4')
		{
			grid[0][j] = 1;
			grid[0][j + 1] = 2;
			grid[0][j + 2] = 3;
		}
		if (str[i] == '1')
			grid[0][j] = 4;
		j++;
		i++;
	}
	j = 0;
	while (j < 4)
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '4')
		{
			grid[3][j] = 1;
			grid[3][j + 1] = 2;
			grid[3][j + 2] = 3;
		}
		if (str[i] == '1')
			grid[3][j] = 4;
		j++;
		i++;
	}
	j = 0;
	while (j < 4)
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '4')
		{
			grid[j][0] = 1;
			grid[j + 1][0] = 2;
			grid[j + 2][0] = 3;
		}
		if (str[i] == '1')
			grid[j][0] = 4;
		j++;
		i++;
	}
	j = 0;
	while (j < 4)
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '4')
		{
			grid[j][3] = 1;
			if (j + 1 >= 4)
			{
				i++;
				continue ;
			}
			grid[j + 1][3] = 2;
			grid[j + 2][3] = 3;
		}
		if (str[i] == '1')
			grid[j][3] = 4;
		j++;
		i++;
	}
}

bool	is_safe(int **grid, int row, int col, int value)
{
	int	x;

	while (x < ROW_SIZE)
	{
		if (grid[row][x] == value || grid[x][col] == value)
			return (false);
		x++;
	}
	return (true);
}

bool	try_solving(const char *str)
{
	int	**grid;
	int	x;
	int	y;

	grid = create_grid(ROW_SIZE, COL_SIZE);
	solve_default_case(grid, str);
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
	x = 0;
	while (x < ROW_SIZE)
	{
		free(grid[x]);
		x++;
	}
	free(grid);
	return (true);
}
