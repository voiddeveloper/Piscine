/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 22:33:32 by gicho             #+#    #+#             */
/*   Updated: 2020/02/10 22:33:33 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		parse_map_info(t_map *map, char *info)
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

char	*read_line(int fd)
{
	char	*line;
	char	c;
	int		idx;
	int		size;

	idx = 0;
	size = 2;
	line = (char*)malloc(size);
	while (read(fd, &c, 1))
	{
		if (c == '\n')
		{
			line[idx] = 0;
			break ;
		}
		if (idx + 1 == size)
		{
			line = expand_size(line, size);
			size <<= 1;
		}
		line[idx++] = c;
	}
	if (idx == 0)
		return (0);
	return (line);
}

t_map	*read_map(int fd, int stdin)
{
	char	*line;
	int		idx;
	t_map	*map;

	map = (t_map*)malloc(sizeof(t_map));
	if (!parse_map_info(map, read_line(fd)))
		return (0);
	map->arr = (char**)malloc(sizeof(char*) * map->y_len);
	idx = 0;
	map->x_len = 0;
	while ((line = read_line(fd)))
	{
		if (idx == map->y_len || !ft_is_valid_map(line, map))
			return (0);
		if (map->x_len == 0)
			map->x_len = ft_strlen(line);
		if (ft_strlen(line) != map->x_len)
			return (0);
		map->arr[idx++] = line;
		if (stdin && (idx == map->y_len))
			break ;
	}
	if (idx != map->y_len)
		return (0);
	return (map);
}

t_map	*read_stdin(void)
{
	return (read_map(0, 1));
}

t_map	*read_file(char *file)
{
	int fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	return (read_map(fd, 0));
}
