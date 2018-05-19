/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 16:02:23 by msukhare          #+#    #+#             */
/*   Updated: 2018/05/18 10:14:45 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "parser.h"
#include <stdio.h>

static void	ft_init_struct(t_env *env)
{
	env->verbos = 0;
	env->visu = 0;
	env->cycle_totale = 0;
	env->cycle = 0;
	env->nb_live = 0;
	env->check = 0;
	ft_bzero(env->mem, MEM_SIZE);
}

int			main(int argc, char **argv)
{
	t_env	env;
	int		i;

	ft_init_struct(&env);
	if (ft_check_argv(argc, argv, &env))
	{
	/*	if (parser(&env))
		{
			printf("parser ok\n");
		}
		else
		{*/
			printf("parser err\n");
	//	}
	i = 0;
	while (i < env.nb_player)
	{
		printf("name = %s , numero = %d, fd = %d\n", env.player[i].name, env.player[i].numero, env.player[i].fd);
		i++;
	}
	}
	return (0);
}
