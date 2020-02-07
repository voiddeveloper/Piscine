/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 06:22:31 by gicho             #+#    #+#             */
/*   Updated: 2020/02/08 06:32:34 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*ret;
	t_list	*tmp;
	int		i;

	i = 0;
	ret = 0;
	while (i < size)
	{
		tmp = (t_list*)malloc(sizeof(t_list));
		tmp->data = strs[i];
		tmp->next = ret;
		ret = tmp;
		++i;
	}
	return (ret);
}
