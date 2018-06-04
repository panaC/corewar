/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 20:31:40 by pleroux           #+#    #+#             */
/*   Updated: 2018/06/02 15:56:24 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <libft.h>

t_bool			game_not_end(t_env *e)
{
	if (e->dump && e->cycle_totale == e->nb_cycle_dump)
		return (FALSE);
	return (TRUE);
}

t_bool			game_rules(t_env *e)
{
	verbose(e, V_7, "Start Game_rules\n");
	if (e->cycle >= CYCLE_TO_DIE)
	{
		verbose(e, V_5, "Cycle_to_die atteint -> reset process\n");
		ft_delete_process(e);
		e->cycle = 0;
	}
	//appel fct verification fin de cycle
	verbose(e, V_7, "End Game_rules\n");
	return (TRUE);
}
