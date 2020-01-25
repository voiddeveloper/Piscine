/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:49:53 by gicho             #+#    #+#             */
/*   Updated: 2020/01/24 11:50:59 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_printable(char c)
{
	if (' ' <= c && c <= '~')
		return (1);
	return (0);
}

int	ft_str_is_printable(char *str)
{
	int i;

	i = 0;
	while (str[i])
		if (!is_printable(str[i++]))
			return (0);
	return (1);
}
