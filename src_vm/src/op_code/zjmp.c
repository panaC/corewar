/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 14:07:20 by msukhare          #+#    #+#             */
/*   Updated: 2018/06/20 20:16:20 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdio.h>
#include <stdlib.h>

int		op_zjmp(void *e)
{
	t_process	*p;
	int			pc;

	p = ((t_env*)e)->current_process;
	pc = op_decod_arg((t_env*)e);
	if (p->carry == 1)
	{
		p->pc += (p->op.arg[0] % IDX_MOD);
		rot_mem_set(&(p->pc));
		verbose(e, V_7, "op:zjmp: pc=%d\n", p->pc);
	}
	else
		p->pc = pc;
	return (TRUE);
}
