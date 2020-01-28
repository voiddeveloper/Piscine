/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jushin <jushin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:07:28 by gicho             #+#    #+#             */
/*   Updated: 2020/01/25 17:18:28 by jushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_col(char *data, int x)
{
	int col;

	col = 0;
	while (col < x)
	{
		if (col == 0)
			ft_putchar(data[0]);
		else if (col == x - 1)
			ft_putchar(data[1]);
		else
			ft_putchar(data[2]);
		++col;
	}
	ft_putchar('\n');
}

void	print_row(char *data, int x, int y)
{
	int row;

	row = 0;
	while (row < y)
	{
		if (row == 0)
			print_col(data, x);
		else if (row == y - 1)
			print_col(&data[3], x);
		else
			print_col(&data[6], x);
		++row;
	}
}

void	rush(int x, int y)
{
	print_row("/\\*\\/*** ", x, y);
}
