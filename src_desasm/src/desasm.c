/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   desasm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 19:35:35 by lchancri          #+#    #+#             */
/*   Updated: 2018/06/11 11:48:29 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/desasm.h"

static void		free_file(t_file *file)
{
	t_file	*tmp;

	while (file)
	{
		tmp = file;
		file = file->next;
		free(tmp);
	}
}

static t_file	*get_file(int fd)
{
	int		a;
	int		b;
	char	buf[1];
	t_file	*file;
	t_file	*b_file;

	b = 0;
	if (!(file = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	file->place = -1;
	file->c = 0;
	b_file = file;
	while ((a = read(fd, buf, 1)) > 0)
	{
		file->next = stock_file(buf[0], b);
		b++;
		file = file->next;
	}
	return (b_file);
}

int				main(int ac, char **av)
{
	int		fd;
	t_file	*file;
	t_file	*b_file;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		file = get_file(fd);
		b_file = file;
		close(fd);
		create_file(file, av[1]);
		free_file(b_file);
	}
	return (0);
}
