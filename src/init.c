/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 17:39:27 by pleroux           #+#    #+#             */
/*   Updated: 2018/06/02 12:44:02 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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

void	ft_init_struct(t_env *env)
{
	env->verbos = 0;
	env->verbos_lvl = 0;
	env->visu = 0;
	env->dump = 0;
	env->nb_cycle_dump = 0;
	env->cycle_totale = 0;
	env->cycle = 0;
	env->cycle_totale = 0;
	env->nb_live = 0;
	env->err_parsing = NULL;
	env->current_process = NULL;
	ft_bzero(env->mem, MEM_SIZE);
}

