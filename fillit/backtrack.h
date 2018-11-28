/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:50:19 by jucapik           #+#    #+#             */
/*   Updated: 2018/11/26 15:00:53 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKTRACK_H
# define BACKTRACK_H

# include "s_dbs.h"
# define LIMTAB 25

int		backtrack(int size, t_dbs *tetris, char tab[LIMTAB][LIMTAB]);

#endif
