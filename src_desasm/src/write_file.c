/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:30:22 by lchancri          #+#    #+#             */
/*   Updated: 2018/06/28 13:27:36 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/desasm.h"

static int	write_file2(t_file *file, int fd)
{
	if (file->c == 6)
		return (write_and(file, fd));
	else if (file->c == 7)
		return (write_or(file, fd));
	else if (file->c == 8)
		return (write_xor(file, fd));
	else if (file->c == 9)
		return (write_zjmp(file, fd));
	else if (file->c == 10)
		return (write_ldi(file, fd));
	else if (file->c == 11)
		return (write_sti(file, fd));
	else if (file->c == 12)
		return (write_fork(file, fd));
	else if (file->c == 13)
		return (write_lld(file, fd));
	else if (file->c == 14)
		return (write_lldi(file, fd));
	else if (file->c == 15)
		return (write_lfork(file, fd));
	else if (file->c == 16)
		return (write_aff(file, fd));
	return (0);
}

static void	write_file(t_file *file, int fd, int a)
{
	if (file && file->c == 1)
		a = write_live(file, fd);
	else if (file && file->c == 2)
		a = write_ld(file, fd);
	else if (file && file->c == 3)
		a = write_st(file, fd);
	else if (file && file->c == 4)
		a = write_add(file, fd);
	else if (file && file->c == 5)
		a = write_sub(file, fd);
	else if (file)
		a = write_file2(file, fd);
	if (a == 0)
		return ;
	if (file)
		a = a + file->place;
	while (file && file->place != a)
		file = file->next;
	if (file && file->next)
		write_file(file, fd, 0);
}

static void	write_name_comment(t_file *file, int fd)
{
	while (file && file->place != 4)
		file = file->next;
	write(fd, ".name \"", 7);
	while (file && file->c != '\0' && file->place < 4 + PROG_NAME_LENGTH)
	{
		write(fd, &file->c, 1);
		file = file->next;
	}
	write(fd, "\"\n", 2);
	while (file && file->place < 12 + PROG_NAME_LENGTH)
		file = file->next;
	write(fd, ".comment \"", 10);
	while (file && file->c != '\0'
			&& file->place < 12 + PROG_NAME_LENGTH + COMMENT_LENGTH)
	{
		write(fd, &file->c, 1);
		file = file->next;
	}
	while (file && file->place < 16 + PROG_NAME_LENGTH + COMMENT_LENGTH)
		file = file->next;
	write(fd, "\"\n\n", 3);
	if (file)
		write_file(file, fd, 1);
}

void		create_file(t_file *file, char *name)
{
	int		a;
	int		fd;
	char	*s;

	a = 0;
	while (name[a] != '\0')
		a++;
	if (a > 2 && !(s = (char*)malloc(sizeof(char) * (a - 1))))
		return ;
	if (a > 2)
		s = ft_strncpy(s, name, a - 2);
	s[a - 3] = 's';
	ft_putstr("Writting output program to ");
	ft_putstr(s);
	write(1, "\n", 1);
	if ((fd = open(s, O_CREAT | O_WRONLY | O_TRUNC, 0600)) <= 0)
	{
		free(s);
		return ;
	}
	free(s);
	write_name_comment(file, fd);
	close(fd);
}
