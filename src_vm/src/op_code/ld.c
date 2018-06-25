/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 07:08:25 by pleroux           #+#    #+#             */
/*   Updated: 2018/06/20 20:12:44 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "op_code.h"
#include "corewar.h"
#include "op.h"

int			op_ld(void *e)
{
	t_process		*p;
	int				pc;

	p = ((t_env*)e)->current_process;
	pc = op_decod_arg((t_env*)e);
	if (p->op.arg[1] > 0 && p->op.arg[1] <= REG_NUMBER)
	{
		if (p->op.encodage.bit.a4 == T_IND_BIT)
			p->op.arg[0] = get_int_mem_pc((t_env*)e, REG_SIZE,
					p->pc + (p->op.arg[0] % IDX_MOD)).v32;
		p->reg[p->op.arg[1] - 1].v = p->op.arg[0];
		verbose(e, V_7, "op:ld: reg[%d]=%x\n", p->op.arg[1] - 1,
				p->reg[p->op.arg[1] - 1].v);
		p->carry = ((p->op.arg[0] == 0) ? TRUE : FALSE);
	}
	p->pc = pc;
	return (TRUE);
}
