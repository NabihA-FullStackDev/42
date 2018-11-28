/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetriminos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:52:28 by naali             #+#    #+#             */
/*   Updated: 2018/11/28 13:13:07 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/includes/get_next_line.h"
#include "error.h"
#include "get_tetriminos.h"
#include "getpdir.h"

static t_dbs		**copytabtolst(char **tab, t_dbs **tetris, int id)
{
	t_dbs		*tmp;

	tmp = NULL;
	tmp = dbs_new(('A' + id));
	getpdir(tab, tmp);
	dbs_pushback(tetris, tmp);
	return (tetris);
}

static int			checktab(char **tab, t_dbs **tetris, int i)
{
	if (errorform(tab) == -1 || i == -1)
	{
		write(1, F_ERROR, F_ERSIZ);
		if (tetris != NULL)
			dbs_del(tetris);
		full_free_tab(tab);
		return (-1);
	}
	return (0);
}

static int			copylinetotab(char **line, char **tab)
{
	if (*line != NULL && errorlines(*line) == -1)
	{
		free(*line);
		write(1, F_ERROR, F_ERSIZ);
		return (-1);
	}
	if (*line != NULL && **line != '\0')
	{
		*tab = (char*)ft_memmove((void*)*tab, (void*)*line, sizeof(char) * 5);
		free(*line);
	}
	return (0);
}

static char			**init_tab45(void)
{
	int		i;
	char	**tab;

	i = 0;
	if ((tab = (char**)malloc(sizeof(char*) * 4)) == NULL)
	{
		write(1, F_ERROR, F_ERSIZ);
		return (NULL);
	}
	while (i < 4)
	{
		if ((tab[i] = (char*)malloc(sizeof(char) * 5)) == NULL)
		{
			write(1, F_ERROR, F_ERSIZ);
			full_free_tab(tab);
			return (NULL);
		}
		i = i + 1;
	}
	return (tab);
}

/*
** Recuperation des tetriminos a partir du fd donnes.
** Envoie les lignes aux focntions de verifications.
*/

int					get_tetriminos(int fd, t_dbs **tetris, char **tab)
{
	int		i;
	int		nb_tetri;
	char	*line;

	i = 0;
	nb_tetri = 0;
	if ((tab = init_tab45()) == NULL)
		return (-1);
	while (get_next_line(fd, &line) > 0)
	{
		if (i < 4 && copylinetotab(&line, &tab[i]) == -1 && *line != '\0')
			i = -1;
		else if (i < 4 && *line != '\0' && i != -1)
			i = i + 1;
		if (i == 4 || i == -1)
		{
			if (checktab(tab, tetris, i) == -1)
				return (-1);
			copytabtolst(tab, tetris, nb_tetri);
			nb_tetri = nb_tetri + 1;
			i = 0;
		}
	}
	full_free_tab(tab);
	return (nb_tetri);
}
