/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 09:32:26 by tmlkshk           #+#    #+#             */
/*   Updated: 2019/09/29 14:35:21 by tmlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*temp;
	int		x;

	temp = (char*)malloc((ft_strlen(s1) + 1) * (sizeof(char)));
	if (temp == 0)
		return (0);
	x = 0;
	while (s1[x] != '\0')
	{
		temp[x] = s1[x];
		x++;
	}
	temp[x] = '\0';
	return (temp);
}
