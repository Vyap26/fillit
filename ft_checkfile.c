/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisidra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 08:03:10 by sisidra           #+#    #+#             */
/*   Updated: 2019/12/10 08:45:19 by sisidra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_checkstr(char *str)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	if (ft_strlen(str) != 4 || !str)
		return (-1);
	while ((str[i] == '.' || str[i] == '#') && (str[i] != '\0'))
	{
		if (str[i] == '#' && flag == 0)
			flag = 1;
		else if (str[i] != '#' && flag == 1)
			flag = 2;
		if (str[i] == '#' && flag == 2)
			return (-1);
		if (i == 3 && flag == 0)
			flag = 1;
		i++;
	}
	return (0);
}

int		ft_checkv(char **tmp)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (i < 4 && j < 4)
	{
		while (j == 0 && ft_checkstr(tmp[i]) != 0)
			return (-1);
		if (tmp[i][j] == '#' && flag == 0)
			flag = 1;
		else if (tmp[i][j] == '.' && flag == 1)
			flag = 2;
		else if (tmp[i][j] == '#' && flag == 2)
			return (-1);
		i++;
		if (i == 4 && j++ < 4)
		{
			i = 0;
			flag = 0;
		}
	}
	return (0);
}

void	ft_cutrow(char **tmp)
{
	int i;
	int k;
	int t;

	i = 0;
	k = 3;
	while (i < 4)
	{
		t = i;
		while (ft_strcmp(tmp[t], "....") == 0)
		{
			while (t < k)
			{
				ft_strcpy(tmp[t], tmp[t + 1]);
				t++;
			}
			t = i;
			ft_strclr(tmp[k--]);
		}
		i++;
	}
}

void	ft_cutc(char **tmp, int i, int j)
{
	int t;

	t = j;
	while (i < 4)
	{
		if (t < 3)
		{
			tmp[i][t] = tmp[i][t + 1];
			t++;
		}
		if (t == 3)
		{
			tmp[i][t] = '\0';
			i++;
			t = j;
		}
	}
}

void	ft_cutcol(char **tmp)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < 4)
	{
		if (tmp[0][j] == '\0' && tmp[1][j] == '\0' && tmp[2][j] == '\0' &&
		tmp[3][j] == '\0')
			break ;
		if (tmp[0][j] != '#' && tmp[1][j] != '#' && tmp[2][j] != '#'
		&& tmp[3][j] != '#')
			ft_cutc(tmp, i, j);
		else
			j++;
	}
}
