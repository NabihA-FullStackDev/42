/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:47:35 by naali             #+#    #+#             */
/*   Updated: 2018/11/16 01:27:35 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_putnbr(int n)
{
	int		cp;
	int		mod;

	mod = 1;
	if (n >= 0)
		n = n * (-1);
	else
		ft_putchar('-');
	cp = n;
	while (cp < -9)
	{
		cp = cp / 10;
		mod = mod * 10;
	}
	while (mod > 0)
	{
		ft_putchar('0' + ((n / mod) * -1));
		n = n % mod;
		mod = mod / 10;
	}
}
