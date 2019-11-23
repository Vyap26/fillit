/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:01:00 by tmlkshk           #+#    #+#             */
/*   Updated: 2019/09/29 14:31:53 by tmlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				x;
	unsigned char		*a;
	unsigned char		*a1;
	const unsigned char	*b;
	const unsigned char *b1;

	if (dst != NULL || src != NULL)
	{
		x = 0;
		a = (unsigned char *)dst;
		b = (unsigned char *)src;
		if (b < a)
		{
			a1 = a + (len - 1);
			b1 = b + (len - 1);
			while (len--)
				*a1-- = *b1--;
		}
		else
			while (len--)
				*a++ = *b++;
	}
	return (dst);
}
