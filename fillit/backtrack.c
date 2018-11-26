/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 11:14:53 by jucapik           #+#    #+#             */
/*   Updated: 2018/11/26 19:08:24 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//A AJOUTER:
// header dbs

//verifie si on peut mettre en position [x, y] (commence toujours a [0, 0])
//si oui:
//	mettre la piece
//	si c'est la derniere piece:
//		renvoyer 1, c'est la solution
//	si non:
//		et rappeler la fonction avec la piece suivante
//		si la fonction return -1, essayer la position suivante
//		si renvois 1, c'est la solution donc renvoyer 1
//si non:
//	essayer a la place suivant
//si on arrive a la fin sans avoir pu placer la piece, return -1 et si
//c'est la premiere piece on met tab a NULL 
//pdir[3][2] -> pdir => {[y, x], [y, x], [y, x]}

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "s_dbs.h"
#include "backtrack.h"
#include "init.h"
#include "libft/includes/libft.h"

static void	ecrisforme(int pos[2], t_dbs *tetris, char tab[LIMTAB][LIMTAB])
{
	int count;
	int tmppos[2];

	tmppos[0] = pos[0];
	tmppos[1] = pos[1];
	tab[tmppos[0]][tmppos[1]] = tetris->id;
	count = 0;
	while (count < 3)
	{
		tmppos[0] += tetris->pdir[count][0];
		tmppos[1] += tetris->pdir[count][1];
		tab[tmppos[0]][tmppos[1]] = tetris->id;
		++count;
	}
}

static void	effaceforme(int pos[2], t_dbs *tetris, char tab[LIMTAB][LIMTAB])
{
	int count;
	int tmppos[2];

	tmppos[0] = pos[0];
	tmppos[1] = pos[1];
	tab[tmppos[0]][tmppos[1]] = '.';
	count = 0;
	while (count < 3)
	{
		tmppos[0] += tetris->pdir[count][0];
		tmppos[1] += tetris->pdir[count][1];
		tab[tmppos[0]][tmppos[1]] = '.';
		++count;
	}
}


static int	checkpos(int size, t_dbs *tetris, char tab[LIMTAB][LIMTAB], int pos[2])
{
	int count;
	int tmppos[2];

	tmppos[0] = pos[0];
	tmppos[1] = pos[1];
	count = 0;
	if (tab[tmppos[0]][tmppos[1]] != '.')
		return (-1);
	while (count < 3)
	{
		tmppos[0] += tetris->pdir[count][0];
		tmppos[1] += tetris->pdir[count][1];
		if (tmppos[0] < 0 || tmppos[1] < 0 || tmppos[0] >= size ||
				tmppos[1] >= size || tab[tmppos[0]][tmppos[1]] != '.')
			return (-1);
		++count;
	}
	return (1);
}

int			backtrack(int size, t_dbs *tetris, char tab[LIMTAB][LIMTAB])
{
	int pos[2]; //[0] <=> y, [1] <=> x

	pos[0] = 0;
	while (pos[0] < size)
	{
		pos[1] = 0;
		while (pos[1] < size)
		{
			if (tetris == NULL)
				return (1);
			if (checkpos(size, tetris, tab, pos) == 1)
			{
				ecrisforme(pos, tetris, tab);
				if (backtrack(size, tetris->next, tab) == 1)
					return (1);
				effaceforme(pos, tetris, tab);
			}
			++pos[1];
		}
		++pos[0];
	}
	return (-1);
}
