/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:26:44 by gicho             #+#    #+#             */
/*   Updated: 2020/02/11 19:26:45 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int			ft_min(int a, int b, int c)
{
	int		min;

	min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	return (min);
}

int			cmp(int a, int b)
{
	if (a < b)
		return (1);
	return (0);
}
