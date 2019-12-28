/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 22:30:45 by tmlkshk           #+#    #+#             */
/*   Updated: 2019/09/28 22:37:16 by tmlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		k;
	char	*string;

	if (!s1 || !s2)
		return (NULL);
	j = ft_strlen(s1);
	i = ft_strlen(s2);
	k = 0;
	if ((string = (char *)malloc((i + j) * sizeof(char) + 1)) == NULL)
		return (NULL);
	while (*s1)
	{
		string[k] = *s1++;
		k++;
	}
	while (*s2)
	{
		string[k] = *s2++;
		k++;
	}
	string[k] = '\0';
	return (string);
}
