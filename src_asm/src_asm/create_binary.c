/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_binary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 19:30:00 by lchancri          #+#    #+#             */
/*   Updated: 2018/06/28 12:53:38 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

static void	write_padding(int fd)
{
	int				a;
	unsigned char	c;

	a = 0;
	c = 0;
	while (a < 4)
	{
		write(fd, &c, 1);
		a++;
	}
}

static void	write_size(int fd, int size)
{
	unsigned char	a;
	unsigned char	b;
	unsigned char	c;
	unsigned char	d;

	a = 0;
	b = 0;
	c = 0;
	d = 0;
	write_padding(fd);
	a |= size;
	size = size >> 8;
	b |= size;
	size = size >> 8;
	c |= size;
	size = size >> 8;
	d |= size;
	write(fd, &d, 1);
	write(fd, &c, 1);
	write(fd, &b, 1);
	write(fd, &a, 1);
}

static void	write_name_comment_lenght(int fd, t_file *file, int a)
{
	unsigned char	c;

	c = 0x00;
	while (file->name[a] != '\0')
	{
		write(fd, &file->name[a], 1);
		a++;
	}
	while (a < PROG_NAME_LENGTH)
	{
		write(fd, &c, 1);
		a++;
	}
	write_size(fd, file->length);
	a = 0;
	while (file->comment[a] != '\0')
	{
		write(fd, &file->comment[a], 1);
		a++;
	}
	while (a < COMMENT_LENGTH)
	{
		write(fd, &c, 1);
		a++;
	}
}

static void	write_magic(int fd, t_file *file)
{
	unsigned char	a;
	unsigned char	b;
	unsigned char	c;
	unsigned char	d;
	int				exec;

	a = 0;
	b = 0;
	c = 0;
	d = 0;
	exec = COREWAR_EXEC_MAGIC;
	a |= exec;
	exec = exec >> 8;
	b |= exec;
	exec = exec >> 8;
	c |= exec;
	exec = exec >> 8;
	d |= exec;
	write(fd, &d, 1);
	write(fd, &c, 1);
	write(fd, &b, 1);
	write(fd, &a, 1);
	write_name_comment_lenght(fd, file, 0);
	write_padding(fd);
	write_file(file, fd);
}

void		create_binary(t_file *file, char *name)
{
	int		a;
	int		fd;
	char	*binary;

	a = 0;
	while (name[a] != '\0')
		a++;
	if (!(binary = (char*)malloc(sizeof(char) * (a + 3))))
		return ;
	binary = ft_strcpy(binary, name);
	binary[a - 1] = 'c';
	binary[a] = 'o';
	binary[a + 1] = 'r';
	binary[a + 2] = '\0';
	write(1, "Writting output program to ", 27);
	ft_putstr(binary);
	write(1, "\n", 1);
	if ((fd = open(binary, O_CREAT | O_WRONLY | O_TRUNC, 0600)) <= 0)
	{
		free(binary);
		return ;
	}
	free(binary);
	write_magic(fd, file);
	close(fd);
}
