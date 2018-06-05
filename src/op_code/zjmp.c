/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 14:07:20 by msukhare          #+#    #+#             */
/*   Updated: 2018/06/05 14:53:11 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdio.h>
#include <stdlib.h>

int		op_zjmp(void *e)
{
	t_process	*p;

	p = ((t_env*)e)->current_process;
	if (p->carry != 1)
		return (FALSE);
	p->pc = p->pc + (p->op.arg[0] % IDX_MOD);
	return (TRUE);
}
