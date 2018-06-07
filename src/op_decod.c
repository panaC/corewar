/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_decod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 19:20:39 by pierre            #+#    #+#             */
/*   Updated: 2018/06/07 15:46:26 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "corewar.h"
#include "op.h"
#include <ft_printf.h>
#include <stdlib.h>
#include <stdio.h>

int				rot_mem(int *pc)
{
	*pc = *pc + 1;
	if (*pc >= MEM_SIZE)
		*pc = *pc % MEM_SIZE;
	if (*pc < 0)
		*pc = MEM_SIZE - *pc % MEM_SIZE;

	return (*pc);
}

int				rot_mem_set(int *pc)
{
	if (*pc >= MEM_SIZE)
		*pc = *pc % MEM_SIZE;
	if (*pc < 0)
		*pc = MEM_SIZE - *pc % MEM_SIZE;
	return (*pc);
}

int				op_decod(t_env *e)
{
	t_process	*p;

	verbose(e, V_7, "Start Op_decode\n");
	p = e->current_process;
	if (p && e->mem[p->pc] > 0 && e->mem[p->pc] <= REG_NUMBER)
	{
		if (p->op.info.op_code == 0)
		{
			p->op.op_code = e->mem[p->pc];
			p->op.info = op_tab[e->mem[p->pc] - 1];
			verbose(e, V_7, "op: op_code %x\n", e->mem[p->pc]);
		}
		if (p->op.info.cycle == 1)
		{
			verbose(e, V_7, "op: Start fct %x\n", e->mem[p->pc]);
			p->op.info.ft(e);
			process_init_instruction(&(p->op));
		}
		--(p->op.info.cycle);
	}
	else
		rot_mem(&(p->pc));
	verbose(e, V_7, "End Op_decode\n");
	return (TRUE);
}
