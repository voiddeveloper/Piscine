/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:26:25 by gicho             #+#    #+#             */
/*   Updated: 2020/02/11 19:26:26 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "struct.h"

int		is_full(t_square *sq, int y, int x);
void	print(t_map *map, t_square *square);
#endif
