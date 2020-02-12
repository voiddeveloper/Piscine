/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:26:13 by gicho             #+#    #+#             */
/*   Updated: 2020/02/12 23:27:23 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		parse_map_info(t_map *map, char *info)
{
	int ret;

	ret = parse_map_info_sub(map, info);
	if (!ret)
		free(map);
	free(info);
	return (ret);
}

char	*read_line(int fd)
{
	char	*line;
	char	c;
	int		idx;
	int		size;

	idx = 0;
	size = 2;
	if (!(line = (char*)malloc(size)))
		exit(0);
	while (read(fd, &c, 1))
	{
		if (c == '\n')
		{
			line[idx] = 0;
			break ;
		}
		if (idx + 1 == size)
			line = expand_size(line, &size);
		line[idx++] = c;
	}
	if (idx == 0)
		return (free_line(line));
	return (line);
}

t_map	*read_map(int fd, int stdin)
{
	char	*line;
	int		idx;
	t_map	*map;

	stdin = 0;
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		exit(0);
	if (!parse_map_info(map, read_line(fd)))
		return (0);
	if (!(map->arr = (char**)malloc(sizeof(char*) * map->y_len)))
		exit(0);
	idx = 0;
	map->x_len = 0;
	while ((line = read_line(fd)))
		if (!read_map_sub(&idx, map, line))
			return (0);
	if (idx != map->y_len)
	{
		free_map(map, idx);
		return (0);
	}
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
