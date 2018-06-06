/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 18:16:14 by pierre            #+#    #+#             */
/*   Updated: 2018/06/06 17:48:47 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "corewar.h"
#include "op_code.h"
#include "op.h"

int			op_lldi(void *env)
{
	t_process		*p;
	t_env			*e;
	int				pc;
	t_uint			s;
	int				i;

	i = (IND_SIZE > 4 ? 3 : IND_SIZE - 1);
	e = (t_env *)env;
	p = e->current_process;
	pc = p->pc + p->op.arg[0];
	while (i >= 0)
		s.v[--i] = e->mem[rot_mem(&pc)];
	s.v32 += p->op.arg[1];
	i = (REG_SIZE > 4 ? 3 : REG_SIZE - 1);
	while (i >= 0)
		p->reg[p->op.arg_raw[2]].t[--i] = e->mem[rot_mem(&(s.v32))];
	p->carry = 1;
	return (FALSE);
}
