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

int		main(int ac, char **av)
{
	char	*res;
	int		fd;
	t_kvad	*all;
	char	*a;
	char	*z;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		all = NULL;
	}
    if (!(all = ft_checkfile(fd, all)))
		ft_putstr("error\n");
	else
    	solve(all);
    close(fd);
    return (0);
}

int		checkend(fd)
{

}

int		ft_checktetra(char **tmp, char *res, int fd, char **line)
{
	char	*abr;
	int		gnl;
	
	if (ft_checkv(tmp) == -1)
		return (-1);
    ft_cutrow(tmp);
	ft_cutcol(tmp);
	ft_putimg(tmp, res);
	abr = ft_strdup(*line);
	ft_putstr(*line);
	ft_putchar('\n');
	gnl = get_next_line(fd, &abr);
	ft_putnbr(gnl);
	ft_putchar('\n');
	
	if ((ft_compare(res) != 0) || (gnl == 1 && *abr != '\0'))
		return (-1);
	free(abr);
	return (0);
}

t_kvad		*ft_checkfile(int fd, t_kvad *all)
{
	int		i;
    int		ret;
    char	*line;
    char	*tmp[4];
    char	res[20];

    ret = get_next_line(fd, &line);
    i = 0;
    while (ret > 0)
    {
        tmp[i++] = ft_strdup(line);
        if (i == 4)
        {
            if (ft_checktetra(tmp, res, fd, &line) != 0)
				return (NULL);
			all = get_tetri(all, res);
            i = 0;
        }
		free(line);
        if (ret != 0)
        ret = get_next_line(fd, &line);
	}
    return (all);
}