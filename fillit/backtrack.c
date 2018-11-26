/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 11:14:53 by jucapik           #+#    #+#             */
/*   Updated: 2018/11/26 15:32:27 by jucapik          ###   ########.fr       */
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

static void	ecrisforme(int pos[2], t_dbs *tetris, char tab[LIMTAB][LIMTAB])
{
	int count;

	tab[pos[0]][pos[1]] = '#';
	count = 0;
	while (count < 3)
	{
		pos[0] += tetris->pdir[count][0];
		pos[1] += tetris->pdir[count][1];
		tab[pos[0]][pos[1]] = '#';
		count++;
	}
}

static void	effaceforme(int pos[2], t_dbs *tetris, char tab[LIMTAB][LIMTAB])
{
	int count;

	tab[pos[0]][pos[1]] = '.';
	count = 0;
	while (count < 3)
	{
		pos[0] += tetris->pdir[count][0];
		pos[1] += tetris->pdir[count][1];
		tab[pos[0]][pos[1]] = '.';
		count++;
	}
}
	

static int	checkpos(int ssquare, t_dbs *tetris, char tab[LIMTAB][LIMTAB], int pos[2])
{
	int count;

	count = 0;
	while (count < 3)
	{
		pos[0] += tetris->pdir[count][0];
		pos[1] += tetris->pdir[count][1];
		if (pos[0] < 0 || pos[1] < 0 || pos[0] >= ssquare ||
				pos[1] >= ssquare || tab[pos[0]][pos[1]] != '#')
			return (-1);
		count++;
	}
	return (1);
}

int			backtrack(int size, t_dbs *tetris, char tab[LIMTAB][LIMTAB])
{
	int pos[2]; //[0] <=> y, [1] <=> x

	printf("size = %d\n", size);
	pos[0] = 0;
	while (pos[0] < size)
	{
		pos[1] = 0;
		while (pos[1] < size)
		{
			write(1, "2\n", 2);
			if (tab[pos[0]][pos[1]] == '#' &&
					checkpos(size, tetris, tab, pos) == 1)
			{
				write(1, "3\n", 2);
				ecrisforme(pos, tetris, tab);
				if (tetris->next == NULL ||
						backtrack(size, tetris->next, tab) == 1)
					return (1);
				effaceforme(pos, tetris, tab);
			}
			pos[1]++;
		}
		pos[0]++;
	}
	return (-1);
}
