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

int    main(void)
{
    char    *res;
    int     fd;
    t_kvad *all;

    fd = open("test.txt", O_RDONLY);
    if (ft_checkfile(fd, &all) != 0)// проверка, сравнение с образцами
        res = "error\n";
    
    if (res)
        ft_putstr(res);
    fd = close(fd);
    return (0);
}
