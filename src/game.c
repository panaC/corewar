/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 10:33:14 by pierre            #+#    #+#             */
/*   Updated: 2018/06/01 22:05:09 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "corewar.h"
#include "op.h"

static void			print_process(t_env *e)
{
	int		i;
	t_process	*tmp;

	i = 0;
	while (i < e->nb_player)
	{
		tmp = e->player[i].process;
		while (tmp)
		{
			printf("live = %d, carry = %d, pc = %d %s\n\n\n",tmp->live, tmp->carry, tmp->pc, tmp->name);
			tmp = tmp->next;
		}
		printf("player %d\n", i);
		i++;
	}
}

int					game(t_env *e)
{
	t_process		*p;

	while (game_has_process(e) && game_not_end(e))
	{
		while ((p = game_iter_process(e)))
		{
			e->current_process = p;
			p->pc = op_decod(e);
			//printf("%d live = %d, carry = %d, pc = %d %s player = %d\n\n\n",e->cycle_totale, p->live, p->carry, p->pc, p->name, p->numero);
		}
		game_rules(e);
		++e->cycle_totale;
		++e->cycle;
	}
	return (TRUE);
}
