/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 09:37:03 by jucapik           #+#    #+#             */
/*   Updated: 2018/11/25 17:27:37 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft/includes/libft.h"
#include "get_tetriminos.h"
#include "error.h"

int     main(int ac, char **av)
{
	int     fd;

	if ((fd = check_file(ac, av)) == -1)
		printf("%d\n", fd);
	else
		printf("%d\n", fd);
	return (0);
}
