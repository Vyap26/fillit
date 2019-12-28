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

int			cleanall(char **tmp, char *line, t_kvad *all, int i)
{
	if (tmp)
		arrdel(tmp, i);
	if (line)
		free(line);
	if (all)
		delete_kvad(all);
	return (0);
}

int			checkend(int fd)
{
	int		ret;
	char	str[BUFF_SIZE];

	ret = read(fd, &str, BUFF_SIZE);
	close(fd);
	if (str[ret - 1] != '\n' || str[ret - 2] == '\n')
		return (-1);
	return (0);
}

int			ft_checktetra(char **tmp, char *res, int fd, char **line)
{
	char	*abr;
	int		gnl;

	if (ft_checkv(tmp) == -1)
		return (-1);
	ft_cutrow(tmp);
	ft_cutcol(tmp);
	ft_putimg(tmp, res);
	abr = NULL;
	abr = ft_strjoin(abr, *line);
	gnl = get_next_line(fd, &abr);
	if ((ft_compare(res) != 0) || (gnl == 1 && *abr != '\0'))
		return (-1);
	ft_strdel(&abr);
	return (0);
}

t_kvad		*ft_checkfile(int fd, t_kvad *all, int i)
{
	char	*line;
	char	*tmp[4];
	char	res[20];

	while (get_next_line(fd, &line) > 0)
	{
		tmp[i++] = ft_strdup(line);
		if (i == 4)
		{
			if (ft_checktetra(tmp, res, fd, &line) != 0)
			{
				cleanall(tmp, line, all, i);
				return (NULL);
			}
			all = get_tetri(all, res);
			i = 0;
			arrdel(tmp, 4);
		}
		free(line);
	}
	free(line);
	return (i != 0 ? NULL + cleanall(tmp, line, all, i) : all);
}

int			main(int ac, char **av)
{
	int		fd;
	t_kvad	*all;

	fd = 0;
	if (ac == 2 && checkend(open(av[1], O_RDONLY)) == 0)
	{
		fd = open(av[1], O_RDONLY);
		all = NULL;
		if (!(all = ft_checkfile(fd, all, 0)))
			ft_putstr("error\n");
		else
		{
			solve(all);
			delete_kvad(all);
		}
	}
	else
		ft_putstr("error\n");
	close(fd);
	return (0);
}
