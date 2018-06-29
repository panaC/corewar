/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 17:29:35 by lchancri          #+#    #+#             */
/*   Updated: 2018/06/27 16:42:49 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/desasm.h"

static void		write_type(int fd, int type, int size)
{
	if (size != 0)
		write(fd, ", ", 2);
	if (type == 1)
		write(fd, "r", 1);
	if (type == 3 || type == 4 || type == 5)
		write(fd, "%", 1);
}

int				create_num(t_file *file, int type, int fd, int size)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	write_type(fd, type, size);
	while (file && size > 0)
	{
		file = file->next;
		size--;
	}
	if (type == 3 || type == 5)
		type--;
	while (file && b < type)
	{
		if (file->c < 0)
			a |= (unsigned char)file->c;
		else
			a |= file->c;
		if (b < type - 1)
			a = a << 8;
		file = file->next;
		b++;
	}
	return (a);
}

int				write_enc(t_file *f, int fd, int dir, int size)
{
	int		b;

	b = 128;
	while (1 && f)
	{
		if (b & f->c)
		{
			b = b >> 1;
			if (f && b & f->c && f->next && (size = size + 2) != -1)
				ft_putnbr_fd(create_num(f->next, 2, fd, size - 2), fd);
			else if ((size = size + dir) != -1)
				ft_putnbr_fd(create_num(f->next, dir + 1, fd, size - dir), fd);
		}
		else
		{
			b = b >> 1;
			if (!(b & f->c))
				return (size + 1);
			size = size + 1;
			ft_putnbr_fd(create_num(f->next, 1, fd, size - 1), fd);
		}
		b = b >> 1;
	}
	return (size + 1);
}
