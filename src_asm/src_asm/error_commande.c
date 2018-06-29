/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_commande.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 20:41:30 by lchancri          #+#    #+#             */
/*   Updated: 2018/06/28 17:12:00 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

int			error_no_space_cmd(char *str, int a)
{
	write(1, "Error : no space after instruction\n", 35);
	print_line_col(str, a);
	return (-1);
}

int			error_parameter(char *str, int a, int parameter, int error)
{
	if (error > 0)
	{
		write(1, "Error : parameter ", 18);
		ft_putnbr(parameter);
		write(1, " is not", 7);
		if (error == 1)
			write(1, " direct", 7);
		if (error == 2)
			write(1, " indirect", 9);
		if (error == 3)
			write(1, " a register", 11);
		if (error == 4)
			write(1, " direct or indirect", 19);
		if (error == 5)
			write(1, " direct or a register", 21);
		if (error == 6)
			write(1, " indirect or a register", 23);
		if (error == 7)
			write(1, " direct, indirect or a register", 31);
		write(1, "\n", 1);
		print_line_col(str, a);
	}
	return (-1);
}

int			error_parameter_number(char *str, int a, int enough_or_not)
{
	if (enough_or_not == 1)
		write(1, "Error : not enough arguments\n", 29);
	if (enough_or_not == 2)
		write(1, "Error : too much arguments\n", 27);
	print_line_col(str, a);
	return (-1);
}
