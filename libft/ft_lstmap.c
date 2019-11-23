/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 12:40:41 by tmlkshk           #+#    #+#             */
/*   Updated: 2019/09/29 12:46:21 by tmlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*first;
	t_list	*second;

	if (!lst || !f)
		return (NULL);
	second = f(lst);
	first = second;
	while (lst->next)
	{
		first->next = f(lst->next);
		first = first->next;
		lst = lst->next;
	}
	return (second);
}
