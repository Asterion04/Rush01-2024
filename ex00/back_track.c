/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_track.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iavautra <iavautra@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:13:07 by iavautra          #+#    #+#             */
/*   Updated: 2024/06/30 14:43:59 by iavautra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	parse_clues(const char *clues, int *clue_array)
{
	int	i;

	i = 0;
	while (i < ROW_SIZE * COL_SIZE)
	{
		if (*clues == ' ')
			clues++;
		clue_array[i] = *clues - '0';
		clues++;
		i++;
	}
}

bool	check_visibility(int *line, int size, int clue)
{
	int	max_height;
	int	visible_count;
	int	i;

	visible_count = 0;
	max_height = 0;
	i = 0;
	while (i < size)
	{
		if (line[i] > max_height)
		{
			max_height = line[i];
			visible_count++;
		}
		i++;
	}
	return (visible_count == clue);
}

bool	is_valid(int **grid, const char *clues, int *rowcol, int height)
{
	int	clue_array[ROW_SIZE * COL_SIZE];
	int	row;
	int	col;

	row = rowcol[0];
	col = rowcol[1];
	parse_clues(clues, clue_array);
	grid[row][col] = height;
	if (!rules_check_duplicates(grid, row, col, height))
	{
		grid[row][col] = 0;
		return (false);
	}
	if (!rules_check_row_clues(grid, row, col, clue_array))
	{
		grid[row][col] = 0;
		return (false);
	}
	if (!rules_check_col_clues(grid, row, col, clue_array))
	{
		grid[row][col] = 0;
		return (false);
	}
	return (true);
}

bool	backtrack_solve(int **grid, const char *str, int row, int col)
{
	int	value;

	if (row == ROW_SIZE)
		return (true);
	if (col == COL_SIZE)
		return (backtrack_solve(grid, str, row + 1, 0));
	if (grid[row][col] != 0)
		return (backtrack_solve(grid, str, row, col + 1));
	value = 1;
	while (value <= 4)
	{
		if (is_valid(grid, str, (int []){row, col}, value))
		{
			grid[row][col] = value;
			if (backtrack_solve(grid, str, row, col + 1))
				return (true);
			grid[row][col] = 0;
		}
		value++;
	}
	return (false);
}
