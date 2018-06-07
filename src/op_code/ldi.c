/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 07:23:51 by pleroux           #+#    #+#             */
/*   Updated: 2018/06/07 21:00:22 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "op_code.h"
#include "corewar.h"
#include "op.h"

int			op_ldi(void *env)
{
	(void)env;
//	t_process		*p;
//	t_env			*e;
//	int				pc;
//	t_uint			s;
//	int				i;
//
//	i = (IND_SIZE > 4 ? 3 : IND_SIZE - 1);
//	e = (t_env *)env;
//	p = e->current_process;
//	pc = p->pc + (p->op.arg[0] % IDX_MOD);
//	while (i >= 0)
//		s.v[--i] = e->mem[rot_mem(&pc)];
//	s.v32 += p->op.arg[1];
//	i = (REG_SIZE > 4 ? 3 : REG_SIZE - 1);
//	while (i >= 0)
//		p->reg[p->op.arg_raw[2]].t[--i] = e->mem[rot_mem(&(s.v32))];
//	p->carry = 1;
	return (FALSE);
}
