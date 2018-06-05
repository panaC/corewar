/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 07:08:25 by pleroux           #+#    #+#             */
/*   Updated: 2018/06/05 15:39:42 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "op_code.h"
#include "corewar.h"
#include "op.h"

int			op_ld(void *e)
{
	t_process		*p;

	p = ((t_env*)e)->current_process;
	if (p->op.arg_raw[1] && p->op.arg_raw[1] < REG_NUMBER)
	{
		p->reg[p->op.arg_raw[1] - 1].v = p->op.arg[0];
		if (p->reg[p->op.arg_raw[1] - 1].v == 0)
			p->carry = 1;
	}
	return (FALSE);
}
