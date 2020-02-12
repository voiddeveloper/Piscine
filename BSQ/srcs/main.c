/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:27:19 by gicho             #+#    #+#             */
/*   Updated: 2020/02/12 23:30:20 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	bsq(char *file)
{
	t_map		*map;
	t_square	*square;

	if (file)
		map = read_file(file);
	else
		map = read_stdin();
	if (!map)
	{
		ft_putstr(ERR_MSG);
		return ;
	}
	square = find_bsq(map);
	if (!square->len)
		ft_putstr(ERR_MSG);
	else
		print(map, square);
	free_map(map, map->y_len);
	free(square);
}

int		main(int argc, char *argv[])
{
	int i;

	if (argc == 1)
		bsq(0);
	else
	{
		i = 0;
		while (++i < argc)
			bsq(argv[i]);
	}
	return (0);
}
