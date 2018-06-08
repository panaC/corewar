/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 13:06:40 by lchancri          #+#    #+#             */
/*   Updated: 2018/06/06 21:07:51 by lchancri         ###   ########.fr       */
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

void		affiche_file(t_file *file)
{
	t_cmd		*cmd;

	printf("name : %s\n", file->name);
	printf("comment : %s\n", file->comment);
	while (file->label)
	{
		printf("label, a = %d : %s\n", file->label->a, file->label->name);
		while (file->label->cmd)
		{
			cmd = file->label->cmd;
			printf("			%d", cmd->op_code);
			if (cmd->arg1_type != 0)
				printf(", 1:%d(%d)", cmd->arg1_type, cmd->arg1_value);
			if (cmd->arg2_type != 0)
				printf(", 2:%d(%d)", cmd->arg2_type, cmd->arg2_value);
			if (cmd->arg3_type != 0)
				printf(", 3:%d(%d)", cmd->arg3_type, cmd->arg3_value);
			printf("\n");
			file->label->cmd = file->label->cmd->next;
		}
		file->label = file->label->next;
	}
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

	file = init_file();
	if (check_file(str, 0, 0, file) != NULL)
	{
	//	if (file)
	//		affiche_file(file);
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
			return (0);
		if (str[0] == '\0')
			return (empty_file(str));
		return (main2(str, ac[1]));
	}
	else
		write(1, "Error : too much arguments passed to the function\n", 50);
	return (0);
}
