/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 16:02:23 by msukhare          #+#    #+#             */
/*   Updated: 2018/05/19 16:04:39 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "parser.h"
#include "op.h"
#include <fcntl.h>
#include <stdlib.h>
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
			game_init(&env);
			ft_print_memory(env.mem, MEM_SIZE);
		}
		else
		{
			printf("parser err\n");
		}
	}
	return (0);
}

int			main_2()
{
	t_env		e;
	char *file = "test/asm/test.txt";

	int fd = open(file, O_RDONLY);
	printf("fd %d\n", fd);

	e.nb_player = 1;
	e.player[0].process = NULL;
	e.player[0].numero = 1;
	e.player[0].fd = fd;
	e.player[0].name = file;
	ft_bzero(e.player[0].data, CHAMP_MAX_SIZE);

	int val = parser(&e);
	ft_print_memory(e.player[0].data, CHAMP_MAX_SIZE);

	printf("val %d\n", val);
}

