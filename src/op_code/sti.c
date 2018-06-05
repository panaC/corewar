/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 22:54:54 by pleroux           #+#    #+#             */
/*   Updated: 2018/06/04 18:15:46 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "op_code.h"
#include "corewar.h"
#include "op.h"
#include <ft_printf.h>

int			op_sti(void *e)
{
	t_process		*p;
	t_reg			value;
	t_uint32		addr;
	int				i;

	i = REG_SIZE - 1;
	p = ((t_env*)e)->current_process;
	value.v = p->op.arg[0];
	addr = p->op.arg[1] + p->op.arg[2];
	while (i >= 0)
		((t_env*)e)->mem[rot_mem(&addr) - 1] = value.t[--i];
	return (TRUE);
}
