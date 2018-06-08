/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 22:27:05 by lchancri          #+#    #+#             */
/*   Updated: 2018/06/01 21:15:02 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

static int	push_a_if_label(t_file *file, char *str, int a)
{
	int		b;
	t_label	*label;

	label = file->label;
	while (label)
	{
		if (label->a == a)
		{
			b = ft_strclen(&str[a], LABEL_CHAR) + 1;
			while (str[a + b] != '\0' && str[a + b] != '\n'
					&& (str[a + b] == 32 || str[a + b] == 9))
				b++;
			return (b);
		}
		label = label->next;
	}
	return (0);
}

static int	errror(char *str, int a)
{
	write(1, "Error : instruction doesn't exist\n", 34);
	print_line_col(str, a);
	return (-1);
}

int			check_cmd(t_file *file, char *str, int a)
{
	int		b;
	int		check;
	t_file	*tmp;
	t_label	*label;

	b = 0;
	if (str[a] == '.')
		return (0);
	tmp = file;
	label = file->label;
	a = a + push_a_if_label(file, str, a);
	while ((str[a + b] == 32 || str[a + b] == 9) && str[a + b] != '\n'
			&& str[a + b] != '\0')
		b++;
	if (str[a + b] == '\n')
		return (0);
	if ((check = check_which_cmd(str, a)) > 0
			&& check_validity(str, a, check, file) == 1)
		return (check);
	else if (check == 0)
		return (errror(str, a));
	return (-1);
}
