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

int 	in_range(t_kvad *kvad, t_point *pos, int size) // проверяем, вписывается ли тетраминка в карту
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

int 	place_kvad(t_map *map, t_point *pos, t_kvad *kvad) //вписываем тетраминку в карту, если там точки
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

int 	free_n_return(t_point *pos) // обнуляем бегунок
{
		free (pos);
		return (1);
}

void	clear_last(t_map *map, t_point *pos, t_kvad *kvad) //возвращаем карте точки
{
	map->map[kvad->tetri[0].x + pos->x][kvad->tetri[0].y + pos->y] = '.';
	map->map[kvad->tetri[1].x + pos->x][kvad->tetri[1].y + pos->y] = '.';
	map->map[kvad->tetri[2].x + pos->x][kvad->tetri[2].y + pos->y] = '.';
	map->map[kvad->tetri[3].x + pos->x][kvad->tetri[3].y + pos->y] = '.';
}

int 	solve_map(t_map *map, t_kvad *kvad) //главная функция решения c рекурсией
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

int 	get_map_size(t_kvad *kvad) //кол-во тетраминок и минимальный размер стороны квадрата
{
	int 	size;
	int 	i;

	i = 0;
	size = 1;
	while (kvad)
	{
		i++;
		kvad = kvad->next;
	}
	while ((size * size) < (i * 4))
		size++;
	return (size);
}

t_map	*fill_map(t_map *map)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (i < map->size)
	{
		while (k < map->size)
		{
			map->map[i][k] = '.';
			k++;
		}
		k = 0;
		i++;
	}
	return (map);
}

void	delete_map(t_map *map)
{
	int		i;

	i = 0;
	while (map->map[i])
	{
		ft_strdel(&map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
	map = NULL;
	return ;
}

t_map	*generate_map(int size) // генерация карты
{
	t_map	*map;
	int 	count;

	count = 0;
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (0);
	map->size = size;
	if (!(map->map = (char**)malloc(sizeof(char*) * (size + 1))))
	{
		delete_map(map);
		return (0);
	}
	map->map[size] = NULL;
	while (count < size)
	{
		if (!(map->map[count] = ft_strnew(size)))
		{
			delete_map(map);
			return (0);
		}
		count++;
	}
	map = fill_map(map);
	return (map);
}

void	print_map(t_map *map)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (i < map->size)
	{
		while (k < map->size)
		{
			ft_putchar(map->map[i][k]);
			k++;
		}
		ft_putchar('\n');
		k = 0;
		i++;
	}
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
