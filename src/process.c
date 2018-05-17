/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:56:53 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/16 23:05:46 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "corewar.h"

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
	ist->info = op_tab[16];
	ist->ft = NULL;
}

void		process_init_empty(t_process *p, int numero)
{
	int		i;

	p->live = 0;
	p->carry = 0;
	p->pc = 0;
	p->reg[0] = numero;
	i = 1;
	while (i < REG_NUMBER)
	{
		p->reg[i] = 0;
		++i;
	}
	p->op = process_init_instruction();
}

void		process_init(t_process *p, t_process *prev, t_uint32 pc)
{
	int		i;

	i = 0;
	p->live = prev->live;
	p->carry = prev->carry;
	p->pc = pc;
	while (i < REG_NUMBER)
	{
		p->reg[i] = prev->reg[i];
		++i;
	}
	p->op = init_instruction();
}

t_process	*process_create(t_process *prev, t_uint32 pc)
{
	t_process		*p;

	p = NULL;
	p = (t_process*)ft_memalloc(sizeof(*p));
	if (p)
	{
		process_init(p, prev, pc);
	}
	return (process);
}

t_process	*process_add_lst(t_list **l, t_process *prev, t_uint32 pc)
{
	t_process		*p;
	t_list			*n;

	p = process_create(prev, pc);
	if (p)
	{
		n = (t_list*)ft_memalloc(sizeof(*n));
		if (n)
		{
			n->next = NULL;
			n->content = (void*)p;
			n->content_size = sizeof(*p);
			ft_lstadd(l, n);
		}
		else
		{
			free(p);
			p = NULL;
		}
	}
	return (p);
}