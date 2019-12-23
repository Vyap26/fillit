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

int 	in_range(t_kvad *kvad, t_point *pos, int size);
int 	place_kvad(t_map *map, t_point *pos, t_kvad *kvad);
int 	free_n_return(t_point *pos);
void	clear_last(t_map *map, t_point *pos, t_kvad *kvad);
int 	solve_map(t_map *map, t_kvad *kvad);
int 	get_map_size(t_kvad *kvad);
t_map	*fill_map(t_map *map);
void	delete_map(t_map *map);
t_map	*generate_map(int size);
void	print_map(t_map *map);
int		get_solution(t_map *map, t_kvad *kvad);
void	solve(t_kvad *kvad);
t_kvad	*new_kvad(t_kvad *kvad, t_point *sharps, char name);
void	delete_kvad(t_kvad *kvad);
t_kvad	*rest(t_kvad *kvad, t_point *sharps);
t_kvad	*save_kvad(t_kvad *kvad, t_point *sharps);
t_kvad	*get_tetri(t_kvad *all, char *str);
t_point	*get_sharps2(char *temp);
int		getmin(int a, int b, int c, int d);
t_point	*optimize_sharps(t_point *sharps);
t_point	*get_sharps(char *data);
t_point	*figure();
int		ft_checkstr(char *str);
void	ft_cutrow(char **tmp);
void	ft_cutcol(char **tmp);
int		ft_checkv(char **tmp);
void	ft_putimg(char **tmp, char *res);
int		ft_compare(char *str);
int		ft_checktetra(char **tmp, char *res, int fd, char **line);
t_kvad	*ft_checkfile(int fd, t_kvad *all);

#endif
