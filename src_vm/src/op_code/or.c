/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 21:20:32 by pleroux           #+#    #+#             */
/*   Updated: 2018/06/20 20:10:41 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdio.h>
#include <stdlib.h>

int				op_or(void *e)
{
	t_process	*p;
	t_reg		val;
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
		val.v = p->op.arg[0] | p->op.arg[1];
		p->reg[p->op.arg[2] - 1] = val;
		p->carry = ((val.v == 0) ? TRUE : FALSE);
	}
	p->pc = pc;
	return (TRUE);
}