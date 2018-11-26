/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:37:44 by jucapik           #+#    #+#             */
/*   Updated: 2018/11/26 17:14:28 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_TAB_H
# define INIT_TAB_H

#include "backtrack.h"

int		init_size(int surfacemin);
void	init_tab(char tab[LIMTAB][LIMTAB]);
void	print_tab(int size, char tab[LIMTAB][LIMTAB]);

#endif
