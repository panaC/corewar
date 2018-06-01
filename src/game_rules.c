/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 20:31:40 by pleroux           #+#    #+#             */
/*   Updated: 2018/06/01 21:00:02 by pleroux          ###   ########.fr       */
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
	if (e->cycle >= CYCLE_TO_DIE)
	{
		ft_delete_process(e);
		e->cycle = 0;
	}
	//appel fct verification fin de cycle
	return (TRUE);
}
