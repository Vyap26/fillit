/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 12:00:25 by tmlkshk           #+#    #+#             */
/*   Updated: 2019/09/29 12:07:39 by tmlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*mat;

	if ((mat = (t_list *)ft_memalloc(sizeof(t_list))))
	{
		if (!content)
		{
			mat->content = NULL;
			mat->content_size = 0;
		}
		else
		{
			if (!(mat->content = ft_memalloc(content_size)))
			{
				free(mat);
				return (NULL);
			}
			ft_memcpy(mat->content, content, content_size);
			mat->content_size = content_size;
		}
		mat->next = NULL;
	}
	return (mat);
}
