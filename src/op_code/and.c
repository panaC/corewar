/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:39:36 by msukhare          #+#    #+#             */
/*   Updated: 2018/06/07 15:05:52 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdio.h>
#include <stdlib.h>

int				op_and(void *e)
{
	t_process	*p;
	t_reg		tmp;

	p = ((t_env *)e)->current_process;
	if (p->op.arg[2] && p->op.arg[2] <= REG_NUMBER)
	{
		tmp.v = (p->op.arg[0] & p->op.arg[1]);
		if (tmp.v == 0)
			p->carry = 1;
		else
			p->carry = 0;
		p->reg[p->op.arg[2] - 1] = tmp;
	}
	return (0);
}
