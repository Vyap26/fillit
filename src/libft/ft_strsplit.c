/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 09:35:37 by tmlkshk           #+#    #+#             */
/*   Updated: 2019/09/29 10:14:01 by tmlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**ft_strsplit_mass(char const *str, char c)
{
	int count;
	int i;

	count = 0;
	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			while (str[i] != c && str[i] != '\0')
				i++;
			count++;
			continue ;
		}
		i++;
	}
	if (!count)
		return (NULL);
	return ((char **)malloc(count * sizeof(char*) + 1));
}

static	char	**ft_strsplit_opa(void)
{
	char	**raz;

	raz = (char **)malloc(sizeof(char));
	if (raz == NULL)
		return (NULL);
	*raz = NULL;
	return (raz);
}

static	char	*ft_strsplit_slovo(char const *str, int i, int z, char c)
{
	int		j;
	char	*string;

	if ((string = (char *)malloc((z - i) * sizeof(char) + 1)) == NULL)
		return (NULL);
	j = 0;
	while (str[i] != c && str[i] != '\0')
	{
		string[j] = str[i];
		i++;
		j++;
	}
	string[j] = '\0';
	return (string);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**array;

	if (!s || !c)
		return (NULL);
	i = 0;
	k = 0;
	if ((array = ft_strsplit_mass(s, c)) == NULL)
		return (ft_strsplit_opa());
	while (s[i] && (j = i) >= 0)
	{
		if (s[i] != c)
		{
			while (s[j] != c && s[j] != '\0')
				j++;
			if ((array[k] = ft_strsplit_slovo(s, i, j, c)))
				k++;
			i = j - 1;
		}
		i++;
	}
	array[k] = NULL;
	return (!s ? NULL : array);
}
