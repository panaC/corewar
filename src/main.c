/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 16:02:23 by msukhare          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/05/18 10:14:45 by msukhare         ###   ########.fr       */
=======
/*   Updated: 2018/05/18 16:02:09 by pierre           ###   ########.fr       */
>>>>>>> f677879a03995ce6bd867e1efddb0f61867f25d4
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "parser.h"
#include <fcntl.h>
#include <stdlib.h>
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

