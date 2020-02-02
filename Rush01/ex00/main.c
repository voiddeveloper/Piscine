/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 19:13:40 by gicho             #+#    #+#             */
/*   Updated: 2020/02/01 21:28:39 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNISTD_H
# define UNISTD_H
# include <unistd.h>
#endif

int		is_valid_condition(char *cond);
int		rush(void);

int		main(int argc, char *argv[])
{
	if (argc != 2 || !(is_valid_condition(argv[1]) && rush()))
		write(1, "Error\n", 6);
	return (0);
}
