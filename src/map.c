/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 20:19:11 by tmlkshk           #+#    #+#             */
/*   Updated: 2019/12/23 20:19:20 by tmlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_map_size(t_kvad *kvad)
{
	int		size;
	int		i;

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

t_map	*generate_map(int size)
{
	t_map	*map;
	int		count;

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
