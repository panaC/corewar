/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 19:35:34 by lchancri          #+#    #+#             */
/*   Updated: 2018/06/06 21:09:13 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

static int		len_cmd(int arg_type, int b)
{
	if (arg_type == 12)
		return (1);
	if (arg_type == 11 || arg_type == 13)
		return (2);
	if (arg_type < 10 && arg_type > 0)
		return (2 + b);
	return (0);
}

int				size_cmd(t_cmd *cmd)
{
	int		a;
	int		b;

	a = 0;
	b = 2;
	if (cmd->op_code == 0)
		return (0);
	if (cmd->op_code == 9 || cmd->op_code == 10 || cmd->op_code == 11
			|| cmd->op_code == 12 || cmd->op_code == 14 || cmd->op_code == 15)
		b = 0;
	a = a + len_cmd(cmd->arg1_type, b);
	a = a + len_cmd(cmd->arg2_type, b);
	a = a + len_cmd(cmd->arg3_type, b);
	if (cmd->op_code == 1 || cmd->op_code == 9 || cmd->op_code == 12
			|| cmd->op_code == 15)
		return (a + 1);
	return (a + 2);
}

static t_cmd	*label_v(t_cmd *cmd, t_label *b_label, t_cmd *c, t_label *l)
{
	l->cmd = c;
	if (cmd->arg1_type == 1 || cmd->arg1_type == 11)
		cmd->arg1_value = label_place(b_label, cmd->arg1_value, cmd->a);
	if (cmd->arg2_type == 1 || cmd->arg2_type == 11)
		cmd->arg2_value = label_place(b_label, cmd->arg2_value, cmd->a);
	if (cmd->arg3_type == 1 || cmd->arg3_type == 11)
		cmd->arg3_value = label_place(b_label, cmd->arg3_value, cmd->a);
	return (cmd);
}

t_file			*prepare_file(t_file *f, int a, int size, int lenght_file)
{
	t_label	*label;
	t_cmd	*cmd;

	label = f->label;
	lenght_file = 0;
	while (f->label)
	{
		a = 0;
		size = 0;
		cmd = f->label->cmd;
		while (f->label->cmd)
		{
			f->label->cmd = label_v(f->label->cmd, label, cmd, f->label);
			a = size_cmd(f->label->cmd);
			size = size + a;
			lenght_file = lenght_file + a;
			f->label->cmd = f->label->cmd->next;
		}
		f->label->place = size;
		f->label->cmd = cmd;
		f->label = f->label->next;
	}
	f->label = label;
	f->length = lenght_file;
	return (f);
}
