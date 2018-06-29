/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:56:53 by pleroux           #+#    #+#             */
/*   Updated: 2018/06/21 15:09:57 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include "corewar.h"
#include "op.h"

void		process_init_instruction(t_instruc *ist)
{
	int		i;

	i = 0;
	ist->index = 0;
	ist->op_code = 0;
	ist->encodage.value = 0;
	while (i < NB_ARG)
	{
		ist->arg[i] = 0;
		++i;
	}
	ist->info = g_op_tab[16];
}

void		process_init_empty(t_process *p, int numero)
{
	int		i;

	p->live = 0;
	p->carry = 0;
	p->pc = 0;
	p->numero = numero;
	p->reg[0].v = numero * -1;
	i = 1;
	while (i < REG_NUMBER)
	{
		p->reg[i].v = 0;
		++i;
	}
	process_init_instruction(&(p->op));
}

void		process_init(t_process *p, t_process *prev, t_uint32 pc)
{
	int		i;

	i = 0;
	p->live = prev->live;
	p->carry = prev->carry;
	p->pc = pc;
	p->numero = prev->numero;
	while (i < REG_NUMBER)
	{
		p->reg[i] = prev->reg[i];
		++i;
	}
	process_init_instruction(&(p->op));
}

t_process	*process_create(t_process *prev, t_uint32 pc)
{
	t_process		*p;

	p = NULL;
	p = (t_process*)ft_memalloc(sizeof(*p));
	if (p)
	{
		process_init(p, prev, pc);
		p->next = NULL;
	}
	return (p);
}

t_process	*process_add_lst(t_process **bg, t_process *prev, t_uint32 pc)
{
	t_process	*new;

	if (!(new = process_create(prev, pc)))
		return (NULL);
	if (!(*bg))
		(*bg) = new;
	else
	{
		new->next = (*bg);
		(*bg) = new;
	}
	return (new);
}
