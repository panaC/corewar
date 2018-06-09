/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 16:02:23 by msukhare          #+#    #+#             */
/*   Updated: 2018/06/09 11:46:14 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "parser.h"
#include "op.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int			main(int argc, char **argv)
{
	t_env	env;

	ft_init_struct(&env);
	if (ft_check_argv(argc, argv, &env))
	{
		if (parser(&env))
		{
			game_init(&env);
			game(&env);
			print_win(&env);
		}
		else
			verbose(&env, E, "PARSER -> QUIT\n");
	}
	else
		verbose(&env, E, "ARG -> QUIT\n");
}

int			main_3(int argc, char **argv)
{
	t_env	env;
	//int		i;

	ft_init_struct(&env);
	if (ft_check_argv(argc, argv, &env))
	{
		if (parser(&env))
		{
			printf("parser ok\n");
			game_init(&env);
			ft_print_memory(env.mem, MEM_SIZE / 4);
			/*int j = 0;
			int k = 0;
			while (j < 30)
			{
				k = op_decod((t_process*)env.player[0].process->content, env.mem, k, env.player[0].process);
				printf("%d %d\n", k, ((t_process*)env.player[0].process->content)->reg[1].v);
				j++;
			}*/
			}
		else
		{
			printf("parser err\n");
	/*	i = 0;
		while (i < env.nb_player)
		{
			ft_creat_process(&env, i);
			i++;
		}
		game(&env);
		*/
		}
	}
		/*
	i = 0;
	while (i < env.nb_player)
	{
		printf("name = %s , numero = %d, fd = %d\n", env.player[i].name, env.player[i].numero, env.player[i].fd);
		i++;
	}
	*/
	return (0);
}

/*int			main_2()
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
	return (0);
}*/

