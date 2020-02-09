/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 21:47:41 by gicho             #+#    #+#             */
/*   Updated: 2020/02/09 21:58:52 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	int		swapped;
	t_list	*ptr;
	void	*tmp;

	if (!*begin_list)
		return ;
	ptr = *begin_list;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		while (!ptr->next)
		{
			if (cmp(ptr->data, ptr->next->data))
			{
				swapped = 1;
				tmp = ptr->data;
				ptr->data = ptr->next->data;
				ptr->next->data = tmp;
			}
		}
	}
}
