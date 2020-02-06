/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 22:29:06 by gicho             #+#    #+#             */
/*   Updated: 2020/02/06 22:35:38 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex02.h"

char	*g_prog;
char	*g_buf;
int		g_fd;
int		g_buf_size;

void	display_file(int fd)
{
	long long	idx;
	int			tmp;

	if (g_buf_size == 0)
	{
		while (read(fd, g_buf, 1))
			if (errno)
				return ;
	}
	else
	{
		idx = 0;
		while (read(fd, &g_buf[(idx % g_buf_size)], 1))
		{
			if (errno)
				return ;
			++idx;
		}
		tmp = idx % g_buf_size;
		if (idx >= g_buf_size)
			write(1, g_buf + tmp, g_buf_size - tmp);
		write(1, g_buf, tmp);
	}
}

void	display(int argc, char *argv[])
{
	int i;
	int k;

	i = 2;
	k = 0;
	while (++i < argc)
	{
		errno = 0;
		if ((g_fd = open(argv[i], O_RDONLY)) == -1)
		{
			print_error_msg(argv[i]);
			continue ;
		}
		if (argc > 4)
		{
			if (k)
				ft_putstr("\n");
			ft_putstr("==> ");
			ft_putstr(argv[i]);
			ft_putstr(" <==\n");
		}
		k = 1;
		display_file(g_fd);
		close(g_fd);
	}
}

int		main(int argc, char *argv[])
{
	g_prog = argv[0];
	g_buf_size = ft_atoi(argv[2]);
	g_buf = (char*)malloc(g_buf_size);
	if (argc == 3)
		display_file(0);
	else
		display(argc, argv);
	free(g_buf);
	return (0);
}
