/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iavautra <iavautra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 06:39:20 by iavautra          #+#    #+#             */
/*   Updated: 2024/06/29 08:56:26 by iavautra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	main(int argc, char *argv[])
{
	bool	is_success;
	int		**grid;

	if (argc != 2)
		return (print_error());
	if (!rules_check_format(argv[1]))
		return (print_error());
	is_success = try_solving(argv[1]);
	return (0);
}
