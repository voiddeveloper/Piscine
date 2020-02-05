/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 22:19:59 by gicho             #+#    #+#             */
/*   Updated: 2020/02/05 22:27:21 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>

#define BUF_SIZE 1

char *g_prog;

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	print_error_msg(char *file)
{
	ft_putstr(basename(g_prog));
	ft_putstr(": ");
	ft_putstr(file);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
}

void	display_file(int fd, char *file)
{
	long			size;
	unsigned char	buf[BUF_SIZE];

	while ((size = read(fd, buf, BUF_SIZE)))
	{
		if (errno)
		{
			print_error_msg(file);
			return ;
		}
		write(1, buf, size);
	}
}

int		main(int argc, char *argv[])
{
	int	fd;
	int	i;

	g_prog = argv[0];
	if (argc == 1)
		display_file(0, 0);
	else
	{
		i = 0;
		while (++i < argc)
		{
			if ((fd = open(argv[i], O_RDONLY)) == -1)
			{
				print_error_msg(argv[i]);
				continue ;
			}
			display_file(fd, argv[i]);
			close(fd);
		}
	}
	return (0);
}
