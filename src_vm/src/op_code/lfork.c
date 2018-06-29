/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 17:10:56 by pierre            #+#    #+#             */
/*   Updated: 2018/06/19 16:22:46 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.h"
#include <libft.h>

int			op_lfork(void *e)
{
	t_process	*p;
	int			pc;

	p = ((t_env*)e)->current_process;
	pc = op_decod_arg((t_env*)e);
	p->pc += p->op.arg[0];
	process_add_lst(&(((t_env*)e)->player[p->numero - 1].process), p,
			rot_mem_set(&(p->pc)));
	verbose(e, V_7, "op:lfork: pc=%d\n", p->pc);
	p->pc = pc;
	return (TRUE);
}
