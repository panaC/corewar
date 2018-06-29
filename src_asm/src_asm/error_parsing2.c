/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parsing2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 13:39:58 by lchancri          #+#    #+#             */
/*   Updated: 2018/06/06 21:07:49 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

int			print_error_instruction(char *str, int type, int a)
{
	if (type == 1)
	{
		write(1, "Error : name not well formated ", 31);
		write(1, "(instruction on name line)\n", 27);
	}
	if (type == 2)
	{
		write(1, "Error : comment not well formated ", 34);
		write(1, "(instruction on comment line)\n", 30);
	}
	print_line_col(str, a);
	return (-1);
}

int			print_error(char *str, int type, int a)
{
	if (type == 1)
		write(1, "Error : name not well formated\n", 31);
	if (type == 2)
		write(1, "Error : comment not well formated\n", 34);
	print_line_col(str, a);
	return (-1);
}

int			error_label(char *str, int a)
{
	write(1, "Error : label not well formated\n", 32);
	print_line_col(str, a);
	return (-1);
}
