/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 19:23:25 by lchancri          #+#    #+#             */
/*   Updated: 2018/06/28 10:51:06 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

static t_file	*create_name_comment(t_file *file, char *str, int a, int check)
{
	if (check == 1)
		file->name = ft_strccpy(&str[a], '"', 0);
	if (check == 2)
		file->comment = ft_strccpy(&str[a], '"', 0);
	return (file);
}

static t_file	*create_cmd(t_file *file, char *str, int a, int check)
{
	t_label	*tmp;
	t_cmd	*tmp2;

	tmp = file->label;
	while (file && file->label && file->label->next
			&& file->label->next->a <= a)
		file->label = file->label->next;
	if (!file->label->cmd)
		file->label->cmd = init_cmd(str, a, check, tmp);
	else
	{
		tmp2 = file->label->cmd;
		while (file->label->cmd->next)
			file->label->cmd = file->label->cmd->next;
		file->label->cmd->next = init_cmd(str, a, check, tmp);
		file->label->cmd = tmp2;
	}
	file->label = tmp;
	return (file);
}

static t_file	*create_label(t_file *file, char *str, int a)
{
	t_label	*tmp;

	tmp = file->label;
	while (file->label && file->label->next)
		file->label = file->label->next;
	file->label->next = init_label(str, a);
	file->label = tmp;
	return (file);
}

static int		move_a(t_file *file, char *str, int a)
{
	t_label	*label;

	label = file->label;
	while (label)
	{
		if (label->a == a)
		{
			a = a + ft_strclen(&str[a], LABEL_CHAR) + 1;
			return (a);
		}
		label = label->next;
	}
	return (a);
}

t_file			*update_file(t_file *file, char *str, int a, int check)
{
	if (str[a] == '\n')
		a++;
	while (str[a] != '\n' && str[a] != '\0' && (str[a] == 9 || str[a] == 32))
		a++;
	if (check == 1 || check == 2)
	{
		a = a + ft_strclen(&str[a], '"') + 1;
		file = create_name_comment(file, str, a, check);
	}
	if (check == 3)
	{
		while ((str[a] == 32 || str[a] == 9) && str[a] != '\0')
			a++;
		file = create_label(file, str, a);
	}
	if (check > 10)
	{
		a = move_a(file, str, a);
		file = create_cmd(file, str, a, check - 10);
	}
	return (file);
}
