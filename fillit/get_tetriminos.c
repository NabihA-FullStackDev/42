/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetriminos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:52:28 by naali             #+#    #+#             */
/*   Updated: 2018/11/28 16:38:12 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/includes/get_next_line.h"
#include "get_tetriannex.h"
#include "error.h"
#include "get_tetriminos.h"
#include "getpdir.h"

/*
** Recuperation des tetriminos a partir du fd donnes.
** Envoie les lignes aux fonctions de verifications.
*/

int					get_tetriminos(int fd, t_dbs **tetris, char **tab)
{
	int		i;
	int		nb_tetri;
	char	*line;
	int		empty;

	i = 0;
	empty = 0;
	nb_tetri = 0;
	if ((tab = init_tab45()) == NULL)
		return (-1);
	while (get_next_line(fd, &line) > 0)
	{
		if (i < 4 && copylinetotab(&line, &tab[i], &empty) == -1)
			i = -1;
		else if (i < 4 && i != -1 && *line != '\0')
			i = i + 1;
		if (checknlist(tetris, tab, &nb_tetri, &i) == -1)
			return (-1);
	}
	full_free_tab(tab);
	return ((i == 0 && empty == 0) ? nb_tetri : -1);
}
