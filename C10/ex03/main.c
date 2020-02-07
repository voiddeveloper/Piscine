#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>

char    *g_prog;
char    *g_hex;
char    g_buf[17];

int        is_printable(unsigned char c)
{
    return (' ' <= c && c <= '~');
}

void    ft_putchar(unsigned char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *str)
{
    while(*str)
        ft_putchar(*(str++));
}


void    print_input_offset(int n, int offset)
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

void    print_hexadecimal_bytes(char *str, int size)
{
    int i;
    int tmp;
    
    ft_putchar(' ');
    i = 0;
    while (i < size && i < 8)
    {
        ft_putchar(' ');
        tmp = str[i];
        ft_putchar(g_hex[(tmp / 16)]);
        ft_putchar(g_hex[(tmp % 16)]);
        ++i;
    }
    while (i++ < 8)
        ft_putstr("   ");
}

void    print_characters(char *str, int len)
{
    int i;
    
    ft_putstr("  |");
    i = 0;
    while (i < len)
    {
        if (is_printable(str[i]))
            ft_putchar(str[i]);
        else
            ft_putchar('.');
        ++i;
    }
    ft_putchar('|');
}

void    print_error_msg(char *file)
{
    ft_putstr(basename(g_prog));
    ft_putstr(": ");
    ft_putstr(file);
    ft_putstr(": ");
    ft_putstr(strerror(errno));
    ft_putchar('\n');
    errno = 0;
}

void    print_row(int offset, int i)
{
    print_input_offset(8, offset);
    print_hexadecimal_bytes(g_buf, 8 * (i / 8) + i);
    print_hexadecimal_bytes(g_buf + 8, i - 8);
    print_characters(g_buf, i);
    ft_putchar('\n');
}

void    hexdump_stdin()
{
    int offset;
    int i;

    offset = 0;
    i = 0;
    while (read(0, &g_buf[i], 1))
        if (++i == 16)
        {
            print_row(offset, i);
            offset += 16;
            i = 0;
        }
    if (i)
        print_row(offset, i);
    print_input_offset(8, offset + i);
    ft_putchar('\n');
}

void    hexdump_files(int argc, char *argv[])
{
    int offset;
    int i;
    int j;
    int fd;

    offset = 0;
    i = 1;
    j = 0;
    while (++i < argc)
    {
        if ((fd = open(argv[i], O_RDONLY)) == -1)
        {
            print_error_msg(argv[i]);
            continue;
        }
        while (read(fd, &g_buf[j], 1))
        {
            if (errno)
            {
                print_error_msg(argv[i]);
                break ;
            }
            if (++j == 16)
            {
                print_row(offset, j);
                offset += 16;
                j = 0;
            }
        }
    }
    if (j)
        print_row(offset, j);
    print_input_offset(8, offset + j);
    ft_putchar('\n');
}

int main(int argc, char *argv[])
{
    g_prog = argv[0];
    g_hex = "0123456789abcdef";
    g_buf[16] = 0;
    
    if (argc == 2)
    {
        hexdump_stdin();
    }
    else
    {
        hexdump_files(argc, argv);
    }
    return (0);
}

