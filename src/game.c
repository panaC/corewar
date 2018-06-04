/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 10:33:14 by pierre            #+#    #+#             */
/*   Updated: 2018/06/04 13:08:52 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "corewar.h"
#include "op.h"

static void			print_process(t_env *e)
{
	int		i;
	t_process	*tmp;

	verbose(e, V_8, "print process\n");
	i = 0;
	while (i < e->nb_player)
	{
		tmp = e->player[i].process;
		while (tmp)
		{
			verbose(e, V_8, "player = %d, process = %p, live = %d, carry = %d, pc = %d\n", i + 1, tmp, tmp->live, tmp->carry, tmp->pc);
			tmp = tmp->next;
		}
		i++;
	}
}

int					game(t_env *e)
{
	t_process		*p;

	verbose(e, V_7, "Start game\n");
	while (game_has_process(e) && game_not_end(e))
	{
		verbose(e, V_6, "New Cycle %d : total %d\n", e->cycle, e->cycle_totale);
		print_process(e);
		while ((p = game_iter_process(e)))
		{
			verbose(e, V_5, "process find p = %p\n", p);
			verbose(e, V_6, "process: live = %d, carry = %d, pc = %d player = %d\n", p->live, p->carry, p->pc, p->numero);
			e->current_process = p;
			p->pc = op_decod(e);
		}
		game_rules(e);
		++e->cycle_totale;
		++e->cycle;
	}
	verbose(e, V_7, "End game\n");
	return (TRUE);
}
