/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 19:30:00 by lchancri          #+#    #+#             */
/*   Updated: 2018/06/13 12:55:10 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

static void	write_int(int fd, int size, int octet)
{
	unsigned char	a;
	unsigned char	b;
	unsigned char	c;
	unsigned char	d;

	a = 0;
	b = 0;
	c = 0;
	d = 0;
	a |= size;
	size = size >> 8;
	b |= size;
	size = size >> 8;
	c |= size;
	size = size >> 8;
	d |= size;
	if (octet >= 4)
		write(fd, &d, 1);
	if (octet >= 3)
		write(fd, &c, 1);
	if (octet >= 2)
		write(fd, &b, 1);
	if (octet >= 1)
		write(fd, &a, 1);
}

static void	print_enc(t_cmd *cmd, int fd)
{
	unsigned char	type;

	type = 0x00;
	if (cmd->op_code == 1 || cmd->op_code == 9 || cmd->op_code == 12
			|| cmd->op_code == 15)
		return ;
	if (cmd->arg1_type != 0)
		type = create_type(type, 1, cmd->arg1_type);
	if (cmd->arg2_type != 0)
		type = create_type(type, 2, cmd->arg2_type);
	if (cmd->arg3_type != 0)
		type = create_type(type, 3, cmd->arg3_type);
	write(fd, &type, 1);
}

static int	oct(int type, int op_code)
{
	if (type == 12)
		return (1);
	if (type == 11 || type == 13)
		return (2);
	if (type < 10 && type > 0)
	{
		if (op_code == 9 || op_code == 10 || op_code == 11 || op_code == 12
				|| op_code == 14 || op_code == 15)
			return (2);
		return (4);
	}
	return (0);
}

static void	print_cmd(t_cmd *cmd, int fd)
{
	t_cmd	*tmp;

	tmp = cmd;
	while (cmd)
	{
		write_int(fd, cmd->op_code, 1);
		print_enc(cmd, fd);
		if (cmd->arg1_type != 0)
			write_int(fd, cmd->arg1_value, oct(cmd->arg1_type, cmd->op_code));
		if (cmd->arg2_type != 0)
			write_int(fd, cmd->arg2_value, oct(cmd->arg2_type, cmd->op_code));
		if (cmd->arg3_type != 0)
			write_int(fd, cmd->arg3_value, oct(cmd->arg3_type, cmd->op_code));
		cmd = cmd->next;
	}
	cmd = tmp;
}

void		write_file(t_file *file, int fd)
{
	t_label	*label;

	label = file->label;
	while (file->label)
	{
		if (file->label->cmd)
			print_cmd(file->label->cmd, fd);
		file->label = file->label->next;
	}
	file->label = label;
}
