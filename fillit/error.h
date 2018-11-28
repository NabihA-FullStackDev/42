/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 10:33:07 by jucapik           #+#    #+#             */
/*   Updated: 2018/11/28 16:38:25 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define F_ERROR "error\n"
# define F_ERSIZ 6

# define F_USE "usage: ./fillit source_file\n"
# define F_USI 28

int		errorlines(char *line);
int		errorform(char **tab);
int		check_file(int ac, char **av);
void	full_free_tab(char **tab);

#endif
