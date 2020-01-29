/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 11:58:20 by gicho             #+#    #+#             */
/*   Updated: 2020/01/29 12:06:59 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

void	ft_sort(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (i++ < argc)
	{
		j = 1;
		while (++j < argc)
		{
			if (ft_strcmp(argv[j - 1], argv[j]) < 0)
			{
				tmp = argv[j - 1];
				argv[j - 1] = argv[j];
				argv[j] = tmp;
			}
		}
	}
}

int		main(int argc, char *argv[])
{
	ft_sort(argc, argv);
	while (--argc)
	{
		while (*argv[argc])
			write(1, argv[argc]++, 1);
		write(1, "\n", 1);
	}
	return (0);
}
