/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:16:21 by tmlkshk           #+#    #+#             */
/*   Updated: 2019/11/23 16:17:20 by tmlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"

typedef struct	s_point
{
	int 			x;
	int 			y;
}					t_point;

typedef	struct		s_kvad
{
	char			name;
	struct s_kvad	*next;
	t_point			*tetri;
}					t_kvad;

typedef struct	s_map
{
	int 			size;
	char 			**map;
}					t_map;

int	getmin(int a, int b, int c, int d);
t_point	*optimize_sharps(t_point *sharps);
t_point	*get_sharps(char *data);
t_point	*figure();
int	ft_checkstr(char *str);
int	ft_checkv(char **tmp);
int	ft_checkfile(int fd);
void	ft_putimg(char **tmp, char *res);
int	ft_compare(char *str);

#endif
