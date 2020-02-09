/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 19:20:17 by gicho             #+#    #+#             */
/*   Updated: 2020/02/09 19:20:18 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		is_white_space(char c)
{
	return (c == ' ' || (9 <= c && c <= 13));
}

int		ft_is_number(char c)
{
	return ('0' <= c && c <= '9');
}

int		ft_is_valid_num(char *str)
{
	if (!str || (*str == '0' && *(str + 1)))
		return (0);
	while (*str)
	{
		if (!ft_is_number(*str))
			return (0);
		++str;
	}
	return (1);
}

int		is_valid_key_value(char *str)
{
	int cnt_colon;
	int cnt_key;
	int cnt_val;

	cnt_colon = 0;
	cnt_key = 0;
	cnt_val = 0;
	while (*str)
	{
		if (*str == ':')
			++cnt_colon;
		else if (!is_white_space(*str))
		{
			if (cnt_colon)
				++cnt_val;
			else
				++cnt_key;
		}
		++str;
	}
	return (cnt_colon == 1 && cnt_key > 0 && cnt_val > 0);
}
