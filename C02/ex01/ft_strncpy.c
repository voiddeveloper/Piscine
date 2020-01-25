/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 23:03:43 by gicho             #+#    #+#             */
/*   Updated: 2020/01/25 22:05:52 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		++i;
	}
	if (src[i])
		return (dest + n);
	while (i < n)
		dest[i++] = 0;
	return (dest);
}
