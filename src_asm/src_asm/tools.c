/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 19:45:40 by lchancri          #+#    #+#             */
/*   Updated: 2018/06/06 21:16:14 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

char		*cpy_name(char *str)
{
	int		a;
	char	*tmp;

	a = 0;
	while (str[a] != '\0' && str[a] != 32 && str[a] != 9 && str[a] != '\n')
		a++;
	if (!(tmp = (char*)malloc(sizeof(char) * (a + 1))))
		return (NULL);
	a = 0;
	while (str[a] != '\0' && str[a] != 32 && str[a] != 9 && str[a] != '\n')
	{
		tmp[a] = str[a];
		a++;
	}
	tmp[a] = '\0';
	return (tmp);
}

static int	label_before(t_label *label, int cmd_place)
{
	int		size;
	t_cmd	*cmd;

	size = 0;
	cmd = label->cmd;
	while ((label && !cmd) || (cmd && cmd_place != cmd->a))
	{
		cmd = label->cmd;
		while (cmd && cmd_place != cmd->a)
		{
			size = size - size_cmd(cmd);
			cmd = cmd->next;
		}
		label = label->next;
	}
	return (size);
}

static int	label_after2(t_label *label, t_cmd *cmd, int which_label, int a)
{
	int		size;

	size = 0;
	while (label && a != which_label)
	{
		while (cmd)
		{
			size = size + size_cmd(cmd);
			cmd = cmd->next;
		}
		label = label->next;
		cmd = label->cmd;
		a++;
	}
	return (size);
}

static int	label_after(t_label *lab, int which_label, int cmd_place)
{
	int		a;
	t_cmd	*cmd;
	t_label	*label;

	a = 0;
	label = lab;
	cmd = lab->cmd;
	while ((label) && (!cmd || (cmd_place != cmd->a)))
	{
		cmd = label->cmd;
		while (cmd && cmd->a != cmd_place)
			cmd = cmd->next;
		if (!cmd || (cmd && cmd->a != cmd_place))
		{
			label = label->next;
			a++;
		}
	}
	return (label_after2(label, cmd, which_label, a));
}

int			label_place(t_label *label, int which_label, int cmd_place)
{
	int		a;
	int		size;
	t_label	*tmp;

	a = 0;
	size = 0;
	tmp = label;
	while (label && a != which_label)
	{
		label = label->next;
		a++;
	}
	if (label->a < cmd_place)
		size = label_before(label, cmd_place);
	else if (label->a > cmd_place)
		size = label_after(tmp, which_label, cmd_place);
	label = tmp;
	return (size);
}
