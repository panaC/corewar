/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 16:55:14 by msukhare          #+#    #+#             */
/*   Updated: 2018/06/02 19:50:09 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <libft.h>

static void		init_header(header_t *a)
{
	a->magic = 0;
	a->prog_size = 0;
	ft_bzero(a->prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(a->comment, COMMENT_LENGTH + 1);
}

static int	ft_get_opt(char *str, t_env *env)
{
	if (ft_strcmp(str, "-v") == 0)
		env->verbos = 1;
	else if (ft_strcmp(str, "-s") == 0)
		env->visu = 1;
	else if (ft_strcmp(str, "-dump") == 0)
		env->dump = 1;
	/*
	 bonus a rajouter
	*/
	else
		return (0);
	return (1);
}

static int	ft_chk_dump(t_env *env, int *i, char **argv)
{
	if (!argv[*i + 1] || argv[*i + 1][0] == '\0')
		return (1);
	if (ft_if_all_digit(argv[*i + 1]) == 0)
		return (1);
	env->nb_cycle_dump = ft_atoi(argv[*i + 1]);
	(*i)++;
	return (0);
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
			if (ft_strcmp(argv[i], "-dump") == 0 && ft_chk_dump(env, &i, argv))
			{
				ft_putstr_fd("need nb_cycle after dump\n", 2);
				return (0);
			}
		}
		i++;
	}
	ft_putstr_fd("no champ\n", 2);
	return (0);
}

static void	ft_init_tab_players(t_env *env)
{
	int		i;

	i = 0;
	while (i < env->nb_player)
	{
		init_header(&(env->player[i].head));
		env->player[i].process = NULL;
		env->player[i].numero = 1;
		env->player[i].fd = -1;
		env->player[i].name = NULL;
		env->player[i].mem_ref = 0;
		ft_bzero(env->player[i].data, CHAMP_MAX_SIZE);
		i++;
	}
}
int			ft_check_argv(int argc, char **argv, t_env *env)
{
	int		end_opt;

	if ((end_opt = ft_check_opt(argv, argc, env)) == 0)
		return (0);
	if (ft_if_opt_in_sec(end_opt, argv, argc) == 0 ||
			ft_if_after_n_error(end_opt, argv, argc) == 0 ||
			(env->nb_player = ft_check_nb_champ(argv, argc, end_opt)) == 0)
		return (0);
	ft_init_tab_players(env);
	if (ft_init_players(env, argv, end_opt, argc) == 0)
		return (0);
	return (1);
}
