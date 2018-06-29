/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 21:19:06 by lchancri          #+#    #+#             */
/*   Updated: 2018/06/28 17:11:04 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"
#include "../include/op.h"

void		print_line_col(char *str, int a)
{
	int		b;
	int		c;

	b = 0;
	c = 1;
	while (b < a)
	{
		if (str[b] == '\n')
			c++;
		b++;
	}
	write(1, "line  : ", 8);
	ft_putnbr(c);
	write(1, "\n", 1);
	c = 0;
	while (b - c > 0 && str[b - c] != '\n')
		c++;
	write(1, "col   : ", 8);
	ft_putnbr(c);
	write(1, "\n", 1);
}

char		*error_binary(void)
{
	write(1, "Error : binary file\n", 20);
	return (NULL);
}

int			error_name_comment(int check)
{
	if (check == 1)
		write(1, "Error : multiples names\n", 24);
	else if (check == 2)
		write(1, "Error : multiples comments\n", 27);
	return (-1);
}

int			error_lenght(int type)
{
	if (type == 1)
	{
		write(1, "Error : name is too long (max lenght : ", 39);
		ft_putnbr(PROG_NAME_LENGTH);
		write(1, ")\n", 2);
	}
	if (type == 2)
	{
		write(1, "Error : comment is too long (max lenght : ", 42);
		ft_putnbr(COMMENT_LENGTH);
		write(1, ")\n", 2);
	}
	return (-1);
}

int			error_cmd_before_name(char *str, int a)
{
	write(1, "Error : Instruction before name or comment\n", 43);
	print_line_col(str, a);
	return (-1);
}
