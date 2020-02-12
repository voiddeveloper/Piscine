/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:26:29 by gicho             #+#    #+#             */
/*   Updated: 2020/02/12 22:41:18 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	modify_map(t_map *map, t_square *square)
{
	int		i;
	int		j;
	char	full;

	full = map->full;
	i = square->y - square->len;
	while (++i <= square->y)
	{
		j = square->x - square->len;
		while (++j <= square->x)
			map->arr[i][j] = full;
	}
}

void	print(t_map *map, t_square *square)
{
	int		i;

	modify_map(map, square);
	i = -1;
	while (++i < map->y_len)
	{
		write(1, map->arr[i], map->x_len);
		ft_putchar('\n');
	}
}
