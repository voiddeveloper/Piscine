#include "ex03.h"

char    *g_prog;
char    *g_hex;
char    g_buf[17];
int		g_offset;
int		g_cnt;
int		g_is_on_flag_c;

void    hexdump_stdin()
{
	g_offset = 0;
	g_cnt = 0;
	while (read(0, &g_buf[g_cnt], 1))
		if (++g_cnt == 16)
		{
			print_row(g_offset, g_cnt);
			g_offset += 16;
			g_cnt = 0;
		}
	if (g_cnt)
		print_row(g_offset, g_cnt);
	print_input_offset(7, g_offset + g_cnt);
	ft_putchar('\n');
}

void    hexdump_files(int argc, char *argv[])
{
	int i;
	int fd;
	int k;
	
	g_offset = 0;
	k = 0;
	i = g_is_on_flag_c;
	g_cnt = 0;
	while (++i < argc)
	{
		if ((fd = open(argv[i], O_RDONLY)) == -1)
		{
			print_error_msg(argv[i]);
			continue;
		}
		while (read(fd, &g_buf[g_cnt], 1))
		{
			if (errno)
			{
				print_error_msg(argv[i]);
				break ;
			}
			k = 1;
			if (++g_cnt == 16)
			{
				print_row(g_offset, g_cnt);
				g_offset += 16;
				g_cnt = 0;
			}
		}
	}
	if (k)
	{
		if (g_cnt)
			print_row(g_offset, g_cnt);
		print_input_offset(7, g_offset + g_cnt);
		ft_putchar('\n');
	}
}

int main(int argc, char *argv[])
{
	g_prog = argv[0];
	g_hex = "0123456789abcdef";
	g_buf[16] = 0;
	g_is_on_flag_c = 0;
	if (argc >= 2 && is_flag_c(argv[1]))
		g_is_on_flag_c = 1;
	if (argc == 1 + g_is_on_flag_c)
		hexdump_stdin();
	else
		hexdump_files(argc, argv);
	return (0);
}
