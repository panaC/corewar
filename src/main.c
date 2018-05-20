/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 16:02:23 by msukhare          #+#    #+#             */
/*   Updated: 2018/05/19 22:48:12 by msukhare         ###   ########.fr       */
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
	env->verbos = 0;
	env->visu = 0;
	env->cycle_totale = 0;
	env->cycle = 0;
	env->nb_live = 0;
	env->check = 0;
	ft_bzero(env->mem, MEM_SIZE);
}

void		ft_creat_process(t_env *env, int i)
{
	t_process *tmp;

	tmp = (t_process*)malloc(sizeof(t_process) * 1);
	env->player[i].process = tmp;
	tmp->next = NULL;
	tmp->live = 1;
	tmp->carry = 0;
	tmp->pc = 1;
	if (i >= 0)
	{
		tmp = (t_process*)malloc(sizeof(t_process) * 1);
		tmp->next = env->player[i].process;
		env->player[i].process = tmp;
		tmp->live = 2;
		tmp->carry = 1;
		tmp->pc = 2;
		if (i >= 1)
		{
			tmp = (t_process*)malloc(sizeof(t_process) * 1);
			tmp->next = env->player[i].process;
			env->player[i].process = tmp;
			tmp->live = 0;
			tmp->carry = 1;
			tmp->pc = 3;
			if (i >= 2)
			{
				tmp = (t_process*)malloc(sizeof(t_process) * 1);
				tmp->next = env->player[i].process;
				env->player[i].process = tmp;
				tmp->live = 2;
				tmp->carry = 1;
				tmp->pc = 4;
				tmp = (t_process*)malloc(sizeof(t_process) * 1);
				tmp->next = env->player[i].process;
				env->player[i].process = tmp;
				tmp->live = 2;
				tmp->carry = 1;
				tmp->pc = 5;
				tmp = (t_process*)malloc(sizeof(t_process) * 1);
				tmp->next = env->player[i].process;
				env->player[i].process = tmp;
				tmp->live = 2;
				tmp->carry = 1;
				tmp->pc = 6;
				tmp = (t_process*)malloc(sizeof(t_process) * 1);
				tmp->next = env->player[i].process;
				env->player[i].process = tmp;
				tmp->live = 2;
				tmp->carry = 1;
				tmp->pc = 7;
			}
		}
	}
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
			game_init(&env);
			ft_print_memory(env.mem, MEM_SIZE);
		}
		else
		{
			printf("parser err\n");*/
		i = 0;
		while (i < env.nb_player)
		{
			ft_creat_process(&env, i);
			i++;
		}
		game(&env);
	}
	i = 0;
	while (i < env.nb_player)
	{
		printf("name = %s , numero = %d, fd = %d\n", env.player[i].name, env.player[i].numero, env.player[i].fd);
		i++;
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
	return (0);
}

