/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 09:37:03 by jucapik           #+#    #+#             */
/*   Updated: 2018/11/26 19:10:09 by jucapik          ###   ########.fr       */
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
	while (check == -1 && size < LIMTAB)
	{
		if ((check = backtrack(size, tetris, &tab[0])) == 1)
			check = 1;
		++size;
	}
	if (size == LIMTAB)
		printf("NON\n");
	else
		print_tab(size - 1, tab);
	//mettre les free
	return (0);
}
