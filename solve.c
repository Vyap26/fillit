/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 19:07:59 by tmlkshk           #+#    #+#             */
/*   Updated: 2019/12/14 19:08:02 by tmlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		solve_map(t_map *map, t_kvad *kvad)
{
	t_point	*pos;

	if (!kvad)
		return (1);
	pos = (t_point*)malloc(sizeof(t_point));
	pos->x = 0;
	while (pos->x < map->size)
	{
		pos->y = 0;
		while (pos->y < map->size)
		{
			if (place_kvad(map, pos, kvad))
			{
				if (solve_map(map, kvad->next))
					return (free_n_return(pos));
				else
					clear_last(map, pos, kvad);
			}
			pos->y++;
		}
		pos->x++;
	}
	free(pos);
	return (0);
}

int		get_solution(t_map *map, t_kvad *kvad)
{
	if (solve_map(map, kvad))
	{
		print_map(map);
		return (1);
	}
	return (0);
}

void	solve(t_kvad *kvad)
{
	t_map	*map;
	int		size;

	map = generate_map(get_map_size(kvad));
	size = map->size;
	while (!get_solution(map, kvad))
	{
		size++;
		delete_map(map);
		map = generate_map(size);
	}
	delete_map(map);
}
