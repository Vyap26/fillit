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
    int ret;
    char *line;
    char *tmp[4];
    int fig;
    int i;
    
    ret = get_next_line(fd, &line);
    i = 0;
    while (ret > 0)
    {
        tmp[i] = ft_strdup(line);//filling array with checked strings
        i++;
        if (i == 4)
        {
            if (ft_checkv(tmp) == -1)
                return ("tetrimino error\n");
            fig = 0;//figure_out(tmp);//decode the array to it's contains figure
            i = 0;
            //here will be a function that put the figure to array
            //free the tmp
            //ft_putchar('\n'); 
            if (get_next_line(fd, &line) == 1 && *line != '\0') // if i==4 && (line[0] != '\0' && ret == 0) mean an error
                return ("file error\n");
        }
        free(line);
        if (ret != 0)
            ret = get_next_line(fd, &line);
    }
    return(tmp[i]);
}

int    main(void)
{
    char    *res;
    int     fd;

    fd = open("test.txt", O_RDONLY);
    res = ft_fillit(fd);
    if (res)
        {
            ft_putstr(res);
    //        free(res);
        }
    fd = close(fd);
    return (0);
}
