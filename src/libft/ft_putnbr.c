/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 11:09:43 by tmlkshk           #+#    #+#             */
/*   Updated: 2019/09/29 11:15:54 by tmlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long	num;
	size_t	ten;
	short	temp;

	if (n == 0)
		return (ft_putchar('0'));
	num = n;
	ten = 1;
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	while (num / ten)
		ten = ten * 10;
	ten = ten / 10;
	while (ten)
	{
		temp = num / ten;
		ft_putchar(temp + 48);
		num -= ten * temp;
		ten = ten / 10;
	}
}
