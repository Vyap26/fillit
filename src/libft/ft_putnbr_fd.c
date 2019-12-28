/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 11:29:32 by tmlkshk           #+#    #+#             */
/*   Updated: 2019/09/29 11:32:53 by tmlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	size_t	ten;
	short	temp;

	if (n == 0)
		return (ft_putchar_fd('0', fd));
	num = n;
	ten = 1;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num = -num;
	}
	while (num / ten)
		ten *= 10;
	ten /= 10;
	while (ten)
	{
		temp = num / ten;
		ft_putchar_fd(temp + 48, fd);
		num -= ten * temp;
		ten /= 10;
	}
}
