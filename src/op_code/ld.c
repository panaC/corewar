/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 07:08:25 by pleroux           #+#    #+#             */
/*   Updated: 2018/06/01 22:00:57 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "op_code.h"
#include "corewar.h"
#include "op.h"

int			op_ld(void *e)
{
	t_process		*p;
	t_reg			value;
	int				i;

	i = REG_SIZE;
	p = ((t_env*)e)->current_process;
	if (p->op.arg_raw[1] && p->op.arg_raw[1] > REG_NUMBER)
		return (FALSE);
	else
	{
		value.v = p->op.arg[0];
		p->reg[p->op.arg_raw[1] - 1] = value;
	}
	return (TRUE);
}
