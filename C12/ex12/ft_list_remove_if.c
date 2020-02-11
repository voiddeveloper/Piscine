/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 08:18:05 by gicho             #+#    #+#             */
/*   Updated: 2020/02/11 23:11:22 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list *g_prev;
t_list *g_curr;
t_list *g_tmp;

void	free_curr(void (*free_fct)(void *))
{
	free_fct(g_curr->data);
	free(g_curr);
}

void	slide_next(void)
{
	g_prev = g_curr;
	g_curr = g_curr->next;
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
		void (*free_fct)(void *))
{
	g_curr = *begin_list;
	while (g_curr && (cmp(g_curr->data, data_ref) == 0))
	{
		*begin_list = g_curr->next;
		free_curr(free_fct);
		g_curr = *begin_list;
	}
	if (!g_curr || !g_curr->next)
		return ;
	slide_next();
	while (g_curr)
	{
		if (cmp(g_curr->data, data_ref) == 0)
		{
			g_tmp = g_curr->next;
			free_curr(free_fct);
			g_prev->next = g_tmp;
			g_curr = g_tmp;
		}
		else
			slide_next();
	}
}
