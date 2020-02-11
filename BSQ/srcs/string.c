/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:26:39 by gicho             #+#    #+#             */
/*   Updated: 2020/02/11 19:26:40 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_strncpy(char *dst, char *src, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		++i;
	}
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*(str++));
}
