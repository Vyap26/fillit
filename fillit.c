/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisidra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:43:46 by sisidra           #+#    #+#             */
/*   Updated: 2019/11/23 17:44:01 by sisidra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int    main(int ac, char **av) {
	char *res;
	int fd;
	t_kvad *all;
	char *a;
	char *z;

	z = "AB";
	a = "truba blat";
	if (ac != 2)
	{
		printf("%s\n", a);
		return (0);
	}
    fd = open(av[1], O_RDONLY);
	printf("%s\n", a);
	all = NULL;
    if ((ft_checkfile(fd, all)) == 0)// проверка, сравнение с образцами
//		while (all)
//		{
//			printf("%s\n", z);
//			all = all->next;
//			z++;
//		}
    	solve(all);
//    else
//    	printf("%s\n", a);
    close(fd);
    return (0);
}
