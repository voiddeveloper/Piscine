/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:36:57 by gicho             #+#    #+#             */
/*   Updated: 2020/02/13 12:37:28 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *,
			void *))
{
	if (!*root)
	{
		*root = btree_create_node(item);
		return ;
	}
	if (cmpf(item, (*root)->item) < 0)
	{
		if (!(*root)->left)
		{
			(*root)->left = btree_create_node(item);
			return ;
		}
		btree_insert_data(&(*root)->left, item, cmpf);
	}
	else
	{
		if (!(*root)->right)
		{
			(*root)->right = btree_create_node(item);
			return ;
		}
		btree_insert_data(&(*root)->right, item, cmpf);
	}
}
