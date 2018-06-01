/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 07:08:25 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/20 07:38:23 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "op_code.h"
#include "corewar.h"
#include "op.h"

int			op_ld(void *v, t_list *l, t_uint8 *b)
{
	t_process		*p;
	t_reg			value;
	int				i;

	(void)l;
	(void)b;
	i = REG_SIZE;
	p = (t_process*)v;
	if (p->op.arg_raw[1] && p->op.arg_raw[1] > REG_NUMBER)
		return (FALSE);
	else
	{
		value.v = p->op.arg[0];
		p->reg[p->op.arg_raw[1] - 1] = value;
	}
	return (TRUE);
}
