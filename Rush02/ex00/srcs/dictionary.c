/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 19:07:42 by gicho             #+#    #+#             */
/*   Updated: 2020/02/09 21:33:29 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		g_fd;
char	*g_line;

t_dict	*create_ele(char *key, char *val)
{
	t_dict *ret;

	ret = (t_dict*)malloc(sizeof(t_dict));
	ret->key = key;
	ret->value = val;
	ret->next = 0;
	return (ret);
}

void	push_front(char *key, char *val)
{
	t_dict *tmp;

	if (!g_dict)
		g_dict = create_ele(key, val);
	else
	{
		tmp = g_dict;
		g_dict = create_ele(key, val);
		g_dict->next = tmp;
	}
}

void	insert_key_value(char *str)
{
	char *key;
	char *val;
	char *ptr;
	char *tmp;

	tmp = str;
	key = str;
	ptr = str;
	while (*ptr != ':')
		++ptr;
	key = (char*)malloc(ptr - key + 1);
	ft_strcpy(key, str, ptr - 1);
	key = trim_allocated_str(key);
	val = ++ptr;
	str = val;
	while (*ptr)
		++ptr;
	val = (char*)malloc(ptr - val + 1);
	ft_strcpy(val, str, ptr - 1);
	val = trim_allocated_str(val);
	*tmp = 0;
	free(tmp);
	push_front(key, val);
}

/*
** make linked list of dictionary data for converting input number
*/

void	build_dict(char *file)
{
	if ((g_fd = open(file, O_RDONLY)) == -1)
	{
		print_error_msg("Cannot open dictionary file.");
		return ;
	}
	g_eof = 1;
	while ((g_line = read_line(g_fd)))
	{
		if (g_eof++)
			break ;
		if (!*g_line)
			continue ;
		if (!is_valid_key_value(g_line))
		{
			g_read_error = 1;
			break ;
		}
		insert_key_value(g_line);
	}
	if (g_read_error)
	{
		g_dict_error = 1;
		print_error_msg("Cannot read contents.");
	}
	close(g_fd);
}

char	*get_val(char *key)
{
	t_dict *tmp;

	tmp = g_dict;
	while (tmp)
	{
		if (ft_is_equal(tmp->key, key))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (0);
}
