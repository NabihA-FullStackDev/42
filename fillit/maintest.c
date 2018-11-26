/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 09:37:03 by jucapik           #+#    #+#             */
/*   Updated: 2018/11/26 16:30:26 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft/includes/libft.h"
#include "get_tetriminos.h"
#include "error.h"
#include "init.h"
#include "backtrack.h"

int     main(int ac, char **av)
{
	int     fd;
	t_dbs	*tetris;
	t_dbs	*tmp;
	int		check;
	int		ssquare;
	int		size;
	char	tab[LIMTAB][LIMTAB];

	tetris = NULL;
	if ((fd = check_file(ac, av)) == -1)
	{
		printf("%d\n", fd);
		return (-1);
	}
	ssquare = get_tetriminos(fd, &tetris);
	check = -1;
	size = init_size(ssquare * 4);
	init_tab(tab);
	tmp = tetris->next;
	printf("%d, %d\n", tetris->pdir[0][0], tetris->pdir[0][1]);
	printf("%d, %d\n", tetris->pdir[1][0], tetris->pdir[1][1]);
	printf("%d, %d\n", tetris->pdir[2][0], tetris->pdir[2][1]);
	printf("%d, %d\n", tmp->pdir[0][0], tmp->pdir[0][1]);
	printf("%d, %d\n", tmp->pdir[1][0], tmp->pdir[1][1]);
	printf("%d, %d\n", tmp->pdir[2][0], tmp->pdir[2][1]);
	while (check == -1)
	{
		write(1, "1\n", 2);
		if ((check = backtrack(size, tetris, &tab[0])) == -1)
			return (-1);
		size++;
	}
	write(1, "!\n", 2);
	print_tab(size, tab);
	//mettre les free
	return (0);
}
