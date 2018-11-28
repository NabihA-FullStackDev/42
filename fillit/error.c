/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 08:21:50 by jucapik           #+#    #+#             */
/*   Updated: 2018/11/28 10:40:50 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft/includes/libft.h"
#include "error.h"

int			errorlines(char *line)
{
	static int	linenb = 1;
	int			i;

	if ((linenb % 5 != 0 && ft_strlen(line) != 4) ||
			(linenb % 5 == 0 && ft_strcmp(line, "") != 0))
		return (-1);
	++linenb;
	i = 0;
	while (i < 4 && line[i] != '\0')
	{
		if (line[i] != '#' && line[i] != '.')
			return (-1);
		i++;
	}
	return (1);
}

static int	getnbconnect(char **tab, int i, int j)
{
	int	nbconnect;

	nbconnect = 0;
	if (i + 1 < 4 && tab[i + 1][j] == '#')
		nbconnect++;
	if (i - 1 >= 0 && tab[i - 1][j] == '#')
		nbconnect++;
	if (j + 1 < 4 && tab[i][j + 1] == '#')
		nbconnect++;
	if (j - 1 >= 0 && tab[i][j - 1] == '#')
		nbconnect++;
	return (nbconnect);
}

int			errorform(char **tab)
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
		while (j < 5)
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
	
