/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:48:27 by gicho             #+#    #+#             */
/*   Updated: 2020/02/13 17:10:20 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	pop_node(t_list **head)
{
	t_list *tmp;

	tmp = *head;
	*head = (*head)->next;
	free(tmp);
}

t_list	*create_ele(int level, t_btree *node)
{
	t_list *ret;

	ret = (t_list*)malloc(sizeof(t_list));
	ret->level = level;
	ret->next = 0;
	ret->node = node;
	return (ret);
}

void	push_node(t_list **head, t_btree *node, int level)
{
	t_list *tmp;

	if (!*head)
	{
		*head = create_ele(level, node);
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = create_ele(level, node);
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
			int current_level, int is_first_elem))
{
	t_list	*q;
	t_list	*tmp;
	int		level;

	q = 0;
	level = -1;
	if (root)
		push_node(&q, root, 0);
	while (q)
	{
		tmp = q;
		if (tmp->node->left)
			push_node(&q, tmp->node->left, tmp->level + 1);
		if (tmp->node->right)
			push_node(&q, tmp->node->right, tmp->level + 1);
		if (level != tmp->level)
			applyf(tmp->node->item, ++level, 1);
		else
			applyf(tmp->node->item, level, 0);
		pop_node(&q);
	}
}
