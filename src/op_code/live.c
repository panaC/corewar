/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 09:28:49 by msukhare          #+#    #+#             */
/*   Updated: 2018/06/08 17:27:33 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>
#include "op_code.h"
#include "corewar.h"
#include "op.h"

static void		ft_put_live_in_pro(t_process *p, void *e, int first)
{
	ft_printf("INFO : I am %s and i am alive bitch\n",
			((t_env *)e)->player[p->numero - 1].name);
	((t_env *)e)->player[p->numero - 1].last_live = ((t_env *)e)->cycle_totale;
	((t_env *)e)->nb_live++;
	if (first == 1)
	{
		p->live = 1;
		return ;
	}
	while (p)
	{
		if (p->live == 0)
		{
			p->live = 1;
			return ;
		}
		p = p->next;
	}
}

int				op_live(void *e)
{
	t_process	*p;
	int			i;
	int			pc;

	i = 0;
	p = ((t_env *)e)->current_process;
	pc = op_decod_arg((t_env*)e);
	if (p->op.arg[0] == (int)(p->numero * - 1))
	{
		ft_put_live_in_pro(p, e, 1);
		p->pc = pc;
		return (TRUE);
	}
	while (i < ((t_env *)e)->nb_player)
	{
		if (((((t_env *)e)->player[i].process->numero) * -1) == p->op.arg[0])
		{
			ft_put_live_in_pro(((t_env *)e)->player[i].process, e, 0);
			p->pc = pc;
			return (TRUE);
		}
		++i;
	}
	p->pc = pc;
	return (TRUE);
}
