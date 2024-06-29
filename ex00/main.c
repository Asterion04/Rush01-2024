/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iavautra <iavautra@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 06:39:20 by iavautra          #+#    #+#             */
/*   Updated: 2024/06/29 17:03:48 by iavautra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	main(int argc, char *argv[])
{
	bool	is_success;

	if (argc != 2)
		return (print_error());
	if (!rules_check_format(argv[1]))
		return (print_error());
	is_success = try_solving(argv[1]);
	if (!is_success)
		return (print_error());
	return (0);
}
