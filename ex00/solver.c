/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iavautra <iavautra@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 07:03:45 by iavautra          #+#    #+#             */
/*   Updated: 2024/06/29 18:35:00 by iavautra         ###   ########.fr       */
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
		if (str[i] == '1')
		{
			grid[0][j] = 4;

		}
		if (str[i] == '4')
		{
			grid[0][j] = 1;
			grid[1][j] = 2;
			grid[2][j] = 3;
			grid[3][j] = 4;
		}
		j++;
		i++;
	}

	i += 8;
	j = 0;
	while (j < 4)
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '1')
		{
			grid[j][0] = 4;
		}
		if (str[i] == '4')
		{
			grid[j][0] = 1;
			grid[j][1] = 2;
			grid[j][2] = 3;
			grid[j][3] = 4;
		}
		j++;
		i++;
	}

	j = 0;
	while (j < 4)
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '1')
			grid[j][3] = 4;
		j++;
		i++;
	}
}


bool	try_solving(const char *str)
{
	int	**grid;

	grid = create_grid(ROW_SIZE, COL_SIZE);
	solve_default_case(grid, str);
	grid = backtrack_solve(grid, str);
	if (grid == NULL)
		return (false);
	print_grid(grid);
	remove_grid(grid);
	return (true);
}
