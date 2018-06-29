/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 13:06:40 by lchancri          #+#    #+#             */
/*   Updated: 2018/06/28 18:39:39 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

static t_file	*error_name_com(t_file *file)
{
	if (file && !file->name)
		ft_putstr("Error : no name\n");
	else if (file && !file->comment)
		ft_putstr("Error : no comment\n");
	if (file)
		free_file(file);
	return (NULL);
}

static int		pass_name_comment(char *str, int a)
{
	if (str[a] == '\n')
		a++;
	a = a + ft_strclen(&str[a], '"') + 1;
	a = a + ft_strclen(&str[a], '"');
	return (a + ft_strclen(&str[a], '\n') - 1);
}

static t_file	*get_cmd(t_file *file, char *str, int a)
{
	int		check;
	int		check_name;

	check = 0;
	while (str[a] != '\0' && str[a + 1] != '\0' && check != -1)
	{
		check = 0;
		if ((check_name = check_if_name(str, a)) == 1)
			a = pass_name_comment(str, a);
		if (str[a] == '\n')
			check = check_if_cmd_label(str, a, file, 2);
		if (check > 0)
			file = update_file(file, str, a, check + 10);
		a = a + ft_strclen(&str[a + 1], '\n') + 1;
	}
	if (check == -1)
		return (free_file(file));
	return (file);
}

static t_file	*get_label(t_file *file, char *str, int a)
{
	int		check;
	int		check_name;

	check = 0;
	while (str[a] != '\0' && str[a + 1] != '\0' && check != -1)
	{
		check = 0;
		if ((check_name = check_if_name(str, a)) == 1)
			a = pass_name_comment(str, a);
		if (str[a] == '\n')
			check = check_if_cmd_label(str, a, file, 1);
		if (check == 3)
			file = update_file(file, str, a, check);
		a = a + ft_strclen(&str[a + 1], '\n') + 1;
	}
	if (check == -1)
		return (free_file(file));
	return (get_cmd(file, str, 0));
}

t_file			*check_file(char *str, int a, int check, t_file *file)
{
	int		name;
	int		comment;

	name = 0;
	comment = 0;
	while (str[a] != '\0' && str[a + 1] != '\0' && check != -1)
	{
		check = 0;
		if ((check = check_name_comment(str, a, name, comment)) == -1)
			return (free_file(file));
		if (check == 1 || check == 2)
			file = update_file(file, str, a, check);
		if (check == 1 && (a = pass_name_comment(str, a)))
			name = 1;
		if (check == 2 && (a = pass_name_comment(str, a)))
			comment = 1;
		a = a + ft_strclen(&str[a + 1], '\n') + 1;
	}
	if (check == -1 || name != 1 || comment != 1)
		return (error_name_com(file));
	return (get_label(file, str, 0));
}
