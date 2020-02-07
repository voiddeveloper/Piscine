/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 06:10:01 by gicho             #+#    #+#             */
/*   Updated: 2020/02/08 08:08:12 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list *ret;

	ret = (t_list*)malloc(sizeof(t_list));
	ret->data = data;
	ret->next = 0;
	return (ret);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *ele;

	ele = ft_create_elem(data);
	if (*begin_list)
		ele->next = *begin_list;
	*begin_list = ele;
}
