/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:28:04 by gicho             #+#    #+#             */
/*   Updated: 2020/02/11 19:28:05 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		parse_map_info_sub(t_map *map, char *info)
{
	int len;

	if (!info || (len = ft_strlen(info)) < 4)
		return (0);
	map->full = info[len - 1];
	map->obstacle = info[len - 2];
	map->empty = info[len - 3];
	if (map->empty == map->obstacle ||
		map->empty == map->full ||
		map->obstacle == map->full)
		return (0);
	info[len - 3] = 0;
	if (!(map->y_len = ft_atoi(info)))
		return (0);
	return (1);
}

char	*free_line(char *line)
{
	free(line);
	return (0);
}

int		read_map_sub(int *idx, t_map *map, char *line)
{
	int len;

	if (*idx == map->y_len || !ft_is_valid_map(line, map))
		return (0);
	len = ft_strlen(line);
	if (map->x_len == 0)
		map->x_len = len;
	if (len != map->x_len)
		return (0);
	map->arr[(*idx)++] = line;
	return (1);
}
