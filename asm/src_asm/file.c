/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 16:21:18 by lchancri          #+#    #+#             */
/*   Updated: 2018/06/04 23:41:21 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"
#include "../include/op.h"

t_file		*free_file(t_file *file)
{
	t_label		*tmp;
	t_cmd		*tmp2;

	if (file)
	{
		if (file->name)
			free(file->name);
		if (file->comment)
			free(file->comment);
		while (file->label)
		{
			tmp = file->label;
			while (file->label->cmd)
			{
				tmp2 = file->label->cmd;
				file->label->cmd = file->label->cmd->next;
				free(tmp2);
			}
			free(file->label->name);
			file->label = file->label->next;
			free(tmp);
		}
		free(file);
	}
	return (NULL);
}

t_label		*init_label(char *str, int a)
{
	t_label	*label;

	if (!(label = (t_label*)malloc(sizeof(t_label))))
		return (NULL);
	label->a = a;
	if (str && (size_t)a < ft_strlen(str))
		label->name = ft_strccpy(&str[a], LABEL_CHAR, 0);
	else
		label->name = NULL;
	label->cmd = NULL;
	label->next = NULL;
	return (label);
}

t_file		*init_file(void)
{
	t_file	*file;

	if (!(file = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	file->name = NULL;
	file->comment = NULL;
	file->label = init_label(NULL, 0);
	return (file);
}
