/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 22:15:47 by tmlkshk           #+#    #+#             */
/*   Updated: 2019/09/28 22:21:51 by tmlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!n)
		return (1);
	if (!s1 || !s2)
		return (0);
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
		n--;
		if (!n)
			return (1);
	}
	if (!*s1 && !*s2)
		return (1);
	return (0);
}
