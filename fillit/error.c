/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 08:21:50 by jucapik           #+#    #+#             */
/*   Updated: 2018/11/25 12:48:41 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "error.h"
#include "libft/includes/libft.h"

int			errorlines(char *line)
{
	int i;

	if (ft_strlen(line) != 4)
		return (-1);
	i = 0;
	while (i < 4)
	{
		if (line[i] != '#' && line[i] != '.')
			return (-1);
		i++;
	}
	return (1);
}

static int	getnbconnect(char tab[4][5], int i, int j)
{
	int	nbconnect;

	nbconnect = 0;
	if (i + 1 < 4 && tab[i + 1][j] == '#')
		nbconnect++;
	if (i - 1 > 0 && tab[i - 1][j] == '#')
		nbconnect++;
	if (j + 1 < 4 && tab[i][j + 1] == '#')
		nbconnect++;
	if (j - 1 > 0 && tab[i][j - 1] == '#')
		nbconnect++;
	return (nbconnect);
}

int			errorform(char tab[4][5])
{
	int		i;
	int		j;
	int		nbhash;
	int		nbconnect;

	i = 0;
	nbhash = 0;
	nbconnect = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tab[i][j] == '#')
			{
				if (++nbhash > 4)
					return (-1);
				nbconnect += getnbconnect(tab, i , j);
			}
			j++;
		}
		i++;
	}
	if (nbhash != 4 || nbconnect < 6)
		return (-1);
	return (1);
}

int		check_file(int ac, char **av)
{
	int		fd;

	if (ac != 2)
	{
		write(1, "usage: ./fillit source_file\n",
				ft_strlen("usage: ./fillit source_file\n"));
		return (-1);
	}
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (-1);
	else
		return (fd);
}
	
