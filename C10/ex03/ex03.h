/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 00:30:20 by gicho             #+#    #+#             */
/*   Updated: 2020/02/08 00:40:06 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX03_H
# define EX03_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <libgen.h>

extern char	*g_prog;
extern char	*g_buf;
extern char	*g_hex;
extern int	g_is_on_flag_c;
extern int	g_duplicated;
extern int	g_offset;
extern int	g_cnt;
extern char	*g_buf_prev;
extern int	g_last_lines;

int		is_printable(unsigned char c);
void	ft_putchar(unsigned char c);
void	ft_putstr(char *str);
void	print_input_offset(int n, int offset);
void	print_hexadecimal_bytes(char *str, int size);
void	print_characters(char *str, int len);
void	print_error_msg(char *file);
void	print_row(int offset, int i);
int		is_flag_c(char *str);
void	print(void);
int		ft_is_equal(char *a, char *b);


#endif
