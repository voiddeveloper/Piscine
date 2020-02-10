/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:56:04 by jeonkim           #+#    #+#             */
/*   Updated: 2020/02/10 20:57:11 by jeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "struct.h"

int		is_full(t_square *sq, int y, int x);
void	print(t_map *map, t_square *square);
#endif
