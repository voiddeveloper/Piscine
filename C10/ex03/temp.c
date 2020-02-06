#include <unistd.h>
#include <stdlib.h>
char *g_hex;
char g_buf[16];

int		is_printable(unsigned char c)
{
	return (' ' <= c && c <= '~');
}

void	ft_putchar(unsigned char c)
{
	if (is_printable(c))
		write(1, &c, 1);
	else
		write(1, ".", 1);
}

void	ft_putstr(char *str)
{
	while(*str)
		ft_putchar(*(str++));
}


void	print_input_offset(int n, unsigned int offset)
{
	if (!offset)
	{
		while(n--)
			ft_putchar('0');
		return ;
	}
	print_input_offset(n - 1, offset >> 4);
	ft_putchar(g_hex[(offset & 15)]);
}

void	print_hexadecimal_bytes(char *str)
{
	int i;
	int tmp;
	
	ft_putchar(' ');
	i = 0;
	while (i < 8)
	{
		ft_putchar(' ');
		tmp = *str;
		ft_putchar(g_hex[(tmp / 16)]);
		ft_putchar(g_hex[(tmp % 16)]);
		++i;
	}
	while (i++ < 8)
		ft_putstr("   ");
}

void	print_characters(char *str)
{
	ft_putstr("  |");
	ft_putstr(str);
	ft_putstr("|\n");
}

void	init()
{
	g_hex = "0123456789abcdef";
}


void ft_hexdump()
{
	
	
}

int main(int argc, char *argv[])
{
	init();
	
	
	
	
}

