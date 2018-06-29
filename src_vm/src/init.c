/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 17:39:27 by pleroux           #+#    #+#             */
/*   Updated: 2018/06/26 12:37:09 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_init_struct(t_env *env)
{
	env->cycle_to_die = CYCLE_TO_DIE;
	env->check = 0;
	env->nb_player = 1;
	env->win_player = 1;
	env->verbos = 0;
	env->verbos_lvl = 0;
	env->visu = 0;
	env->dump = 0;
	env->nb_cycle_dump = 0;
	env->cycle_totale = 0;
	env->cycle = 0;
	env->nb_live = 0;
	env->err_parsing = NULL;
	env->current_process = NULL;
	ft_bzero(env->mem, MEM_SIZE);
	ft_bzero(env->mem_gui, MEM_SIZE);
}

void	init_header(t_header *a)
{
	a->magic = 0;
	a->prog_size = 0;
	ft_bzero(a->prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(a->comment, COMMENT_LENGTH + 1);
}
