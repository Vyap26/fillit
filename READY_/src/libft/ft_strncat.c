/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 12:26:57 by tmlkshk           #+#    #+#             */
/*   Updated: 2019/09/28 12:41:02 by tmlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	count;
	size_t	num;

	count = ft_strlen(s1);
	num = 0;
	while (n > num && s2[num] != '\0')
	{
		s1[num + count] = s2[num];
		num++;
	}
	s1[num + count] = '\0';
	return (s1);
}
