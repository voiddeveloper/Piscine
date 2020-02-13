/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:31:11 by gicho             #+#    #+#             */
/*   Updated: 2020/02/13 12:31:37 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree *ret;

	ret = (t_btree*)malloc(sizeof(t_btree));
	ret->item = item;
	ret->left = 0;
	ret->right = 0;
	return (ret);
}
