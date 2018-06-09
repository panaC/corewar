/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 17:39:27 by pleroux           #+#    #+#             */
/*   Updated: 2018/06/09 18:31:53 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_init_struct(t_env *env)
{
	env->cycle_to_die = CYCLE_TO_DIE;
	env->check = 1;
	env->nb_player = 1;
	env->win_player = 1;
	env->verbos = 0;
	env->verbos_lvl = 0;
	env->visu = 0;
	env->dump = 0;
	env->nb_cycle_dump = 0;
	env->cycle_totale = 1;
	env->cycle = 1;
	env->nb_live = 0;
	env->err_parsing = NULL;
	env->current_process = NULL;
	ft_bzero(env->mem, MEM_SIZE);
}
