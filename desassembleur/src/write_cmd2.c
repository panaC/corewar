/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_cmd2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 21:10:33 by lchancri          #+#    #+#             */
/*   Updated: 2018/06/11 17:21:07 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/desasm.h"

int			write_and(t_file *file, int fd)
{
	int		size;

	write(fd, "and ", 4);
	file = file->next;
	size = write_enc(file, fd, 4, 0);
	write(fd, "\n", 1);
	return (size + 1);
}

int			write_or(t_file *file, int fd)
{
	int		size;

	write(fd, "or ", 3);
	file = file->next;
	size = write_enc(file, fd, 4, 0);
	write(fd, "\n", 1);
	return (size + 1);
}

int			write_xor(t_file *file, int fd)
{
	int		size;

	write(fd, "xor ", 4);
	file = file->next;
	size = write_enc(file, fd, 4, 0);
	write(fd, "\n", 1);
	return (size + 1);
}

int			write_zjmp(t_file *file, int fd)
{
	int		a;

	a = 0;
	write(fd, "zjmp ", 5);
	file = file->next;
	if (file)
		a = create_num(file, 3, fd, 0);
	ft_putnbr_fd(a, fd);
	write(fd, "\n", 1);
	return (3);
}

int			write_ldi(t_file *file, int fd)
{
	int		size;

	write(fd, "ldi ", 4);
	file = file->next;
	size = write_enc(file, fd, 2, 0);
	write(fd, "\n", 1);
	return (size + 1);
}
