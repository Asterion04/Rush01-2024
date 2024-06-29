/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iavautra <iavautra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 07:14:14 by iavautra          #+#    #+#             */
/*   Updated: 2024/06/29 08:56:21 by iavautra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	**create_grid(int row_size, int col_size)
{
	int	**grid;
	int	x;

	grid = (int **) malloc(row_size * col_size * sizeof(int));
	x = 0;
	while (x < row_size)
	{
		grid[x] = (int *) malloc(col_size * sizeof(int));
		x++;
	}
	return (grid);
}
