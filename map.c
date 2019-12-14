/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 13:48:00 by tmlkshk           #+#    #+#             */
/*   Updated: 2019/12/14 13:48:03 by tmlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*make_map()
{
	char	*map;
	int 	count;
	int 	op;

	map = (char*)malloc(sizeof(char) * 21);
	count = 1;
	op = 0;
	while (count < 21)
	{
		if (count % 5 != 0)
		{
			map[op] = '.';
			count++;
			op++;
		}
		else
		{
			map[op] = '\n';
			count++;
			op++;
		}
	}
	map[op] = '\0';
	return (map);
}

char	*fill_map(char *map, t_point *sharps)
{
	int 	i;
	char	*r_map;
	int 	line;

	i = 0;
	line = 0;
	r_map = map;
	i = sharps[line].x;
	if (r_map[i] == '.')
		r_map[i] = 'A';
	line++;
	i = sharps[line].x + 5;
	if (r_map[i] == '.')
		r_map[i] = 'A';
	line++;
	i = sharps[line].x + 10;
	if (r_map[i] == '.')
		r_map[i] = 'A';
	line++;
	i = sharps[line].x + 15;
	if (r_map[i] == '.')
		r_map[i] = 'A';
	return (r_map);
}

int 	main()
{
	char	*ready_map;

	ready_map = fill_map(make_map(), figure());
	printf("%s\n", ready_map);
	return (0);
}