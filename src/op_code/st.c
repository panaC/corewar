/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 06:22:36 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/20 07:13:46 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "op_code.h"
#include "corewar.h"
#include "op.h"

int			op_st(void *v, t_list *l, t_uint8 *b)
{
	t_process		*p;
	t_reg			value;
	int				i;

	(void)l;
	i = REG_SIZE;
	p = (t_process*)v;
	value.v = p->op.arg[0];
	if (p->op.encodage.bit.a3 == T_REG)
	{
		if (p->op.arg_raw[1] && p->op.arg_raw[1] > REG_NUMBER)
			return (FALSE);
		else
			p->reg[p->op.arg_raw[1] - 1] = value;
	}
	else
	{
		while (i >= 0)
		{
			b[p->pc + (p->op.arg_raw[1] % IDX_MOD)] = value.t[i];
			--i;
		}
	}
	return (TRUE);
}
