/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 14:10:24 by tmlkshk           #+#    #+#             */
/*   Updated: 2019/09/28 14:28:37 by tmlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*a;

	a = s;
	while (*a)
		a++;
	if (c == 0)
		return ((char *)a);
	while (*a != (char)c && a != s)
		a--;
	if (*a == (char)c)
		return ((char *)a);
	return (NULL);
}
