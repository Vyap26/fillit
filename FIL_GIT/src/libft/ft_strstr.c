/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 15:34:27 by tmlkshk           #+#    #+#             */
/*   Updated: 2019/09/28 16:10:56 by tmlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	nl;
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	nl = ft_strlen(needle);
	if (nl == 0)
		return ((char *)haystack);
	while (haystack[a] != '\0')
	{
		while (needle[b] == haystack[a + b])
		{
			if (b == nl - 1)
				return ((char *)haystack + a);
			b++;
		}
		b = 0;
		a++;
	}
	return (NULL);
}
