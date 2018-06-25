/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_direct_indirect_reg.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:58:30 by lchancri          #+#    #+#             */
/*   Updated: 2018/06/13 18:22:28 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

int				is_int(char *str, int signe, char c)
{
	int			a;

	if (!str)
		return (0);
	a = signe;
	if (signe == 1)
		if (str[0] != '-' && !(str[0] >= 48 && str[0] <= 57))
			return (0);
	while (str[a] != '\0' && str[a] != c && str[a] != 32 && str[a] != 9
			&& str[a] != '\n')
	{
		if (!(str[a] >= 48 && str[a] <= 57))
			return (0);
		a++;
	}
	return (1);
}

static int		is_label(char *str, t_file *file, int a)
{
	char	*tmp;
	t_label	*tmp2;

	if (str[0] != LABEL_CHAR)
		return (0);
	while (str[a] != '\0' && check_if_good_char(str[a]) == 1)
		a++;
	if (!(tmp = (char*)malloc(sizeof(char) * a)))
		return (0);
	tmp = ft_strncpy(tmp, &str[1], a - 1);
	tmp2 = file->label;
	while (file->label)
	{
		if (file->label->name && ft_strcmp(tmp, file->label->name) == 0
				&& check_rest_param(&str[a]) == 1)
		{
			free(tmp);
			file->label = tmp2;
			return (1);
		}
		file->label = file->label->next;
	}
	file->label = tmp2;
	free(tmp);
	return (-1);
}

int				check_direct(char *str, int a, t_file *file)
{
	int		b;

	if (str[a] == DIRECT_CHAR)
	{
		if ((b = is_label(&str[a + 1], file, 1)) == 1)
			return (2);
		if (is_int(&str[a + 1], 1, SEPARATOR_CHAR) == 1)
			return (1);
		else if (b == -1)
		{
			write(1, "Error : label not found\n", 24);
			print_line_col(str, a);
			return (-110);
		}
		else if (b == 0)
		{
			write(1, "Error : invalid parameter\n", 26);
			print_line_col(str, a);
			return (-110);
		}
	}
	return (0);
}

int				check_indirect(char *str, int a, t_file *file)
{
	while (str[a] != '\0' && (str[a] == 32 || str[a] == 9))
		a++;
	if (is_label(&str[a], file, 1) == 1)
		return (2);
	if (is_int(&str[a], 1, SEPARATOR_CHAR) == 1)
		return (1);
	return (0);
}

int				check_register(char *str, int a)
{
	int		reg;

	reg = -1;
	if (str[a] != 'r')
		return (0);
	if (is_int(&str[a + 1], 0, SEPARATOR_CHAR) == 1)
		reg = ft_atoi(&str[a + 1]);
	if (reg >= 1 && reg <= REG_NUMBER)
		return (1);
	else
	{
		write(1, "Error : register value isn't included in REG_NUMBER\n", 52);
		print_line_col(str, a);
		return (-110);
	}
}
