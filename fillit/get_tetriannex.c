/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetriannex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:14:11 by naali             #+#    #+#             */
/*   Updated: 2018/11/28 16:21:58 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/includes/get_next_line.h"
#include "error.h"
#include "get_tetriminos.h"
#include "getpdir.h"

t_dbs		**copytabtolst(char **tab, t_dbs **tetris, int id)
{
	t_dbs		*tmp;

	tmp = NULL;
	tmp = dbs_new(('A' + id));
	getpdir(tab, tmp);
	dbs_pushback(tetris, tmp);
	return (tetris);
}

int			checktab(char **tab, t_dbs **tetris, int i)
{
	if (errorform(tab) == -1 || i == -1)
	{
		if (tetris != NULL)
			dbs_del(tetris);
		full_free_tab(tab);
		return (-1);
	}
	return (0);
}

int			copylinetotab(char **line, char **tab, int *empty)
{
	if (*line != NULL && errorlines(*line) == -1)
	{
		free(*line);
		return (-1);
	}
	if (*line != NULL && **line != '\0')
	{
		*empty = 0;
		*tab = (char*)ft_memmove((void*)*tab, (void*)*line, sizeof(char) * 5);
		free(*line);
	}
	else if (*line != NULL && **line == '\0')
	{
		free(*line);
		*empty = *empty + 1;
	}
	if (*empty >= 2)
	{
		free(*line);
		return (-1);
	}
	return (0);
}

char		**init_tab45(void)
{
	int		i;
	char	**tab;

	i = 0;
	if ((tab = (char**)malloc(sizeof(char*) * 4)) == NULL)
		return (NULL);
	while (i < 4)
	{
		if ((tab[i] = (char*)malloc(sizeof(char) * 5)) == NULL)
		{
			full_free_tab(tab);
			return (NULL);
		}
		i = i + 1;
	}
	return (tab);
}

int			checknlist(t_dbs **tetris, char **tab,
						int *nb_tetri, int *i)
{
	if (*i == 4 || *i == -1)
	{
		if (checktab(tab, tetris, *i) == -1)
			return (-1);
		copytabtolst(tab, tetris, *nb_tetri);
		*nb_tetri = *nb_tetri + 1;
		*i = 0;
	}
	return (0);
}
