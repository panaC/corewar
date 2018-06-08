/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 20:31:40 by pleroux           #+#    #+#             */
/*   Updated: 2018/06/08 18:38:07 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <libft.h>

t_bool			game_not_end(t_env *e)
{
	if (e->dump && e->cycle_totale == e->nb_cycle_dump)
	{
		e->win_player = -1;
		return (FALSE);
	}
	if (e->cycle_to_die < 0)
	{
		return (FALSE);
	}
	return (TRUE);
}

t_bool			game_rules(t_env *e)
{
	verbose(e, V_7, "Start Game_rules\n");
	if (e->cycle >= e->cycle_to_die)
	{
		if (e->nb_live >= NBR_LIVE)
		{
			e->cycle_to_die -= CYCLE_DELTA;
			verbose(e, V_3, "NBR_LIVE atteint a %d\n", e->cycle_to_die);
		}
		else if (e->check >= MAX_CHECKS)
		{
			e->check = 0;
			e->cycle_to_die -= CYCLE_DELTA;
		}
		else
			e->check++;
		verbose(e, V_3, "Cycle_to_die atteint -> reset process\n");
		ft_delete_process(e);
		e->nb_live = 0;
		e->cycle = 0;
	}
	verbose(e, V_7, "End Game_rules\n");
	return (TRUE);
}
