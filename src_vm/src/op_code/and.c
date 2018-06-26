/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:39:36 by msukhare          #+#    #+#             */
/*   Updated: 2018/06/26 12:49:16 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdio.h>
#include <stdlib.h>

int				op_and(void *e)
{
	t_process	*p;
	int			pc;

	p = ((t_env *)e)->current_process;
	pc = op_decod_arg((t_env*)e);
	if (p->op.arg[2] > 0 && p->op.arg[2] <= REG_NUMBER)
	{
		if (p->op.encodage.bit.a4 == T_REG_BIT &&
				p->op.arg[0] > 0 && p->op.arg[0] <= REG_NUMBER)
			p->op.arg[0] = p->reg[p->op.arg[0] - 1].v;
		if (p->op.encodage.bit.a4 == T_IND_BIT)
			p->op.arg[0] = get_int_mem_pc((t_env*)e, REG_SIZE,
					p->pc + (p->op.arg[0] % IDX_MOD)).v32;
		if (p->op.encodage.bit.a3 == T_REG_BIT &&
				p->op.arg[1] > 0 && p->op.arg[1] <= REG_NUMBER)
			p->op.arg[1] = p->reg[p->op.arg[1] - 1].v;
		if (p->op.encodage.bit.a3 == T_IND_BIT)
			p->op.arg[1] = get_int_mem_pc((t_env*)e, REG_SIZE,
					p->pc + (p->op.arg[1] % IDX_MOD)).v32;
		p->reg[p->op.arg[2] - 1].v = p->op.arg[0] & p->op.arg[1];
		p->carry = (((p->reg[p->op.arg[2] - 1]).v == 0) ? TRUE : FALSE);
	}
	p->pc = pc;
	return (TRUE);
}
