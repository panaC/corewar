/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 21:00:47 by pleroux           #+#    #+#             */
/*   Updated: 2018/06/18 11:33:07 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "op_code.h"
#include "corewar.h"
#include "op.h"

int			op_lld(void *e)
{
	t_process		*p;
	int				pc;

	p = ((t_env*)e)->current_process;
	pc = op_decod_arg((t_env*)e);
	if (p->op.arg[1] > 0 && p->op.arg[1] <= REG_NUMBER)
	{
		if (p->op.encodage.bit.a4 == T_IND_BIT)
			p->op.arg[0] = get_int_mem_pc((t_env*)e, REG_SIZE,
					p->pc + p->op.arg[0]).v32;
		p->reg[p->op.arg[1] - 1].v = p->op.arg[0];
		verbose(e, V_7, "op:lld: reg[%d]=%x\n", p->op.arg[1] - 1,
				p->reg[p->op.arg[1] - 1].v);
		if (p->op.arg[0] == 0)
			p->carry = 1;
		else
			p->carry = FALSE;
	}
	p->pc = pc;
	return (TRUE);
}
