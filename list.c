/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 18:08:33 by tmlkshk           #+#    #+#             */
/*   Updated: 2019/12/14 18:08:43 by tmlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_kvad	*new_kvad(t_kvad *kvad, t_point *sharps, char name) //создает 1 элемент и пишет в него шарпс и имя (для головы)
{
	kvad = (t_kvad *)malloc(sizeof(t_kvad));
	kvad->name = name;
	kvad->next = NULL;
	kvad->tetri = sharps;
	return (kvad);
}

void	delete_kvad(t_kvad *kvad)
{
	t_kvad	*opa;

	while (kvad)
	{
		opa = kvad;
		kvad = kvad->next;
		free(opa->tetri);
		free(opa);
		opa = NULL;
	}
}

t_kvad	*rest(t_kvad *kvad, t_point *sharps)
{
	t_kvad	*opa;
	char	name;

	opa = kvad;
	if (kvad && sharps)
	{
		name = kvad->name;
		while (kvad->next)
		{
			kvad = kvad->next;
			name++;
		}
		name++;
		kvad->next = new_kvad(kvad->next, sharps, name);
	}
	else
		delete_kvad(kvad);
	kvad = opa;
	return (kvad);
}

t_kvad	*save_kvad(t_kvad *kvad, t_point *sharps)
{
	if(!sharps)
		delete_kvad(kvad);
	else if (!kvad)
	{
		if (!(kvad = new_kvad(kvad, sharps, 'A')))
			delete_kvad(kvad);
	}
	else if (!(kvad = rest(kvad, sharps)))
		delete_kvad(kvad);
	return (kvad);
}

t_kvad *get_tetri(t_kvad *all, char *str)
{
	t_point	*sharps;

//	all = NULL;
//	all = (t_kvad *)malloc(sizeof(t_kvad));
	sharps = NULL;
	sharps = get_sharps2(str);
	all = save_kvad(all, sharps);
	return (all);
}
