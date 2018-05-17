/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 16:02:23 by msukhare          #+#    #+#             */
/*   Updated: 2018/05/17 14:25:49 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdio.h>

static void	ft_init_struct(t_env *env)
{
	int		i;

	i = 0;
	env->verbos = 0;
	env->visu = 0;
	env->cycle_totale = 0;
	env->cycle = 0;
	env->nb_live = 0;
	env->check = 0;
	while (i < MAX_PLAYERS)
	{
		env->fd[i] = -1;
		i++;
	}
	ft_bzero(env->mem, MEM_SIZE);
}

int			main(int argc, char **argv)
{
	t_env	env;

	ft_init_struct(&env);
	if (ft_check_argv(argc, argv, &env))
	{
		if (parser(&env))
		{
			printf("parser ok\n");
		}
		else
		{
			printf("parser err\n");
		}
	}
	return (0);
}
