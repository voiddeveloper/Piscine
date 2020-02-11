/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bsq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:26:07 by gicho             #+#    #+#             */
/*   Updated: 2020/02/11 19:26:08 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void		change_square(t_square *square, int x, int y, int len)
{
	square->x = x;
	square->y = y;
	square->len = len;
}

int			check_square(int **arr, int i, int j)
{
	int	min;

	min = ft_min(arr[i - 1][j], arr[i - 1][j - 1], arr[i][j - 1]);
	arr[i][j] = min + 1;
	return (min + 1);
}

int			**make_arr(t_map *map)
{
	int		i;
	int		j;
	int		**buf;

	if (!(buf = (int**)malloc(sizeof(int *) * (map->y_len))))
		exit(0);
	i = -1;
	while (++i < map->y_len)
	{
		if (!(buf[i] = (int *)malloc(sizeof(int) * (map->x_len))))
			exit(0);
		j = -1;
		while (++j < map->x_len)
		{
			if (map->arr[i][j] == map->obstacle)
				buf[i][j] = 0;
			else
				buf[i][j] = 1;
		}
	}
	return (buf);
}

void		find_bsq_sub(int i, t_map *map, int **arr, t_square *square)
{
	int j;
	int	len;

	j = -1;
	while (++j < map->x_len)
	{
		if (i == 0 || j == 0)
			if (cmp(square->len, arr[i][j]))
				change_square(square, j, i, arr[i][j]);
		if (i == 0 || j == 0)
			continue;
		if (arr[i][j] == 1)
			if (cmp(square->len, len = check_square(arr, i, j)))
				change_square(square, j, i, len);
	}
}

t_square	*find_bsq(t_map *map)
{
	int			i;
	int			**arr;
	t_square	*square;

	if (!(square = (t_square*)malloc(sizeof(t_square))))
		exit(0);
	arr = make_arr(map);
	change_square(square, -1, -1, 0);
	i = -1;
	while (++i < map->y_len)
		find_bsq_sub(i, map, arr, square);
	i = 0;
	while (i < map->y_len)
		free(arr[i++]);
	free(arr);
	return (square);
}
