/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 16:55:14 by msukhare          #+#    #+#             */
/*   Updated: 2018/05/17 14:06:07 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	ft_get_opt(char *str, t_env *env)
{
	if (ft_strcmp(str, "-v") == 0)
		env->verbos = 1;
	else if (ft_strcmp(str, "-s") == 0)
		env->visu = 1;
	/*
	 bonus a rajouter
	*/
	else
		return (0);
	return (1);
}

static int	ft_check_opt(char **argv, int argc, t_env *env)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if ((argv[i][0] != '-' || ft_strcmp("-n", argv[i]) == 0) &&
				argv[i][0] != '\0')
			return (i);
		else
		{
			if (ft_get_opt(argv[i], env) <= 0)
			{
				ft_putstr_fd("wrong option bro\n", 2);
				return (0);
			}
		}
		i++;
	}
	ft_putstr_fd("no champ\n", 2);
	return (0);
}

int			ft_check_argv(int argc, char **argv, t_env *env)
{
	int		end_opt;

	if ((end_opt = ft_check_opt(argv, argc, env)) == 0)
		return (0);
	if (ft_if_opt_in_sec(end_opt, argv, argc) == 0 ||
			ft_if_after_n_error(end_opt, argv, argc) == 0 ||
			(env->nb_player = ft_check_nb_champ(argv, argc, end_opt)) == 0 ||
			ft_open_fd_for_champs(env, argv, argc, end_opt) == 0)
		return (0);
	return (1);
}
