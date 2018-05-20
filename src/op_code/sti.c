/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 22:54:54 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/20 04:06:54 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "op_code.h"
#include "corewar.h"
#include "op.h"
#include <ft_printf.h>

int			op_sti(void *v, t_list *l, t_uint8 *b)
{
	t_process		*p;
	t_reg			value;
	t_uint32		addr;
	int				i;

	(void)l;
	i = REG_SIZE - 1;
	p = (t_process*)v;
	value.v = p->op.arg[0];
	addr = p->op.arg[1] + p->op.arg[2];
	ft_printf("sti: out %u addr %u\n", value.v, addr);
	while (i >= 0)
	{
		b[rot_mem(&addr) - 1] = value.t[i];
		--i;
	}
	return (TRUE);
}
