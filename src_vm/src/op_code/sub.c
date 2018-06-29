/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 15:54:06 by pleroux           #+#    #+#             */
/*   Updated: 2018/06/20 20:15:21 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "op_code.h"
#include "corewar.h"
#include "op.h"

int			op_sub(void *e)
{
	t_process	*p;
	t_reg		r;
	int			pc;

	p = ((t_env*)e)->current_process;
	pc = op_decod_arg((t_env*)e);
	if (p->op.arg[0] > 0 && p->op.arg[0] <= REG_NUMBER &&
			p->op.arg[1] > 0 && p->op.arg[1] <= REG_NUMBER &&
			p->op.arg[2] > 0 && p->op.arg[2] <= REG_NUMBER)
	{
		r.v = p->reg[p->op.arg[0] - 1].v - p->reg[p->op.arg[1] - 1].v;
		p->reg[p->op.arg[2] - 1] = r;
		p->carry = ((r.v == 0) ? TRUE : FALSE);
	}
	p->pc = pc;
	return (TRUE);
}
