/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 15:12:36 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/19 23:47:08 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "op_code.h"
#include "corewar.h"
#include "op.h"

int			op_add(void *v, t_list *l, t_uint8 *b)
{
	t_process	*p;
	t_reg		r;

	(void)l;
	(void)b;
	p = (t_process*)v;
	r.v = p->op.arg[0] + p->op.arg[1];
	if (p->op.arg_raw[2] && p->op.arg_raw[2] < REG_NUMBER)
	{
		p->reg[p->op.arg_raw[2] - 1] = r;
	}
	else
	{
		return (FALSE);
	}
	return (TRUE);
}
