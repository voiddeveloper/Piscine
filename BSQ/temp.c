#include "struct.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void ft_strncpy(char *dst, char *src, int size)
{
	int i;
	
	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		++i;
	}
}

char *expand_size(char *src, int size)
{
	char *ret;
	
	ret = (char*)malloc(size << 1);
	ft_strncpy(ret, src, size);
	free(src);
	return (ret);
}

char *read_line(int fd)
{
	char *line;
	char c;
	int idx;
	int size;
	
	idx = 0;
	size = 2;
	line = (char*)malloc(size);
	while (read(fd, &c, 1))
	{
		if (c == '\n')
		{
			line[idx] = 0;
			break;
		}
		if (idx + 1 == size)
		{
			line = expand_size(line, size);
			size <<= 1;
		}
		line[idx++] = c;
	}
	if (idx == 0)
		return 0;
	return (line);
}

int ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
		++i;
	return (i);
}

int ft_is_number(char c)
{
	return '0' <= c && c <= '9';
}

int ft_atoi(char *str)
{
	int num;
	
	if (*str == '0')
		return (0);
	num = 0;
	while (*str)
	{
		if (!ft_is_number(*str))
			return (0);
		num *= 10;
		num += (*str - '0');
		++str;
	}
	return (num);
}

int parse_map_info(t_map *map, char *info)
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

int ft_is_valid_map(char *line, t_map *map)
{
	while (*line)
	{
		if (*line != map->empty && *line != map->obstacle)
			return (0);
		++line;
	}
	return (1);
}

t_map *read_file(char *file)
{
	int fd;
	char *line;
	int idx;
	t_map *map;
	
	if((fd = open(file, O_RDONLY)) == -1)
		return (0);
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
		if (ft_strlen(line) != map->y_len)
			return (0);
		map->arr[idx++] = line;
	}
	return map;
}

#include<stdio.h>
int main(int argc, char *argv[])
{
	t_map *map;
	
	map = read_file(argv[1]);
	if (!map)
	{
		printf("map error\n");
		return 0;
	}
	for(int i=0;i<map->y_len;++i)
		printf("%s\n",map->arr[i]);
	
	return 0;
}

