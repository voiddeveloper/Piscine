#include <unistd.h>

int g_board[5][5];
int g_chk_row[5][5];
int g_chk_col[5][5];
int g_condition[16];
int *g_start_ptr[4];
int g_offset[4][2];

int		check(int *ptr, int offset, int con)
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
			if(!check(ptr, g_offset[i][0], g_condition[con++]))
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



int		fill_board(int r, int c)
{
	int val;

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
	{
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
}

int		is_valid_condition(char *cond)
{
	int cnt;

	cnt = 0;
	while (*cond)
	{
		while (*cond && (*cond == ' ' || (9 <= *cond && *cond <= 13)))
			++cond;
		if (*cond){
			if ('1' <= *cond && *cond <= '4')
			{
				if (cnt == 16)
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

void	init(void)
{
	int i;
	int j;

	i = 0;
	while (++i < 5)
	{
		j = 0;
		while (++j < 5)
		{
			g_chk_row[i][j] = 0;
			g_chk_row[i][j] = 0;
		}
	}
	g_start_ptr[0] = &g_board[1][1];
	g_start_ptr[1] = &g_board[4][1];
	g_start_ptr[2] = &g_board[1][1];
	g_start_ptr[3] = &g_board[1][4];
	g_offset[0][0] = 5;
	g_offset[0][1] = 1;
	g_offset[1][0] = -5;
	g_offset[1][1] = 1;
	g_offset[2][0] = 1;
	g_offset[2][1] = 5;
	g_offset[3][0] = -1;
	g_offset[3][1] = 5;
}

int		rush(void)
{
	init();
	return (fill_board(1, 1));
}

int		main(int argc, char *argv[])
{
	if (argc != 2 || !is_valid_condition(argv[1]) || !rush())
		write(1, "Error\n", 6);
	rush();
	return (0);
}

