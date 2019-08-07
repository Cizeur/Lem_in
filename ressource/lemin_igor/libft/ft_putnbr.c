/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:18:57 by igarbuz           #+#    #+#             */
/*   Updated: 2018/11/08 11:45:58 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long int l;

	l = n;
	if (l < 0)
	{
		ft_putchar('-');
		l *= -1;
	}
	if (l / 10)
		ft_putnbr(l / 10);
	ft_putchar(l % 10 + '0');
}
