/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 20:31:40 by pleroux           #+#    #+#             */
/*   Updated: 2018/06/04 14:26:58 by pierre           ###   ########.fr       */
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
	return (TRUE);
}

t_bool			game_rules(t_env *e)
{
	verbose(e, V_7, "Start Game_rules\n");
	if (e->cycle >= e->cycle_to_die)
	{
		if (e->nb_live >= NBR_LIVE)
		{
			e->nb_live = 0;
			e->cycle_to_die -= CYCLE_DELTA;
			verbose(e, V_3, "NBR_LIVE atteint -> cycle_to_die = %d\n", e->cycle_to_die);
		}
		else
			++e->check;
		verbose(e, V_3, "Cycle_to_die atteint -> reset process\n");
		ft_delete_process(e);
		e->cycle = 0;
	}
	//appel fct verification fin de cycle
	verbose(e, V_7, "End Game_rules\n");
	return (TRUE);
}
