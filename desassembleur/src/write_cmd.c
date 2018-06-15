/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 21:10:33 by lchancri          #+#    #+#             */
/*   Updated: 2018/06/11 13:24:43 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/desasm.h"

int			write_live(t_file *file, int fd)
{
	int		a;

	a = 0;
	write(fd, "live ", 5);
	file = file->next;
	if (file)
		a = create_num(file, 4, fd, 0);
	ft_putnbr_fd(a, fd);
	write(fd, "\n", 1);
	return (5);
}

int			write_ld(t_file *file, int fd)
{
	int		size;

	write(fd, "ld ", 3);
	file = file->next;
	size = write_enc(file, fd, 4, 0);
	write(fd, "\n", 1);
	return (size + 1);
}

int			write_st(t_file *file, int fd)
{
	int		size;

	write(fd, "st ", 3);
	file = file->next;
	size = write_enc(file, fd, 4, 0);
	write(fd, "\n", 1);
	return (size + 1);
}

int			write_add(t_file *file, int fd)
{
	int		size;

	write(fd, "add ", 4);
	file = file->next;
	size = write_enc(file, fd, 4, 0);
	write(fd, "\n", 1);
	return (size + 1);
}

int			write_sub(t_file *file, int fd)
{
	int		size;

	write(fd, "sub ", 4);
	file = file->next;
	size = write_enc(file, fd, 4, 0);
	write(fd, "\n", 1);
	return (size + 1);
}
