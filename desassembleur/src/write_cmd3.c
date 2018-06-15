/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_cmd3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 21:10:33 by lchancri          #+#    #+#             */
/*   Updated: 2018/06/11 17:32:36 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/desasm.h"

int			write_sti(t_file *file, int fd)
{
	int		size;

	write(fd, "sti ", 4);
	file = file->next;
	size = write_enc(file, fd, 2, 0);
	write(fd, "\n", 1);
	return (size + 1);
}

int			write_fork(t_file *file, int fd)
{
	int		a;

	a = 0;
	write(fd, "fork ", 5);
	file = file->next;
	if (file)
		a = create_num(file, 3, fd, 0);
	ft_putnbr_fd(a, fd);
	write(fd, "\n", 1);
	return (3);
}

int			write_lld(t_file *file, int fd)
{
	int		size;

	write(fd, "lld ", 4);
	file = file->next;
	size = write_enc(file, fd, 4, 0);
	write(fd, "\n", 1);
	return (size + 1);
}

int			write_lldi(t_file *file, int fd)
{
	int		size;

	write(fd, "lldi ", 5);
	file = file->next;
	size = write_enc(file, fd, 2, 0);
	write(fd, "\n", 1);
	return (size + 1);
}

int			write_lfork(t_file *file, int fd)
{
	int		a;

	a = 0;
	write(fd, "lfork ", 6);
	file = file->next;
	if (file)
		a = create_num(file, 3, fd, 0);
	ft_putnbr_fd(a, fd);
	write(fd, "\n", 1);
	return (3);
}
