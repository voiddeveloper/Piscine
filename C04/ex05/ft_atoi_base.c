/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 16:54:36 by gicho             #+#    #+#             */
/*   Updated: 2020/01/27 16:57:28 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char		*g_base;
long long	g_len;

int		ft_get_len(void)
{
	int chk[256];
	int i;

	i = 0;
	while (i < 256)
		chk[i++] = 0;
	g_len = 0;
	while (g_base[g_len])
	{
		if (chk[g_base[g_len]] ||
				g_base[g_len] == '+' ||
				g_base[g_len] == '-')
			return (0);
		chk[g_base[g_len++]] = 1;
	}
	return (1);
}

int		ft_get_idx(char c)
{
	int i;

	i = 0;
	while (i < g_len)
	{
		if (c == g_base[i])
			return (i);
		++i;
	}
	return (-1);
}

long	get_number(char *str)
{
	long	ret;
	int		idx;

	ret = 0;
	while (*str)
	{
		idx = ft_get_idx(*str);
		if (idx == -1)
			break ;
		ret *= g_len;
		ret += idx;
		++str;
	}
	return (ret);
}

int		ft_atoi_base(char *str, char *base)
{
	int sign;

	sign = 1;
	g_base = base;
	if (!ft_get_len() || g_len == 0 || g_len == 1)
		return (0);
	while (*str)
	{
		if (*str == '-')
			sign *= -1;
		else if (ft_get_idx(*str) != -1)
			return ((get_number(str)) * sign);
		else if (*str != '+')
			sign = 1;
		++str;
	}
	return (0);
}
