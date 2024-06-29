/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iavautra <iavautra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 06:44:52 by iavautra          #+#    #+#             */
/*   Updated: 2024/06/29 07:33:43 by iavautra         ###   ########.fr       */
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
bool	rules_check_format(const char *str);
int		print_error(void);

bool	try_solving(const char *str);
int		**create_grid(int row_size, int col_size);

#endif // RUSH01_H
