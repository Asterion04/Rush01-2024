/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iavautra <iavautra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 06:44:52 by iavautra          #+#    #+#             */
/*   Updated: 2024/06/30 14:19:02 by iavautra         ###   ########.fr       */
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
bool	rules_check_row_clues(int **grid, int row, int col, int *clue_array);
bool	rules_check_col_clues(int **grid, int row, int col, int *clue_array);
bool	rules_check_duplicates(int **grid, int row, int col, int height);

bool	check_visibility(int *line, int size, int clue);

void	print_grid(int **grid);
int		print_error(void);

bool	try_solving(const char *str);

void	remove_grid(int **grid);
int		**create_grid(int row_size, int col_size);

bool	backtrack_solve(int **grid, const char *str, int row, int col);

#endif // RUSH01_H
