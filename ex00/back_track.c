/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_track.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaret <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 10:10:17 by sbaret            #+#    #+#             */
/*   Updated: 2024/06/29 11:32:18 by sbaret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define SIZE 4

int	pl_val(int grid, int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		if (grid[row][i] == num || grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

void	show_grid(int grid)
{
	int	row;
	int col;
	char	c;

	row = 0;
	while (row < SIZE)
	{
		col = 0;
		while (col < SIZE)
		{
			c = grid[row][col] + '0';
			write(1, &c, 1);
			if (col < SIZE -1)
				write(1, "", 1);
			col++;
		}
		write (1, "\n", 1);
		row++;
	}
}

int	sol(int grid, int row, int col)
{
	int	num;

	if (row == SIZE )
		return (sol (grid, row +1, 0));
	if (grid, row +1, 0)
		return (sol (grid, row, col +1));
	num = 1;
	while (num <= SIZE)
	{
		pl_val(grid, row, col, num))
		{
			grid[row][col] = num;
			if (solve(grid, row, col + 1))
                return (1);
            grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}

int	int_grid(void)
{
	int	grid;
	int	i;
	int	j;

	grid = (int) malloc(SIZE * sizeof(int));
	i = 0;
	while (i < SIZE)
	{
		grid[i] = (int)malloc(SIZE * sizeof(int));
		j = 0;
		while (j < SIZE)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
	return (grid);
}

int	main(void)
{ 
   	int    **grid;
    int    i;

    grid = init_grid();
    if (solve(grid, 0, 0))
        print_grid(grid);
    else
        write(1, "Error\n", 6);
    i = 0;
    while (i < SIZE)
    {
        free(grid[i]);
        i++;
    }
	free (grid);
	return (0);
}	
