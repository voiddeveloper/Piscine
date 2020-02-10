/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 22:33:39 by gicho             #+#    #+#             */
/*   Updated: 2020/02/10 22:33:40 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

int		parse_map_info(t_map *map, char *info);
char	*read_line(int fd);
t_map	*read_file(char *file);
t_map	*read_stdin(void);
#endif
