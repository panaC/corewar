/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 09:28:49 by msukhare          #+#    #+#             */
/*   Updated: 2018/06/20 19:03:22 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>
#include "op_code.h"
#include "corewar.h"
#include "op.h"

int				op_live(void *e)
{
	t_process	*p;
	t_env		*env;
	int			i;
	int			pc;

	i = 0;
	env = (t_env *)e;
	p = env->current_process;
	pc = op_decod_arg(env);
	p->live = TRUE;
	env->nb_live++;
	while (i < env->nb_player)
	{
		if (p->op.arg[0] == ((env->player[i].numero + 1) * -1))
		{
			verbose(env, 1, "un processus dit que le joueur %d(%s) est en vie\n"
					, i + 1, env->player[i].head.prog_name);
			env->player[i].last_live = env->cycle_totale;
			env->player[i].nb_live++;
			break ;
		}
		i++;
	}
	p->pc = pc;
	return (TRUE);
}
