/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:33:27 by gicho             #+#    #+#             */
/*   Updated: 2020/02/12 17:09:08 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list *g_head;
t_list *g_l;
t_list *g_r;
t_list *g_tmp;

void	init(t_list *begin_list1, t_list *begin_list2, int (*cmp)())
{
	if (cmp(begin_list1->data, begin_list2->data) > 0)
	{
		g_l = begin_list1;
		g_r = begin_list2->next;
		g_head = begin_list2;
	}
	else
	{
		g_l = begin_list1->next;
		g_r = begin_list2;
		g_head = begin_list1;
	}
	g_tmp = g_head;
}

int		is_null(t_list **begin_list1, t_list *begin_list2)
{
	if (!begin_list2)
		return (1);
	if (!*begin_list1)
	{
		*begin_list1 = begin_list2;
		return (1);
	}
	return (0);
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)())
{
	if (is_null(begin_list1, begin_list2))
		return ;
	init(*begin_list1, begin_list2, cmp);
	*begin_list1 = g_head;
	while (g_l && g_r)
	{
		if (cmp(g_l->data, g_r->data) > 0)
		{
			g_tmp->next = g_r;
			g_r = g_r->next;
		}
		else
		{
			g_tmp->next = g_l;
			g_l = g_l->next;
		}
		g_tmp = g_tmp->next;
	}
	if (g_l)
		g_tmp->next = g_l;
	if (g_r)
		g_tmp->next = g_r;
}
