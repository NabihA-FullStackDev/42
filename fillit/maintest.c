/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 09:37:03 by jucapik           #+#    #+#             */
/*   Updated: 2018/11/28 13:14:21 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "fillit.h"
#include "libft/includes/libft.h"
#include "get_tetriminos.h"
#include "error.h"
#include "init_var.h"
#include "backtrack.h"

int		main(int ac, char **av)
{
	t_fill	f;
	t_dbs	*tetris;
	char	tab[LIMTAB][LIMTAB];

	tetris = NULL;
	if ((f.fd = check_file(ac, av)) == -1)
		return (-1);
	if ((f.ssquare = get_tetriminos(f.fd, &tetris, f.tab)) == -1)
		return (-1);
	f.check = -1;
	f.size = init_size(f.ssquare * 4);
	init_tab(tab);
	while (f.check == -1 && f.size < LIMTAB)
	{
		if ((f.check = backtrack(f.size, tetris, &tab[0])) == 1)
			f.check = 1;
		++(f.size);
	}
	print_tab((f.size) - 1, tab);
	dbs_del(&tetris);
	return (0);
}
