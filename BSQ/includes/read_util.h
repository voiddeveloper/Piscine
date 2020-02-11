/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_util.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:27:09 by gicho             #+#    #+#             */
/*   Updated: 2020/02/11 19:27:10 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_UTIL_H
# define READ_UTIL_H

# include "struct.h"

char	*expand_size(char *src, int *size);
int		ft_is_number(char c);
int		ft_atoi(char *str);
int		ft_is_valid_map(char *line, t_map *map);

#endif
