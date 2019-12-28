/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 14:45:48 by tmlkshk           #+#    #+#             */
/*   Updated: 2019/09/29 14:28:16 by tmlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	if (dst != NULL || src != NULL)
	{
		a = (unsigned char *)dst;
		b = (unsigned char *)src;
		i = 0;
		while (i < n)
		{
			a[i] = b[i];
			i++;
		}
	}
	return (dst);
}
