/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 22:54:54 by pleroux           #+#    #+#             */
/*   Updated: 2018/06/13 13:17:54 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "op_code.h"
#include "corewar.h"
#include "op.h"
#include <ft_printf.h>

int			op_sti(void *e)
{
	t_process	*p;
	int			pc;

	p = ((t_env *)e)->current_process;
	pc = op_decod_arg((t_env*)e);
	if (p->op.arg[0] && p->op.arg[0] <= REG_NUMBER)
	{
		if (p->op.encodage.bit.a3 == T_REG_BIT &&
				p->op.arg[1] && p->op.arg[1] <= REG_NUMBER)
			p->op.arg[1] = p->reg[p->op.arg[1] - 1].v;
		if (p->op.encodage.bit.a3 == T_IND_BIT)
			p->op.arg[1] = get_int_mem_pc((t_env*)e, REG_SIZE,
					p->pc + (p->op.arg[1] % IDX_MOD)).v32;
		if (p->op.encodage.bit.a2 == T_REG_BIT &&
				p->op.arg[2] && p->op.arg[2] <= REG_NUMBER)
			p->op.arg[2] = p->reg[p->op.arg[2] - 1].v;
		p->op.arg[2] += p->op.arg[1];
		verbose(e, V_7, "op:sti: s=%0.8x\n", p->op.arg[2]);
		set_int_mem_pc((t_env*)e, REG_SIZE,
				p->pc + p->op.arg[2], (t_int)p->reg[p->op.arg[0] - 1].v);
		set_int_gui_pc((t_env*)e, REG_SIZE,
				p->pc + (p->op.arg[1] % IDX_MOD), (t_int)p->numero);
	}
	p->pc = pc;
	return (TRUE);
}
