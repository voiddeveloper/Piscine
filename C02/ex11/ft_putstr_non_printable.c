/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:53:02 by gicho             #+#    #+#             */
/*   Updated: 2020/01/25 22:17:43 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_printable(char c)
{
	if (' ' <= c && c <= '~')
		return (1);
	return (0);
}

void	write_hex(char c)
{
	c = c + '0';
	if (c > '9')
		c = c + 39;
	write(1, &c, 1);
}

void	print_hex(char c)
{
	write(1, "/", 1);
	write_hex((int)c / 16);
	write_hex((int)c % 16);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!is_printable(str[i]))
			print_hex(str[i]);
		else
			write(1, &str[i], 1);
		++i;
	}
}
