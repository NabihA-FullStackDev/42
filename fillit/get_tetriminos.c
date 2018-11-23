/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetriminos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:52:28 by naali             #+#    #+#             */
/*   Updated: 2018/11/23 15:59:08 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/includes/get_next_line.h"
#include "error.h"
#include "get_tetriminos.h"

static void			copytabtolst(char tab[4][5], t_dbs **tetris, int id)
{
	t_dbs		*tmp;

	tmp = dbs_new(('A' + id), tab);
	dbs_pushback(tetris, tmp);
}

static int			checktab(char tab[4][5], t_dbs **tetris)
{
	if (errorform(tab) == -1)
	{
		if (tetris != NULL)
			dbs_del(tetris);
		return (-1);
	}
	return (0);
}

static int			copylinetotab(char **line, char tab[4][5])
{
	int			i;

	i = 0;
	if (*line != NULL && errorlines(*line) == -1)
	{
		free(*line);
		return (-1);
	}
	if (*line != NULL && **line != '\0')
	{
		while (*line[i] != '\0')
		{
			*tab[i] = *line[i];
			i = i + 1;
		}
		free(line);
	}
	return (0);
}

int		get_tetriminos(int fd, t_dbs **tetris)
{
	int		i;
	int		nb_tetri;
	char	*line;
	char	tab[4][5];

	nb_tetri = 0;
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (i < 4 && copylinetotab(&line, &tab[i]) == -1)
			return (-1);
		if (i < 4)
			i = i + 1;
		else
		{
			i = 0;
			if (checktab(tab, tetris) == -1)
				return (-1);
			copytabtolst(tab, tetris, nb_tetri);
			nb_tetri = nb_tetri + 1;
		}
	}
	return (nb_tetri);
}
