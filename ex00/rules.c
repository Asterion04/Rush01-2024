/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iavautra <iavautra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 06:44:05 by iavautra          #+#    #+#             */
/*   Updated: 2024/06/29 08:55:23 by iavautra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

bool	rules_check_format(const char *str)
{
	int	i;

	if (ft_strlen(str) != 31)
		return (false);
	i = 0;
	while (i < 31 && str[i] != '\0')
	{
		if ((str[i] >= '1' && str[i] <= '4') || str[i] == ' ')
			i++;
		else
			return (false);
	}
	return (true);
}
