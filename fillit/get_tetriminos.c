/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetriminos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:52:28 by naali             #+#    #+#             */
/*   Updated: 2018/11/26 15:52:38 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft/includes/get_next_line.h"
#include "error.h"
#include "get_tetriminos.h"
#include "getpdir.h"

static t_dbs		**copytabtolst(char **tab, t_dbs **tetris, int id)
{
	t_dbs		*tmp;

	tmp = dbs_new(('A' + id));
	getpdir(tab, tmp);
	dbs_pushback(tetris, tmp);
	return (tetris);
}

static int			checktab(char **tab, t_dbs **tetris)
{
	if (errorform(tab) == -1)
	{
		if (tetris != NULL)
		{
			/*Fonction de free TAB a faire*/
			dbs_del(tetris);
		}
		return (-1);
	}
	return (0);
}

static int			copylinetotab(char **line, char **tab)
{
	if (*line != NULL && errorlines(*line) == -1)
	{
		free(*line);
		return (-1);
	}
	if (*line != NULL && **line != '\0')
	{
		*tab = (char*)ft_memmove((void*)*tab, (void*)*line, sizeof(char) * 5);
		free(*line);
	}
	return (0);
}

static char			**init_tab45()
{
	int		i;
	char	**tab;

	i = 0;
	if ((tab = (char**)malloc(sizeof(char*) * 4)) == NULL)
		return (NULL);
	while (i < 4)
	{
		if ((tab[i] = (char*)malloc(sizeof(char) * 5)) == NULL)
			return (NULL);
		i = i + 1;
	}
	i = 0;
//	printf("tab[%d] = %p\n", i, tab[i]);
	return (tab);
}

int					get_tetriminos(int fd, t_dbs **tetris)
{
	int		i;
	int		nb_tetri;
	char	*line;
	char	**tab;

	i = 0;
	nb_tetri = 0;
	line = NULL;
	if ((tab = init_tab45()) == NULL)
		return (-1);
	while (get_next_line(fd, &line) > 0)
	{
		if (i < 4 && copylinetotab(&line, &tab[i]) == -1)
			return (-1);
		if (i < 4)
			i = i + 1;
		if (i == 4)
		{
			i = 0;
			if (checktab(tab, tetris) == -1)
				return (-1);
			copytabtolst(tab, tetris, nb_tetri);
			nb_tetri = nb_tetri + 1;
		}
		printf("%p\n", *tetris);
	}
	return (nb_tetri);
}
