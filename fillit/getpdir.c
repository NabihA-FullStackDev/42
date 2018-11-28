/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpdir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:04:32 by jucapik           #+#    #+#             */
/*   Updated: 2018/11/28 11:51:05 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "s_dbs.h"

static void	modifpdir(char **tab, int pos[2], t_dbs *tetris, int *pdiriter)
{
	static int	xtmp = -1;
	static int	ytmp = -1;

	if (pos[0] == 0 && pos[1] == 0)
	{
		xtmp = -1;
		ytmp = -1;
	}
	if (tab[pos[0]][pos[1]] == '#' && xtmp != -1 && ytmp != -1)
	{
		tetris->pdir[*pdiriter][0] = pos[0] - ytmp;
		tetris->pdir[*pdiriter][1] = pos[1] - xtmp;
		xtmp = pos[1];
		ytmp = pos[0];
		(*pdiriter)++;
	}
	else if (tab[pos[0]][pos[1]] == '#' && xtmp == -1 && ytmp == -1)
	{
		xtmp = pos[1];
		ytmp = pos[0];
	}
}

int			getpdir(char **tab, t_dbs *tetris)
{
	int pdiriter;
	int	pos[2];

	pos[0] = 0;
	pdiriter = 0;
	while (pos[0] < 4)
	{
		pos[1] = 0;
		while (pos[1] < 4)
		{
			modifpdir(tab, pos, tetris, &pdiriter);
			pos[1]++;
		}
		pos[0]++;
	}
	return (1);
}
