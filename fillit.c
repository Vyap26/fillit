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

char    *ft_fillit(int fd)
{
    if (ft_checkfile(fd) == -1)
        return ("error\n");    
    // else создание файла и заполнение
    return ("ok\n");
}

int    main(void)
{
    char    *res;
    int     fd;

    fd = open("test.txt", O_RDONLY);
    res = ft_fillit(fd);
    if (res)
        ft_putstr(res);
    fd = close(fd);
    return (0);
}
