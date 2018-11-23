/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_dbs.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:58:07 by naali             #+#    #+#             */
/*   Updated: 2018/11/23 15:55:08 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_DBS_H
# define S_DBS_H

# define NBPDIR 3
# define COORDO 2

typedef struct		s_dbs t_dbs;

struct				s_dbs
{
	char		id;
	int			pdir[NBPDIR][COORDO];
	t_dbs		*prev;
	t_dbs		*next;
};

t_dbs			*dbs_new(const char id, int pdir[NBPDIR][COORDO]);
void			dbs_pushback(t_dbs **head, t_dbs *node);
void			dbs_del(t_dbs **head);
int				dbs_size(const t_dbs *head);
t_dbs			*dbs_findid(t_dbs **head, char id);

#endif
