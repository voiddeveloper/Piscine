/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:53:02 by gicho             #+#    #+#             */
/*   Updated: 2020/01/26 04:05:20 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_printable(unsigned char c)
{
	if (' ' <= c && c <= '~')
		return (1);
	return (0);
}

void	write_hex(unsigned char c)
{
	c = c + '0';
	if (c > '9')
		c = c + 39;
	write(1, &c, 1);
}

void	print_hex(unsigned char c)
{
	write(1, "\\", 1);
	write_hex((int)c / 16);
	write_hex((int)c % 16);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (!is_printable(*str))
			print_hex(*str);
		else
			write(1, str, 1);
		++str;
	}
}
