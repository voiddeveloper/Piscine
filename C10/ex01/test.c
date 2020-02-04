
#include<unistd.h>
#include<fcntl.h>

void ft_putstr(char *str)
{
	while(*str)
		write(1, str++, 1);
}

#include<string.h>

extern int errno;

int main(int argc, char *argv[])
{
	char c;
	int sz;

	if (argc == 1)
		ft_putstr("File name missing.\n");
	else if (argc > 2)
		ft_putstr("Too many arguments.\n");
	else
	{
		int fd;

		fd = open(argv[1], O_RDONLY);
		if (fd == -1){
			ft_putstr("Cannot read file.\n");
			ft_putstr(strerror(errno));
		}
		
		else
		{
			read(fd, &c, 1);
			while (c)
			{
				write(1, &c, 1);
				read(fd, &c, 1);
			}
			close(fd);
		}
	}
	return 0;
}

