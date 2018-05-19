/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 15:12:36 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/19 15:53:44 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "op_code.h"
#include "corewar.h"
#include "op.h"

int			op_add(void *v)
{
	t_process	*p;
	t_reg		r;

	p = (t_process*)v;
	r.v = p->op.arg[0] + p->op.arg[1];
	if (p->op.arg_raw[2] && p->op.arg_raw[2] < REG_NUMBER)
	{
		p->reg[p->op.arg_raw[2]] = r;
	}
	else
	{
		return (FALSE);
	}
	return (TRUE);
}
