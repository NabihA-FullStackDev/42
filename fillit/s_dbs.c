/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_dbs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:34:19 by naali             #+#    #+#             */
/*   Updated: 2018/11/28 16:38:46 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "s_dbs.h"

t_dbs			*dbs_new(const char id)
{
	int			i;
	int			j;
	t_dbs		*node;

	i = 0;
	node = NULL;
	if ((node = (t_dbs*)malloc(sizeof(t_dbs))) == NULL)
		return (NULL);
	node->id = id;
	while (i < NBPDIR)
	{
		j = 0;
		while (j < COORDO)
		{
			node->pdir[i][j] = 0;
			j = j + 1;
		}
		i = i + 1;
	}
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void			dbs_pushback(t_dbs **head, t_dbs *node)
{
	t_dbs		*tmp;

	tmp = NULL;
	if (head != NULL && *head != NULL)
	{
		tmp = *head;
		while (*head != NULL && (*head)->next != NULL)
			*head = (*head)->next;
		(*head)->next = node;
		node->prev = *head;
		*head = tmp;
	}
	else
		*head = node;
}

void			dbs_del(t_dbs **head)
{
	t_dbs		*tmp;

	tmp = NULL;
	if (head != NULL)
	{
		while (*head != NULL)
		{
			tmp = (*head)->next;
			free(*head);
			*head = tmp;
		}
	}
}

int				dbs_size(const t_dbs *head)
{
	int			i;

	i = 0;
	while (head != NULL)
	{
		head = head->next;
		i = i + 1;
	}
	return (i);
}

t_dbs			*dbs_findid(t_dbs **head, char id)
{
	t_dbs		*node;

	node = NULL;
	if (head != NULL)
	{
		node = *head;
		while (node != NULL && node->id != id)
			node = node->next;
	}
	return (node);
}
