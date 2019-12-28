/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 12:29:28 by tmlkshk           #+#    #+#             */
/*   Updated: 2019/09/29 12:31:44 by tmlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (!alst && del)
		return ;
	while (*alst)
	{
		tmp = *alst;
		ft_lstdelone(alst, del);
		*alst = tmp->next;
	}
	*alst = NULL;
}
