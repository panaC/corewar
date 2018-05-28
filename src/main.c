/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 16:02:23 by msukhare          #+#    #+#             */
/*   Updated: 2018/05/26 14:39:07 by msukhare         ###   ########.fr       */
/*   Updated: 2018/05/20 00:34:44 by pleroux          ###   ########.fr       */
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
	env->dump = 0;
	env->nb_cycle_dump = 0;
	env->cycle_totale = 0;
	env->cycle = 0;
	env->nb_live = 0;
	env->check = 0;
	ft_bzero(env->mem, MEM_SIZE);
}
/*
void		ft_creat_process(t_env *env, int i)
{
	t_process *tmp;

	tmp = (t_process*)malloc(sizeof(t_process) * 1);
	env->player[i].process = tmp;
	tmp->next = NULL;
	tmp->live = 1;
	tmp->carry = 0;
	tmp->pc = 1;
	tmp->name = "end";
	if (i >= 0)
	{
		tmp = (t_process*)malloc(sizeof(t_process) * 1);
		tmp->next = env->player[i].process;
		env->player[i].process = tmp;
		tmp->live = 4;
		tmp->carry = 0;
		tmp->pc = 2;
		tmp->name = "end -1";
		if (i >= 1)
		{
			tmp = (t_process*)malloc(sizeof(t_process) * 1);
			tmp->next = env->player[i].process;
			env->player[i].process = tmp;
			tmp->live = 4;
			tmp->carry = 0;
			tmp->pc = 3;
		tmp->name = "end -2";
			if (i >= 2)
			{
				tmp = (t_process*)malloc(sizeof(t_process) * 1);
				tmp->next = env->player[i].process;
				env->player[i].process = tmp;
				tmp->live = 5;
				tmp->carry = 1;
				tmp->pc = 4;
		tmp->name = "end -3";
				tmp = (t_process*)malloc(sizeof(t_process) * 1);
				tmp->next = env->player[i].process;
				env->player[i].process = tmp;
				tmp->live = 6;
				tmp->carry = 1;
				tmp->pc = 5;
		tmp->name = "end -4";
				tmp = (t_process*)malloc(sizeof(t_process) * 1);
				tmp->next = env->player[i].process;
				env->player[i].process = tmp;
				tmp->live = 5;
				tmp->carry = 1;
				tmp->pc = 6;
			tmp->name = "end -5";
				tmp = (t_process*)malloc(sizeof(t_process) * 1);
				tmp->next = env->player[i].process;
				env->player[i].process = tmp;
				tmp->live = 5;
				tmp->carry = 1;
				tmp->pc = 7;
		tmp->name = "start";
			}
		}
	}
}
*/
int			main(int argc, char **argv)
{
	t_env	env;
	int		i;

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
			while (j < 50)
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
			i++;*/
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

