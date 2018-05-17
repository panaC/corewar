/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 16:02:23 by msukhare          #+#    #+#             */
/*   Updated: 2018/05/17 10:49:25 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ft_init_struct(t_env *env)
{
	int		i;

	i = 0;
	env->verbos = 0;
	env->visu = 0;
	while (i < MAX_PLAYERS)
	{
		env->fd[i] = -1;
		i++;
	}
}

int			main(int argc, char **argv)
{
	t_env	env;

	ft_init_struct(&env);
	if (!ft_check_argv(argc, argv, &env))
		return (0);
	return (0);
}
