/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:08:03 by gicho             #+#    #+#             */
/*   Updated: 2020/02/09 20:33:54 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define ARGC_ERR_MSG "The count of arguments should be less than 3."
# define INPUT_NUM_ERR_MSG "The argument isn’t a valid positive integer."
# define DEFAULT_DICT_FILE "dictionary/default.dict"
# define MAX_LINE_WIDTH 1024
# define MAX_INPUT_NUM_LEN 1024
# define VALID_NUM_LEN 39

typedef struct		s_dict
{
	char			*key;
	char			*value;
	struct s_dict	*next;
}					t_dict;

extern t_dict *g_dict;
extern int g_dict_error;
extern int g_read_error;
extern int g_input_num_error;
extern int g_is_first;
extern int g_eof;

t_dict				*create_ele(char *key, char *val);
void				push_front(char *key, char *val);
void				build_dict(char *file);
void				insert_key_value(char *str);
char				*get_val(char *key);

char				*trim_left(char *str);
void				trim_right(char *str);
char				*trim_side(char *str);
char				*trim_allocated_str(char *str);

int					ft_strlen(char *str);
void				ft_strcpy(char *dst, char *begin, char *end);
int					ft_is_equal(char *a, char *b);

char				*read_line(int fd);
char				*read_num(void);

void				print(char *str);
void				ft_putchar(char c);
void				ft_putstr(char *str);
void				print_error_msg(char *str);

int					is_white_space(char c);
int					ft_is_number(char c);
int					ft_is_valid_num(char *str);
int					is_valid_key_value(char *str);

void				rush(int argc, char *argv[]);
void				convert_num(char *num);
char				*build_unit_str(int cnt);

#endif
