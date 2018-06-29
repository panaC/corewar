/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 08:42:38 by msukhare          #+#    #+#             */
/*   Updated: 2018/06/26 09:35:42 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

static void	ft_close_fds(t_env *env, char *str)
{
	int		i;

	i = 0;
	while (i < env->nb_player)
	{
		if (env->player[i].fd != -1 && ft_check_fd_before(env, i))
			close(env->player[i].fd);
		i++;
	}
	ft_putstr_fd("open: ", 2);
	ft_putstr_fd(str, 2);
	perror(" ");
}

static int	ft_init_player(t_env *env, char *str, int place)
{
	int		champ_before;

	errno = 0;
	if ((champ_before = ft_check_champs_before(env, str)) != -1)
		env->player[place].fd = env->player[champ_before].fd;
	else
	{
		if ((env->player[place].fd = open(str, O_RDONLY)) < 0 && errno)
		{
			ft_close_fds(env, str);
			return (0);
		}
	}
	env->player[place].numero = place;
	env->player[place].nb_live = 0;
	env->player[place].name = str;
	env->player[place].last_live = 0;
	return (1);
}

static int	ft_put_in_place(t_env *env, char **argv, int start, int argc)
{
	int		place;

	while (start < argc)
	{
		if (argv[start][0] == '-' && ft_strcmp(argv[start], "-n") == 0 &&
				argv[start + 1] && argv[start + 2])
		{
			if ((place = (ft_atoi(argv[start + 1]) - 1)) < 0)
			{
				ft_putstr_fd("place is under to 1\n", 2);
				return (0);
			}
			if (ft_check_in_tab_player(place, env) == 0)
				return (0);
			if (ft_init_player(env, argv[start + 2], place) == 0)
				return (0);
			start += 3;
		}
		else
			start++;
	}
	return (1);
}

static int	ft_get_random_place(t_env *env)
{
	int		i;

	i = 0;
	while (i < env->nb_player)
	{
		if (env->player[i].fd == -1)
			return (i);
		i++;
	}
	return (0);
}

int			ft_init_players(t_env *env, char **argv, int start, int argc)
{
	if (ft_put_in_place(env, argv, start, argc) == 0)
		return (0);
	while (start < argc)
	{
		if (argv[start][0] == '-' && ft_strcmp(argv[start], "-n") == 0 &&
				argv[start + 1] && argv[start + 2])
			start += 2;
		else if (ft_str_in_str(argv[start], ".cor") == 1)
		{
			if (ft_init_player(env, argv[start], ft_get_random_place(env)) == 0)
				return (0);
		}
		start++;
	}
	return (1);
}
