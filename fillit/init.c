/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:34:22 by jucapik           #+#    #+#             */
/*   Updated: 2018/11/26 15:20:18 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "backtrack.h"
#include "libft/includes/libft.h"

int		init_size(int surfacemin)
{
	int count;

	count = 2;
	printf("count = %d, surfacemin = %d\n", count, surfacemin);
	while (count * count < surfacemin)
	{
		printf("count = %d, surfacemin = %d\n", count, surfacemin);
		count++;
	}
	return (count);
}

void	init_tab(char tab[LIMTAB][LIMTAB])
{
	int i;
	int j;

	i = 0;
	while (i < LIMTAB)
	{
		j = 0;
		while (j < LIMTAB)
			tab[i][j++] = '.';
		i++;
	}
}

void	print_tab(int size, char tab[LIMTAB][LIMTAB])
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
			ft_putchar(tab[i][j++]);
		ft_putchar('\n');
		i++;
	}
}
