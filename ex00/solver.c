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

bool	try_solving(const char *str)
{
	int	**grid;

	grid = create_grid(ROW_SIZE, COL_SIZE);
	if (!backtrack_solve(grid, str, 0, 0))
	{
		remove_grid(grid);
		return (false);
	}
	print_grid(grid);
	remove_grid(grid);
	return (true);
}
