/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:58:52 by gicho             #+#    #+#             */
/*   Updated: 2020/01/27 16:55:08 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_number(char c)
{
	return ('0' <= c && c <= '9');
}

long	get_number(char *str)
{
	int ret;

	ret = 0;
	while (*str && ft_is_number(*str))
	{
		ret *= 10;
		ret += (*str - '0');
		++str;
	}
	return (ret);
}

int		ft_atoi(char *str)
{
	int sign;

	sign = 1;
	while (*str)
	{
		if (*str == '-')
			sign *= -1;
		else if (ft_is_number(*str))
			return ((get_number(str)) * sign);
		else if (*str != '+')
			sign = 1;
		++str;
	}
	return (0);
}
