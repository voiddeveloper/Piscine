/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_biggest_square.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:41:01 by jeonkim           #+#    #+#             */
/*   Updated: 2020/02/10 20:45:54 by jeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND_BSQ_H
# define FIND_BSQ_H

# include "struct.h"

t_square	*find_bsq(t_map *map);
void		change_square(t_square *square, int x, int y, int len);
int			**make_arr(t_map *map);
int			check_square(int **arr, int i, int j);
#endif
