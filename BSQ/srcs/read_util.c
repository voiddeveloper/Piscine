/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:27:06 by gicho             #+#    #+#             */
/*   Updated: 2020/02/11 19:27:06 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*expand_size(char *src, int *size)
{
	char *ret;

	if (!(ret = (char*)malloc(*size << 1)))
		exit(0);
	ft_strncpy(ret, src, *size);
	*size <<= 1;
	free(src);
	return (ret);
}

int		ft_is_number(char c)
{
	return ('0' <= c && c <= '9');
}

int		ft_atoi(char *str)
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

int		ft_is_valid_map(char *line, t_map *map)
{
	while (*line)
	{
		if (*line != map->empty && *line != map->obstacle)
			return (0);
		++line;
	}
	return (1);
}
