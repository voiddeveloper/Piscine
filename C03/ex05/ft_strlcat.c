/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 10:52:16 by gicho             #+#    #+#             */
/*   Updated: 2020/01/26 10:53:02 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (*dest)
	{
		++i;
		++dest;
	}
	while (i + 1 < size)
	{
		*dest = *src;
		++dest;
		++src;
		++i;
	}
	*dest = 0;
	while (*src)
	{
		++i;
		++src;
	}
	return (i);
}
