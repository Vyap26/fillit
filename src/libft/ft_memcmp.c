/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:59:33 by tmlkshk           #+#    #+#             */
/*   Updated: 2019/09/21 16:10:37 by tmlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			a;
	unsigned char	*op;
	unsigned char	*up;

	a = 0;
	op = (unsigned char *)s1;
	up = (unsigned char *)s2;
	while (a < n)
	{
		if (op[a] == up[a])
			a++;
		else
			return (op[a] - up[a]);
	}
	return (0);
}
