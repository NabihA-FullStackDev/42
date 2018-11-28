/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetriannex.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:16:15 by naali             #+#    #+#             */
/*   Updated: 2018/11/28 16:38:15 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_TETRIANNEX_H
# define GET_TETRIANNEX_H

# include "s_dbs.h"

t_dbs		**copytabtolst(char **tab, t_dbs **tetris, int id);
int			checktab(char **tab, t_dbs **tetris, int i);
int			copylinetotab(char **line, char **tab, int *empty);
char		**init_tab45(void);
int			checknlist(t_dbs **tetris, char **tab,
						int *nb_tetri, int *i);

#endif
