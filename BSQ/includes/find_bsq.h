/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bsq.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:26:02 by gicho             #+#    #+#             */
/*   Updated: 2020/02/11 19:26:05 by gicho            ###   ########.fr       */
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
