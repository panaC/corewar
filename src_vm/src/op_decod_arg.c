/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_decod_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 12:45:01 by pleroux           #+#    #+#             */
/*   Updated: 2018/06/20 20:20:39 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "corewar.h"
#include "op.h"

void		set_int_mem_pc(t_env *e, int s, int pc, t_int val)
{
	int		i;

	i = s - 1;
	while (i <= 4 && i >= 0)
	{
		e->mem[rot_mem_set(&pc)] = val.v[i];
		rot_mem(&pc);
		--i;
	}
}

t_int		get_int_mem_pc(t_env *e, int s, int pc)
{
	t_int	val;
	int		i;

	i = s - 1;
	val.v32 = 0;
	while (i <= 4 && i >= 0)
	{
		val.v[i] = e->mem[rot_mem_set(&pc)];
		rot_mem(&pc);
		--i;
	}
	return (val);
}

t_int		get_int_mem(t_env *e, int s, int *pc)
{
	t_int	val;
	int		i;

	i = s - 1;
	val.v32 = 0;
	while (i < 4 && i >= 0)
	{
		val.v[i] = e->mem[rot_mem_set(pc)];
		rot_mem(pc);
		--i;
	}
	return (val);
}

int			get_decod_arg(t_env *e, int *pc, t_uint8 enc, int n)
{
	t_process	*p;

	p = e->current_process;
	if (p->op.info.nb_arg > n)
	{
		if (enc == T_REG_BIT)
			return ((int)get_int_mem(e, 1, pc).v8);
		else if (enc == T_DIR_BIT)
		{
			if (p->op.info.b_size_dir)
				return ((int)get_int_mem(e, 2, pc).v16);
			else
				return (get_int_mem(e, 4, pc).v32);
		}
		else if (enc == T_IND_BIT)
			return ((int)get_int_mem(e, 2, pc).v16);
	}
	return (0);
}

int			op_decod_arg(t_env *e)
{
	int			pc;
	t_process	*p;

	p = e->current_process;
	pc = p->pc;
	rot_mem(&pc);
	if (p->op.info.b_if_encod == FALSE)
	{
		if (p->op.info.b_size_dir)
			p->op.arg[0] = (int)get_int_mem(e, 2, &pc).v16;
		else
			p->op.arg[0] = get_int_mem(e, 4, &pc).v32;
	}
	else
	{
		p->op.encodage.value = (t_uint8)(get_int_mem(e, 1, &pc).v8);
		p->op.arg[0] = get_decod_arg(e, &pc, p->op.encodage.bit.a4, 0);
		p->op.arg[1] = get_decod_arg(e, &pc, p->op.encodage.bit.a3, 1);
		p->op.arg[2] = get_decod_arg(e, &pc, p->op.encodage.bit.a2, 2);
		verbose(e, V_7, "op_decod_arg: \
				pc=%d encodage=%x arg[0]=%d arg[1]=%d arg[2]=%d\n", pc,
				p->op.encodage.value, p->op.arg[0], p->op.arg[1], p->op.arg[2]);
	}
	return (pc);
}
