/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iavautra <iavautra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 06:39:42 by iavautra          #+#    #+#             */
/*   Updated: 2024/06/29 07:34:06 by iavautra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

size_t	ft_strlen(const char *str)
{
	size_t	length;

	if (str == NULL)
		return (0);
	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

int	print_error(void)
{
	write(1, ERROR_MSG, ft_strlen(ERROR_MSG));
	return (1);
}
