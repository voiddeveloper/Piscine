/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 19:26:21 by gicho             #+#    #+#             */
/*   Updated: 2020/02/02 15:29:30 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNISTD_H
# define UNISTD_H
# include <unistd.h>
#endif

/*
** The comments of below global variables are on rush.c file.
*/
extern int g_board[5][5];
int g_chk_row[5][5];
int g_chk_col[5][5];
int g_condition[16];
int *g_start_ptr[4];
int g_offset[4][2];

int		is_valid_board_sub(int *ptr, int offset, int con)
{
	int i;
	int cnt;
	int max_val;

	i = 0;
	cnt = 0;
	max_val = 0;
	while (++i < 5)
	{
		if (*ptr > max_val)
		{
			max_val = *ptr;
			++cnt;
		}
		ptr += offset;
	}
	return (cnt == con);
}

int		is_valid_board(void)
{
	int con;
	int i;
	int j;
	int *ptr;

	con = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		ptr = g_start_ptr[i];
		while (j < 4)
		{
			if (!is_valid_board_sub(ptr, g_offset[i][0], g_condition[con++]))
				return (0);
			ptr += g_offset[i][1];
			++j;
		}
		++i;
	}
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		is_white_space(char c)
{
	return (c == ' ' || (9 <= c && c <= 13));
}

/*
** int is_valid_condition(char *cond)
**
** This function check if the condition values seperated by white space are
** valid.
*/

int		is_valid_condition(char *cond)
{
	int cnt;

	cnt = 0;
	while (*cond)
	{
		while (*cond && is_white_space(*cond))
			++cond;
		if (*cond)
		{
			if ('1' <= *cond && *cond <= '4')
			{
				if (cnt == 16 || (*(cond + 1) && !is_white_space(*(cond + 1))))
					return (0);
				g_condition[cnt++] = *cond - '0';
			}
			else
				return (0);
			++cond;
		}
	}
	return (cnt == 16);
}
