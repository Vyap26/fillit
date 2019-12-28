/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:49:43 by tmlkshk           #+#    #+#             */
/*   Updated: 2019/09/21 15:56:16 by tmlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	b;

	i = 0;
	b = (unsigned char)c;
	a = (unsigned char *)s;
	while (i < n)
	{
		if (a[i] == b)
			return (a + i);
		i++;
	}
	return (NULL);
}
