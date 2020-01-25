/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:07:28 by gicho             #+#    #+#             */
/*   Updated: 2020/01/25 15:07:32 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_row(char *data, int x)
{
	int i;

	i = 0;
	while (i < x)
	{
		if (i == 0)
			ft_putchar(data[0]);
		else if (i == x - 1)
			ft_putchar(data[1]);
		else
			ft_putchar(data[2]);
		++i;
	}
	ft_putchar('\n');
}

void	sol(char *data, int x, int y)
{
	int i;

	i = 0;
	while (i < y)
	{
		if (i == 0)
			print_row(data, x);
		else if (i == y - 1)
			print_row(&data[3], x);
		else
			print_row(&data[6], x);
		++i;
	}
}

void	rush(int x, int y)
{
	sol("/\\*\\/*** ", x, y);
}
