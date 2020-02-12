/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:28:04 by gicho             #+#    #+#             */
/*   Updated: 2020/02/12 23:27:33 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		is_printable(char c)
{
	return (' ' <= c && c <= '~');
}

int		is_valid_map_info(t_map *map)
{
	return (is_printable(map->full) &&
			is_printable(map->obstacle) &&
			is_printable(map->empty));
}

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
		map->obstacle == map->full ||
		!is_valid_map_info(map))
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
	{
		free(line);
		free_map(map, *idx);
		return (0);
	}
	len = ft_strlen(line);
	if (map->x_len == 0)
		map->x_len = len;
	if (len != map->x_len)
	{
		free(line);
		free_map(map, *idx);
		return (0);
	}
	map->arr[(*idx)++] = line;
	return (1);
}
