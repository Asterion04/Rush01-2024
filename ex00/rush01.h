/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iavautra <iavautra@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 06:44:52 by iavautra          #+#    #+#             */
/*   Updated: 2024/06/29 15:06:29 by iavautra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define ROW_SIZE	4
# define COL_SIZE	4
# define ERROR_MSG	"Erreur\n"

size_t	ft_strlen(const char *str);

bool	is_safe(int **grid, int row, int col, int value);

bool	rules_check_format(const char *str);

void	print_grid(int **grid);
int		print_error(void);

bool	try_solving(const char *str);

void	remove_grid(int **grid);
int		**create_grid(int row_size, int col_size);

void	copy_grid(int **grid_dest, int **grid_src);

int	**backtrack_solve(int **grid, const char *str);

#endif // RUSH01_H
