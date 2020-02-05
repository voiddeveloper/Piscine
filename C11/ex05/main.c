/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:46:56 by gicho             #+#    #+#             */
/*   Updated: 2020/02/05 17:54:58 by gicho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex05.h"

int		g_op_idx[50];
int		(*g_f[5])(int, int);
char	*g_err_msg[2];

void	init(void)
{
	g_op_idx['/'] = 0;
	g_op_idx['%'] = 1;
	g_op_idx['+'] = 2;
	g_op_idx['-'] = 3;
	g_op_idx['*'] = 4;
	g_f[0] = div;
	g_f[1] = mod;
	g_f[2] = sum;
	g_f[3] = sub;
	g_f[4] = mul;
	g_err_msg[0] = "Stop : division by zero";
	g_err_msg[1] = "Stop : modulo by zero";
}

int		is_valid_operator(char op)
{
	return (op == '+' || op == '-' || op == '*' || op == '/' || op == '%');
}

int		main(int argc, char *argv[])
{
	int		val1;
	int		val2;
	char	op;

	init();
	if (argc != 4)
		return (0);
	op = argv[2][0];
	if (argv[2][1] || !is_valid_operator(op))
	{
		ft_putstr("0\n");
		return (0);
	}
	val1 = ft_atoi(argv[1]);
	val2 = ft_atoi(argv[3]);
	if (val2 == 0 && (op == '/' || op == '%'))
		ft_putstr(g_err_msg[g_op_idx[(int)op]]);
	else
		ft_putnbr(g_f[g_op_idx[(int)op]](val1, val2));
	ft_putstr("\n");
	return (0);
}
