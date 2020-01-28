/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:04:16 by gicho             #+#    #+#             */
/*   Updated: 2020/01/28 11:04:55 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*g_base;
int		g_len;

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
		if (chk[(int)g_base[g_len]] ||
			g_base[g_len] == '+' ||
			g_base[g_len] == '-' ||
			g_base[g_len] == ' ' ||
			('\t' <= g_base[g_len] && g_base[g_len] <= '\r'))
			return (0);
		chk[(int)g_base[g_len++]] = 1;
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

int		ft_atoi_base(char *str, char *base)
{
	int ret;
	int sign;
	int idx;

	g_base = base;
	if (!ft_get_len() || g_len == 0 || g_len == 1)
		return (0);
	ret = 0;
	sign = 1;
	while (('\t' <= *str && *str <= '\r') || *str == ' ')
		++str;
	while (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign *= -1;
	while (*str)
	{
		idx = ft_get_idx(*(str++));
		if (idx == -1)
			break ;
		ret *= g_len;
		ret += (sign * idx);
	}
	return (ret);
}
