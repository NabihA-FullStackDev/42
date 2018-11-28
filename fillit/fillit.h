/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:49:12 by naali             #+#    #+#             */
/*   Updated: 2018/11/28 12:57:06 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct	s_fill
{
	int		fd;
	int		check;
	int		ssquare;
	int		size;
	char	**tab;
}				t_fill;

#endif
