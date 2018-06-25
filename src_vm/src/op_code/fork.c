/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 02:26:04 by msukhare          #+#    #+#             */
/*   Updated: 2018/06/19 16:22:37 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.h"
#include <libft.h>

int			op_fork(void *e)
{
	t_process	*p;
	int			pc;

	p = ((t_env*)e)->current_process;
	pc = op_decod_arg((t_env*)e);
	p->pc += (p->op.arg[0] % IDX_MOD);
	process_add_lst(&(((t_env*)e)->player[p->numero - 1].process),
			p, rot_mem_set(&(p->pc)));
	verbose(e, V_7, "op:fork: pc=%d\n", p->pc);
	p->pc = pc;
	return (TRUE);
}
