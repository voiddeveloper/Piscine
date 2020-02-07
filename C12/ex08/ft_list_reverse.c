/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 07:04:39 by gicho             #+#    #+#             */
/*   Updated: 2020/02/08 07:46:19 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list *tmp;
	t_list **l;
	t_list **r;

	l = begin_list;
	r = begin_list;
	while (*r)
		++r;
	--r;
	while (l < r)
	{
		tmp = *l;
		*l = *r;
		*r = tmp;
		++l;
		--r;
	}
}
