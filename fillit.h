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

typedef	struct		s_tetra
{
	char 			*name;
	char			*img;
	int				num;
	struct s_tetra	*next;
}					t_tetra;

#endif
