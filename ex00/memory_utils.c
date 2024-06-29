/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iavautra <iavautra@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 07:14:14 by iavautra          #+#    #+#             */
/*   Updated: 2024/06/29 17:08:24 by iavautra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	**create_grid(int row_size, int col_size)
{
	int	**grid;
	int	x;
	int	y;

	grid = (int **) malloc(row_size * col_size * sizeof(int));
	x = 0;
	while (x < row_size)
	{
		grid[x] = (int *) malloc(col_size * sizeof(int));
		y = 0;
		while (y < COL_SIZE)
		{
			grid[x][y] = 0;
			y++;
		}
		x++;
	}
	return (grid);
}

void	remove_grid(int **grid)
{
	int	x;

	x = 0;
	while (x < ROW_SIZE)
	{
		free(grid[x]);
		x++;
	}
	free(grid);
}

void	copy_grid(int **grid_dest, int **grid_src)
{
	int	x;
	int	y;

	x = 0;
	while (x < ROW_SIZE)
	{
		y = 0;
		while (y < COL_SIZE)
		{
			grid_dest[x][y] = grid_src[x][y];
			y++;
		}
		x++;
	}
}
