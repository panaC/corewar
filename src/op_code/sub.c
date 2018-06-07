/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 15:54:06 by pleroux           #+#    #+#             */
/*   Updated: 2018/06/07 15:02:42 by pleroux          ###   ########.fr       */
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

	p = ((t_env*)e)->current_process;
	r.v = p->op.arg[0] - p->op.arg[1];
	if (p->op.arg[2] && p->op.arg[2] < REG_NUMBER)
	{
		p->reg[p->op.arg[2] - 1] = r;
		if (r.v == 0)
			p->carry = TRUE;
	}
	return (FALSE);
}
