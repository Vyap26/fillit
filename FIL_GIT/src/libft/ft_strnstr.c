/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:12:19 by tmlkshk           #+#    #+#             */
/*   Updated: 2019/09/29 17:04:51 by tmlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *nee, size_t n)
{
	char	*mass;
	char	*op;
	size_t	a;
	size_t	b;

	mass = (char *)hay;
	op = (char *)nee;
	if (!(a = 0) && *nee == '\0')
		return ((char *)hay);
	while (mass[a] != '\0' && a < n)
	{
		b = 0;
		while (op[b] == mass[a + b] && op[b] && a + b < n)
			b++;
		if (op[b] == '\0')
			return ((char *)(mass + a));
		a++;
	}
	return (NULL);
}
