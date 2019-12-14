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
# define NUMBER_OF_STRING 19
# define MAX_STRING_SIZE 11

typedef	struct		s_tetra
{
	char 			*name;
	char			*img;
	int				num;
	struct s_tetra	*next;
	
}					t_tetra;

typedef struct	s_point
{
	int 		x;
	int 		y;
}				t_point;

int	ft_checkstr(char *str);
int	ft_checkv(char **tmp);
int	ft_checkfile(int fd);
void	ft_putimg(char **tmp, char *res);
int	ft_compare(char *str);

#endif
