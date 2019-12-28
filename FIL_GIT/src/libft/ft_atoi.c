/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 17:50:07 by tmlkshk           #+#    #+#             */
/*   Updated: 2019/09/28 18:14:54 by tmlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int y;
	int n;
	int znak;

	y = 0;
	while (str[y] == ' ' || str[y] == '\n' || str[y] == '\t' || str[y] == '\f'
		|| str[y] == '\v' || str[y] == '\r')
		y++;
	znak = 1;
	if (str[y] == '+' || str[y] == '-')
	{
		if (str[y++] == '+')
			znak = 1;
		else
			znak = -1;
	}
	n = 0;
	while (str[y] >= '0' && str[y] <= '9')
	{
		n = 10 * n + str[y] - '0';
		y++;
	}
	return (znak * n);
}
