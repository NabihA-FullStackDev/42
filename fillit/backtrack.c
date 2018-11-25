/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 11:14:53 by jucapik           #+#    #+#             */
/*   Updated: 2018/11/25 17:50:57 by jucapik          ###   ########.fr       */
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
#include "s_dbs.h"
#define LIMTAB 25

static void	ecrisforme(int pos[2], t_dbs *tetris, char *tab[LIMTAB][LIMTAB])
{
	int count;

	(*tab)[pos[0]][pos[1]] = '#';
	count = 0;
	while (count < 3)
	{
		pos[0] += tetris->pdir[count][0];
		pos[1] += tetris->pdir[count][1];
		(*tab)[pos[0]][pos[1]] = '#';
		count++;
	}
}

static void	effaceforme(int pos[2], t_dbs *tetris, char *tab[LIMTAB][LIMTAB])
{
	int count;

	(*tab)[pos[0]][pos[1]] = '.';
	count = 0;
	while (count < 3)
	{
		pos[0] += tetris->pdir[count][0];
		pos[1] += tetris->pdir[count][1];
		(*tab)[pos[0]][pos[1]] = '.';
		count++;
	}
}
	

static int	checkpos(int ssquare, t_dbs *tetris, char *tab[LIMTAB][LIMTAB], int pos[2])
{
	int count;

	count = 0;
	while (count < 3)
	{
		pos[0] += tetris->pdir[count][0];
		pos[1] += tetris->pdir[count][1];
		if (pos[0] < 0 || pos[1] < 0 || pos[0] >= ssquare ||
				pos[1] >= ssquare || (*tab)[pos[0]][pos[1]] != '#')
			return (-1);
		count++;
	}
	return (1);
}

int			backtrackunepiece(int ssquare, t_dbs *tetris, char *tab[LIMTAB][LIMTAB])
{
	int pos[2]; //[0] <=> y, [1] <=> x

	pos[0] = 0;
	while (pos[0] < ssquare)
	{
		pos[1] = 0;
		while (pos[1] < ssquare)
		{
			if ((*tab)[pos[0]][pos[1]] == '#' &&
					checkpos(ssquare, tetris, tab, pos) == 1)
			{
				ecrisforme(pos, tetris, tab);
				if (tetris->next == NULL ||
						backtrack(ssquare, tetris->next, tab) == 1)
					return (1);
				effaceforme(pos, tetris, tab);
			}
			pos[1]++;
		}
		pos[0]++;
	}
	return (-1);
}

int		backtrackchaquepiece(int ssquare, t_dbs *tetris, char *tab[LIMTAB][LIMTAB])
{
	int		pos[2]; //[0] <=> y, [1] <=> x
	t_dbs	*tmp;

	pos[0] = 0;
	while (pos[0] < ssquare)
	{
		pos[1] = 0;
		while (pos[1] < ssquare)
		{
			tmp = tetris;
			while (tmp != NULL)
			{
				ecrisforme(pos, tetris, tab);
				if ((*tab)[pos[0]][pos[1]] == '#' && backtrack(ssquare, tetris, tab) == 1)
					return (1);
				effaceforme(pos, tetris, tab);
				tmp = tmp->next;
			}
			pos[1]++;
		}
		pos[0]++;
	}
	return (-1);
}
