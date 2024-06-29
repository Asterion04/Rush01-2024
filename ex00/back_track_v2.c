/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_track_v2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iavautra <iavautra@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:13:07 by iavautra          #+#    #+#             */
/*   Updated: 2024/06/29 18:36:00 by iavautra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

bool	check_visibility_bottom(int **grid, const char *str, int start)
{
	int	x;
	int	y;
	int	count;
	int	max_height;

	x = 0;
	while (x < ROW_SIZE)
	{
		y = COL_SIZE - 1;
		max_height = 0;
		count = 0;
		while (y >= 0)
		{
			if (grid[x][y] > max_height)
			{
				max_height = grid[x][y];
				count++;
			}
			y--;
		}
		if (str[start + x] == ' ')
			start++;
		if (str[start + x] - '0' != count)
			return (false);
		x++;
	}
	return (true);
}

bool	check_visibility_left(int **grid, const char *str, int start)
{
	int	x;
	int	y;
	int	count;
	int	max_height;

	y = 0;
	while (y < COL_SIZE)
	{
		x = 0;
		max_height = 0;
		count = 0;
		while (x < ROW_SIZE)
		{
			if (grid[x][y] > max_height)
			{
				max_height = grid[x][y];
				count++;
			}
			x++;
		}
		if (str[start + y] == ' ')
			start++;
		if (str[start + y] - '0' != count)
			return (false);
		y++;
	}
	return (true);
}

bool	check_visibility_right(int **grid, const char *str, int start)
{
	int	x;
	int	y;
	int	count;
	int	max_height;

	y = 0;
	while (y < COL_SIZE)
	{
		x = ROW_SIZE - 1;
		max_height = 0;
		count = 0;
		while (x >= 0)
		{
			if (grid[x][y] > max_height)
			{
				max_height = grid[x][y];
				count++;
			}
			x--;
		}
		if (str[start + y] == ' ')
			start++;
		if (str[start + y] - '0' != count)
			return (false);
		y++;
	}
	return (true);
}

bool	check_visibility_top(int **grid, const char *str, int start)
{
	int	x;
	int	y;
	int	count;
	int	max_height;

	x = 0;
	while (x < ROW_SIZE)
	{
		y = 0;
		max_height = 0;
		count = 0;
		while (y < COL_SIZE)
		{
			if (grid[x][y] > max_height)
			{
				max_height = grid[x][y];
				count++;
			}
			y++;
		}
		if (str[start + x] == ' ')
			start++;
		if (str[start + x] - '0' != count)
			return (false);
		x++;
	}
	return (true);
}

bool	is_correct(int **grid, const char *str)
{
	int	x;
	int	y;

	if (grid == NULL)
		return (false);
	x = 0;
	while (x < ROW_SIZE)
	{
		y = 0;
		while (y < COL_SIZE)
		{
			if (grid[x][y] == 0)
				return (false);
			y++;
		}
		x++;
	}
	if (!check_visibility_top(grid, str, 0) || \
		!check_visibility_bottom(grid, str, 8) || \
		!check_visibility_left(grid, str, 16) || \
		!check_visibility_right(grid, str, 24))
		return (false);
	return (true);
}

bool	backtrack_solve(int **grid, const char *str, int row, int col)
{
	int	value;

	if (row == ROW_SIZE)
	{
		row = 0;
		if (++col == COL_SIZE)
			return (is_correct(grid, str));
	}
	if (grid[row][col] != 0)
		return (backtrack_solve(grid, str, row + 1, col));
	value = 1;
	while (value <= 4)
	{
		if (grid[row][col] == 0 && is_safe(grid, row, col, value))
		{
			grid[row][col] = value;
			if (backtrack_solve(grid, str, row + 1, col))
				return (true);
			grid[row][col] = 0;
		}
		value++;
	}
	return (false);
}
