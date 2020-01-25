/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:55:26 by gicho             #+#    #+#             */
/*   Updated: 2020/01/25 20:02:41 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char *g_hex;
char g_str[16];

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_addr(long long addr, int cnt)
{
	if (!addr)
	{
		while (cnt++ < 16)
			ft_putchar('0');
		return ;
	}
	print_addr(addr >> 4, cnt + 1);
	ft_putchar(g_hex[addr % 16]);
}

void	process(char *ptr, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (i % 2 == 0)
			ft_putchar(' ');
		if (' ' <= ptr[i] && ptr[i] <= '~')
			g_str[i] = ptr[i];
		else
			g_str[i] = '.';
		ft_putchar(g_hex[(int)ptr[i] / 16]);
		ft_putchar(g_hex[(int)ptr[i] % 16]);
		++i;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int		i;
	int		len;
	char	*ptr;

	g_hex = "0123456789abcdef";
	i = 0;
	while (size)
	{
		if (size / 16)
			len = 16;
		else
			len = size;
		ptr = (char*)addr + i;
		print_addr((long long)ptr, 0);
		ft_putchar(':');
		process(ptr, len);
		ft_putchar(' ');
		if (len < 16)
			write(1, "    ", 4);
		write(1, g_str, len);
		ft_putchar('\n');
		size -= len;
		i += 16;
	}
	return (addr);
}
