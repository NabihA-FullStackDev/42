/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:04:41 by naali             #+#    #+#             */
/*   Updated: 2018/11/16 01:28:04 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

void		ft_memdel(void **ap)
{
	if (ap != NULL)
	{
		if (*ap != NULL)
			free(*ap);
		*ap = NULL;
	}
}
