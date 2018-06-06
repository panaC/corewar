/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 09:28:49 by msukhare          #+#    #+#             */
/*   Updated: 2018/06/06 11:57:39 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>
#include "op_code.h"
#include "corewar.h"
#include "op.h"

static void		ft_put_live_in_pro(t_process *p, void *e, int first)
{
	ft_printf("i am %s alive bitch", ((t_env *)e)->player[p->numero].name);
	((t_env *)e)->player[p->numero].last_live = ((t_env *)e)->cycle_totale;
	((t_env *)e)->player[p->numero].nb_live++;
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

	i = 0;
	p = ((t_env *)e)->current_process;
	if (p->op.arg[0] == p->numero)
	{
		ft_put_live_in_pro(p, e, 1);
		return (FALSE);
	}
	while (i < ((t_env *)e)->nb_player)
	{
		if (((t_env *)e)->player[i].process->numero == p->op.arg[0])
		{
			ft_put_live_in_pro(((t_env *)e)->player[i].process, e, 0);
			return (FALSE);
		}
		++i;
	}
	return (FALSE);
}
