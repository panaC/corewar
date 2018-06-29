/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 13:06:40 by lchancri          #+#    #+#             */
/*   Updated: 2018/06/28 10:51:04 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

static int	check_file_extension(char *str)
{
	int		a;

	a = ft_strlen(str) - 2;
	if (ft_strncmp(".s", &str[a], 2) != 0)
	{
		write(1, "Error : ", 8);
		ft_putstr(str);
		write(1, " is a wrong file (not a .s file)\n", 33);
		return (0);
	}
	return (1);
}

static char	*get_file(char *str, int fd)
{
	int		a;
	char	buf[2];

	while ((a = read(fd, buf, 1)) > 0 && str)
	{
		buf[a] = '\0';
		str = ft_strjoinfree(str, buf);
		if (buf[a - 1] == '\0')
			return (error_binary());
	}
	return (str);
}

static int	empty_file(char *str)
{
	write(1, "Error : empty file\n", 19);
	free(str);
	return (0);
}

static int	main2(char *str, char *name)
{
	t_file	*file;

	if (str[0] == '\0')
		return (empty_file(str));
	file = init_file();
	if (check_file(str, 0, 0, file) != NULL)
	{
		file = prepare_file(file, 0, 0, 0);
		create_binary(file, name);
		free_file(file);
	}
	free(str);
	return (0);
}

int			main(int av, char **ac)
{
	int		fd;
	char	*str;

	if (av == 2)
	{
		if (check_file_extension(ac[1]) == 0)
			return (0);
		if ((fd = open(ac[1], O_RDONLY)) <= 0)
		{
			write(1, "Error : file opening failed\n", 28);
			return (0);
		}
		if (!(str = (char*)malloc(sizeof(char))))
			return (0);
		str[0] = '\0';
		if ((str = get_file(str, fd)) == NULL)
		{
			close(fd);
			return (0);
		}
		close(fd);
		return (main2(str, ac[1]));
	}
	ft_putstr("./asm [champs.s]\n");
	return (0);
}
