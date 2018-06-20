/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 09:28:49 by msukhare          #+#    #+#             */
/*   Updated: 2018/06/20 11:17:13 by pleroux          ###   ########.fr       */
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
	p->live = 1;
	env->nb_live++;
	while (i < env->nb_player)
	{
		if (p->op.arg[0] == ((env->player[i].numero + 1) * - 1))
		{
			env->player[i].last_live = env->cycle;
			env->player[i].nb_live++;
			p->pc = pc;
			return (TRUE);
		}
		i++;
	}
	p->pc = pc;
	return (TRUE);
}
