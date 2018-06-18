/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 06:22:36 by pleroux           #+#    #+#             */
/*   Updated: 2018/06/18 09:18:00 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "op_code.h"
#include "corewar.h"
#include "op.h"

int			op_st(void *e)
{
	t_process		*p;
	int				pc;
	t_int			val;

	p = ((t_env*)e)->current_process;
	pc = op_decod_arg((t_env*)e);
	val.v32 = 0;
	if (p->op.arg[0] > 0 && p->op.arg[0] <= REG_NUMBER)
	{
		val.v32 = p->reg[p->op.arg[0] - 1].v;
		if (p->op.encodage.bit.a3 == T_IND_BIT)
		{
			set_int_mem_pc((t_env*)e, REG_SIZE,
					p->pc + (p->op.arg[1] % IDX_MOD), val);
			set_int_gui_pc((t_env*)e, REG_SIZE,
					p->pc + (p->op.arg[1] % IDX_MOD), p->numero);
			verbose(e, V_7, "op:st: mem[%d]=%x\n", p->pc, val.v32);
		}
		else if (p->op.encodage.bit.a3 == T_REG_BIT &&
				p->op.arg[0] >= 0 && p->op.arg[0] <= REG_NUMBER)
		{
			p->reg[p->op.arg[1] - 1].v = val.v32;
			verbose(e, V_7, "op:st: reg[%d]=%x\n", p->op.arg[1] - 1, val.v32);
		}
	}
	p->pc = pc;
	return (TRUE);
}
