/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iavautra <iavautra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 06:44:05 by iavautra          #+#    #+#             */
/*   Updated: 2024/06/30 14:20:43 by iavautra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

bool	rules_check_format(const char *str)
{
	int	i;

	if (ft_strlen(str) != 31)
		return (false);
	i = 0;
	while (i < 31 && str[i] != '\0')
	{
		if ((str[i] >= '1' && str[i] <= '4') || str[i] == ' ')
			i++;
		else
			return (false);
	}
	return (true);
}

bool	rules_check_duplicates(int **grid, int row, int col, int height)
{
	int	i;

	i = 0;
	while (i < COL_SIZE)
	{
		if ((i != col && grid[row][i] == height) || \
			(i != row && grid[i][col] == height))
			return (false);
		i++;
	}
	return (true);
}

bool	rules_check_row_clues(int **grid, int row, int col, int *clue_array)
{
	int	left_clue;
	int	right_clue;
	int	line[4];
	int	reversed_line[4];
	int	i;

	left_clue = clue_array[8 + row];
	right_clue = clue_array[12 + row];
	if (left_clue == 0 && right_clue == 0)
		return (true);
	i = -1;
	while (++i < COL_SIZE)
		line[i] = grid[row][i];
	if (left_clue != 0 && col == COL_SIZE - 1 && \
		!check_visibility(line, COL_SIZE, left_clue))
		return (false);
	if (right_clue != 0 && col == COL_SIZE - 1)
	{
		i = -1;
		while (++i < COL_SIZE)
			reversed_line[i] = line[COL_SIZE - 1 - i];
		if (!check_visibility(reversed_line, COL_SIZE, right_clue))
			return (false);
	}
	return (true);
}


bool	rules_check_col_clues(int **grid, int row, int col, int *clue_array)
{
	int	up_clue;
	int	down_clue;
	int	line[4];
	int	reversed_line[4];
	int	i;

	up_clue = clue_array[col];
	down_clue = clue_array[4 + col];
	if (up_clue == 0 && down_clue == 0)
		return (true);
	i = -1;
	while (++i < COL_SIZE)
		line[i] = grid[i][col];
	if (up_clue != 0 && row == COL_SIZE - 1 && \
		!check_visibility(line, COL_SIZE, up_clue))
		return (false);
	if (down_clue != 0 && row == COL_SIZE - 1)
	{
		i = -1;
		while (++i < COL_SIZE)
			reversed_line[i] = line[COL_SIZE - 1 - i];
		if (!check_visibility(reversed_line, COL_SIZE, down_clue))
			return (false);
	}
	return (true);
}

