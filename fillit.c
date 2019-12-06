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
    t_tetra *smpl;
      
    smpl = ft_filllst();// заполняем лист образцами
    if (ft_checkfile(fd, smpl) == -1)// проверка, сравнение и заполнение листа с образцами
        return ("error\n");
    while (smpl)
    {
        printf("%s\n", smpl->name);
        printf("%s\n", smpl->img);
        printf("%d\n", smpl->num);
        smpl = smpl-> next;
    }  
    // else создание файла и заполнение
    // free smpl
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
