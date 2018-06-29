/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   desasm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 19:35:35 by lchancri          #+#    #+#             */
/*   Updated: 2018/06/28 13:11:00 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/desasm.h"

static int		check_file_extension(char *str)
{
	int		a;

	a = ft_strlen(str) - 4;
	if (a < 1 || ft_strncmp(".cor", &str[a], 4) != 0)
	{
		write(1, "Error : ", 8);
		ft_putstr(str);
		write(1, " is a wrong file (not a .cor file)\n", 35);
		return (0);
	}
	return (1);
}

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
	file = stock_file(0, -1);
	b_file = file;
	while ((a = read(fd, buf, 1)) > 0)
	{
		file->next = stock_file(buf[0], b);
		b++;
		file = file->next;
	}
	if (b == 0)
	{
		free_file(b_file);
		return (NULL);
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
		if (check_file_extension(av[1]) == 0)
			return (0);
		fd = open(av[1], O_RDONLY);
		if (fd < 1)
			return (1);
		file = get_file(fd);
		if (!file)
		{
			write(1, "Error : file is empty\n", 22);
			return (1);
		}
		b_file = file;
		close(fd);
		create_file(file, av[1]);
		free_file(b_file);
		return (0);
	}
	ft_putstr("Usage : ./desasm file_name\n");
	return (1);
}
