/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 06:18:23 by gicho             #+#    #+#             */
/*   Updated: 2020/02/08 08:11:20 by gicho            ###   ########.fr       */
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

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *ele;
	t_list *ptr;

	ele = ft_create_elem(data);
	if (!*begin_list)
	{
		*begin_list = ele;
		return ;
	}
	ptr = *begin_list;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = ele;
}
