/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:26:29 by gicho             #+#    #+#             */
/*   Updated: 2020/02/11 19:26:30 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "bsq.h"

int		is_full(t_square *sq, int y, int x)
{
	if (sq->x >= x && sq->x - sq->len < x && sq->y >= y && sq->y - sq->len < y)
		return (1);
	return (0);
}

void	print(t_map *map, t_square *square)
{
	int		i;
	int		j;

	i = -1;
	while (++i < map->y_len)
	{
		j = -1;
		while (++j < map->x_len)
		{
			if (map->arr[i][j] == map->empty && is_full(square, i, j))
				ft_putchar(map->full);
			else if (map->arr[i][j] == map->empty)
				ft_putchar(map->empty);
			else
				ft_putchar(map->obstacle);
		}
		ft_putchar('\n');
	}
}
