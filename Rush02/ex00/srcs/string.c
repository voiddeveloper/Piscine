/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:59:31 by gicho             #+#    #+#             */
/*   Updated: 2020/02/09 18:59:36 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strcpy(char *dst, char *begin, char *end)
{
	while (begin <= end)
		*(dst++) = *(begin++);
	*dst = 0;
}

int		ft_strlen(char *str)
{
	int ret;

	ret = 0;
	while (str[ret])
		++ret;
	return (ret);
}

int		ft_is_equal(char *a, char *b)
{
	while (*a && *b && *a == *b)
	{
		++a;
		++b;
	}
	return (*a == *b);
}
