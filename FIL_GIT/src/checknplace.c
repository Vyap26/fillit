/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checknplace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 20:24:39 by tmlkshk           #+#    #+#             */
/*   Updated: 2019/12/23 20:24:41 by tmlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		in_range(t_kvad *kvad, t_point *pos, int size)
{
	if (kvad->tetri[0].x + pos->x < 0 || kvad->tetri[0].x + pos->x >= size)
		return (0);
	if (kvad->tetri[1].x + pos->x < 0 || kvad->tetri[1].x + pos->x >= size)
		return (0);
	if (kvad->tetri[2].x + pos->x < 0 || kvad->tetri[2].x + pos->x >= size)
		return (0);
	if (kvad->tetri[3].x + pos->x < 0 || kvad->tetri[3].x + pos->x >= size)
		return (0);
	if (kvad->tetri[0].y + pos->y < 0 || kvad->tetri[0].y + pos->y >= size)
		return (0);
	if (kvad->tetri[1].y + pos->y < 0 || kvad->tetri[1].y + pos->y >= size)
		return (0);
	if (kvad->tetri[2].y + pos->y < 0 || kvad->tetri[2].y + pos->y >= size)
		return (0);
	if (kvad->tetri[3].y + pos->y < 0 || kvad->tetri[3].y + pos->y >= size)
		return (0);
	return (1);
}

int		place_kvad(t_map *map, t_point *pos, t_kvad *kvad)
{
	if (!in_range(kvad, pos, map->size))
		return (0);
	if (map->map[kvad->tetri[0].x + pos->x][kvad->tetri[0].y + pos->y] != '.')
		return (0);
	if (map->map[kvad->tetri[1].x + pos->x][kvad->tetri[1].y + pos->y] != '.')
		return (0);
	if (map->map[kvad->tetri[2].x + pos->x][kvad->tetri[2].y + pos->y] != '.')
		return (0);
	if (map->map[kvad->tetri[3].x + pos->x][kvad->tetri[3].y + pos->y] != '.')
		return (0);
	map->map[kvad->tetri[0].x + pos->x][kvad->tetri[0].y + pos->y] = kvad->name;
	map->map[kvad->tetri[1].x + pos->x][kvad->tetri[1].y + pos->y] = kvad->name;
	map->map[kvad->tetri[2].x + pos->x][kvad->tetri[2].y + pos->y] = kvad->name;
	map->map[kvad->tetri[3].x + pos->x][kvad->tetri[3].y + pos->y] = kvad->name;
	return (1);
}

int		free_n_return(t_point *pos)
{
	free(pos);
	return (1);
}

void	clear_last(t_map *map, t_point *pos, t_kvad *kvad)
{
	map->map[kvad->tetri[0].x + pos->x][kvad->tetri[0].y + pos->y] = '.';
	map->map[kvad->tetri[1].x + pos->x][kvad->tetri[1].y + pos->y] = '.';
	map->map[kvad->tetri[2].x + pos->x][kvad->tetri[2].y + pos->y] = '.';
	map->map[kvad->tetri[3].x + pos->x][kvad->tetri[3].y + pos->y] = '.';
}
