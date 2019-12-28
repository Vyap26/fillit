/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 10:15:00 by tmlkshk           #+#    #+#             */
/*   Updated: 2019/09/29 10:45:19 by tmlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_itoa_op(void)
{
	char *string;

	if ((string = (char*)malloc(1 * sizeof(char) + 1)) == NULL)
		return (NULL);
	string[0] = '0';
	string[1] = '\0';
	return (string);
}

static	int		ft_itoa_num(long n)
{
	long	i;

	i = 0;
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	int		i;
	char	*string;
	long	super;

	if (n == 0)
		return (ft_itoa_op());
	super = n;
	i = ft_itoa_num(super);
	if ((string = (char*)malloc(i * sizeof(char) + 1)) == NULL)
		return (NULL);
	if (super < 0)
	{
		string[0] = '-';
		super = -super;
	}
	string[i--] = '\0';
	while (super)
	{
		string[i] = super % 10 + 48;
		i--;
		super /= 10;
	}
	return (string);
}
