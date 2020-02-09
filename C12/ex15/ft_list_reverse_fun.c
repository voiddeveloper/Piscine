/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:43:37 by gicho             #+#    #+#             */
/*   Updated: 2020/02/09 22:44:13 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*begin;
	t_list	*end;
	void	*tmp;

	end = 0;
	while (begin_list != end)
	{
		begin = begin_list;
		while (begin->next != end)
		{
			tmp = begin->data;
			begin->data = begin->next->data;
			begin->next->data = tmp;
			begin = begin->next;
		}
		end = begin;
	}
}
