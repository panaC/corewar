/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_fd_for_champs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 10:37:43 by msukhare          #+#    #+#             */
/*   Updated: 2018/05/17 13:46:59 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <fcntl.h>
#include <errno.h>
#include <string.h>

static int	ft_check_fd_closed(int *fds, int fd, int end)
{
	int		i;

	i = 0;
	while (i < end)
	{
		if (fds[i] == fd)
			return (0);
		i++;
	}
	return (1);
}

static void	ft_close_fd(t_env *env, int to)
{
	int		i;

	i = 0;
	while (i < to)
	{
		if (ft_check_fd_closed(env->fd, env->fd[i], i) == 1)
			close(env->fd[i]);
		i++;
	}
	perror("open");
}

static int	ft_check_before(char **argv, int to_cmp, int argc)
{
	int		i;

	i = 1;
	while (i < argc && i < to_cmp)
	{
		if (ft_strcmp(argv[i], argv[to_cmp]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_get_fd_before(int argc, char **argv, int to)
{
	int		i;

	i = 0;
	while (i < argc && i < to && ft_strcmp(argv[i], argv[to]) != 0)
		i++;
	return (i);
}

int			ft_open_fd_for_champs(t_env *env, char **argv, int argc, int start)
{
	int		i;

	i = 0;
	errno = 0;
	while (start < argc)
	{
		if (argv[start][0] != '-' && ft_str_in_str(argv[start], ".cor") == 1)
		{
			if (ft_check_before(argv, start, argc) == 1)
			{
				if ((env->fd[i] = open(argv[start], 'r')) < 0 && errno)
				{
					ft_close_fd(env, i);
					return (0);
				}
			}
			else
				env->fd[i] = env->fd[ft_get_fd_before(argc, argv, start)];
			i++;
		}
		start++;
	}
	return (1);
}
