/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:37:44 by jucapik           #+#    #+#             */
/*   Updated: 2018/11/28 13:09:39 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_VAR_H
# define INIT_VAR_H

# include "backtrack.h"

int		init_size(int surfacemin);
void	init_tab(char tab[LIMTAB][LIMTAB]);
void	print_tab(int size, char tab[LIMTAB][LIMTAB]);

#endif
