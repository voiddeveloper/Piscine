/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 19:17:00 by gicho             #+#    #+#             */
/*   Updated: 2020/02/09 21:36:34 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

/*
** read line of the dictionary reference file and check if the pair of key and
** value is valid.
*/

char	*read_line(int fd)
{
	int		i;
	char	*ret;

	i = 0;
	ret = (char*)malloc(MAX_LINE_WIDTH + 1);
	while ((read(fd, &ret[i], 1)))
	{
		g_eof = 0;
		if (i == MAX_LINE_WIDTH)
		{
			free(ret);
			g_read_error = 1;
			print_error_msg("Maximum line width exceeded.");
			return (0);
		}
		if (ret[i] == '\n')
		{
			ret[i] = 0;
			break ;
		}
		++i;
	}
	return (ret);
}

/*
** read standard entry
*/

char	*read_num(void)
{
	int		i;
	char	*ret;

	i = 0;
	ret = (char*)malloc(MAX_INPUT_NUM_LEN + 1);
	while ((read(0, &ret[i], 1)))
	{
		if (i == MAX_INPUT_NUM_LEN)
		{
			free(ret);
			g_input_num_error = 1;
			print_error_msg("Maximum length of number exceeded.");
			return (0);
		}
		if (ret[i] == '\n')
		{
			ret[i] = 0;
			break ;
		}
		++i;
	}
	return (trim_allocated_str(ret));
}
