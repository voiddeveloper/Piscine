/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 19:15:30 by gicho             #+#    #+#             */
/*   Updated: 2020/02/01 19:39:52 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int g_board[5][5];
extern int g_chk_row[5][5];
extern int g_chk_col[5][5];
extern int g_condition[16];
extern int *g_start_ptr[4];
extern int g_offset[4][2];

int		init(void);
int		is_valid_board(void);
int		fill_board(int r, int c);
void	ft_putchar(char c);

void	print_board(void)
{
	int r;
	int c;

	r = 0;
	while (++r < 5)
	{
		c = 0;
		while (++c < 4)
		{
			ft_putchar('0' + g_board[r][c]);
			ft_putchar(' ');
		}
		ft_putchar('0' + g_board[r][c]);
		ft_putchar('\n');
	}
}

int		sub_fill_board(int r, int c)
{
	int val;

	val = 0;
	while (++val < 5)
	{
		if (g_chk_row[r][val] || g_chk_col[c][val])
			continue ;
		g_chk_row[r][val] = 1;
		g_chk_col[c][val] = 1;
		g_board[r][c] = val;
		if (fill_board(r, c + 1))
			return (1);
		g_chk_row[r][val] = 0;
		g_chk_col[c][val] = 0;
	}
	return (0);
}

int		fill_board(int r, int c)
{
	if (r == 5)
	{
		if (is_valid_board())
		{
			print_board();
			return (1);
		}
		return (0);
	}
	if (c == 5)
		return (fill_board(r + 1, 1));
	else
		return (sub_fill_board(r, c));
}

int		rush(void)
{
	init();
	return (fill_board(1, 1));
}
