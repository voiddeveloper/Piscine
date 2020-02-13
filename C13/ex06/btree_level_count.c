/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:45:40 by gicho             #+#    #+#             */
/*   Updated: 2020/02/13 12:47:44 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int l;
	int r;

	if (!root)
		return (0);
	l = btree_level_count(root->left);
	r = btree_level_count(root->right);
	if (l < r)
		return (r + 1);
	else
		return (l + 1);
}
