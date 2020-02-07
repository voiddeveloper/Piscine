#ifndef EX03_H
# define EX03_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <libgen.h>

extern char	*g_prog;
extern char	g_buf[17];
extern char	*g_hex;
extern int	g_is_on_flag_c;

int		is_printable(unsigned char c);
void	ft_putchar(unsigned char c);
void	ft_putstr(char *str);
void    print_input_offset(int n, int offset);
void    print_hexadecimal_bytes(char *str, int size);
void    print_characters(char *str, int len);
void    print_error_msg(char *file);
void    print_row(int offset, int i);
int		is_flag_c(char *str);

#endif
