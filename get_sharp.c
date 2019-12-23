/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sharp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 14:23:22 by tmlkshk           #+#    #+#             */
/*   Updated: 2019/12/12 14:26:42 by tmlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			getmin(int a, int b, int c, int d)
{
	int		min;

	min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	if (min > d)
		min = d;
	return (min);
}

t_point		*optimize_sharps(t_point *sharps)
{
	t_point	*temp;
	int		count;
	int		min;

	temp = sharps;
	min = getmin(temp[0].x, temp[1].x, temp[2].x, temp[3].x);
	count = 0;
	while (count < 4)
	{
		temp[count].x = temp[count].x - min;
		count++;
	}
	min = getmin(temp[0].y, temp[1].y, temp[2].y, temp[3].y);
	count = 0;
	while (count < 4)
	{
		temp[count].y = temp[count].y - min;
		count++;
	}
	return (temp);
}

t_point		*get_sharps2(char *temp, t_point *sharps)
{
	int		g;
	int		k;
	int		sharp;

	sharp = 0;
	g = 0;
	k = 0;
	while (*temp != '\0')
	{
		if (*temp == '#')
		{
			sharps[sharp++].y = k;
			sharps[sharp - 1].x = g;
			k++;
		}
		else if (*temp == '\n')
		{
			g++;
			k = 0;
		}
		else
			k++;
		temp++;
	}
	return (sharps);
}
