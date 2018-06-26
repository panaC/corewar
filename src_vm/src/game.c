/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 10:33:14 by pierre            #+#    #+#             */
/*   Updated: 2018/06/26 12:09:39 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "corewar.h"
#include "op.h"
#include "graphi.h"

static void		print_process(t_env *e)
{
	int			i;
	t_process	*tmp;

	verbose(e, V_8, "print process\n");
	i = 0;
	while (i < e->nb_player)
	{
		tmp = e->player[i].process;
		while (tmp)
		{
			verbose(e, V_8, "player = %d, process = %p, live = %d, carry = %d "\
					", pc = %d\n", i + 1, tmp, tmp->live, tmp->carry, tmp->pc);
			tmp = tmp->next;
		}
		i++;
	}
}

static void		print_info_process(t_env *e, t_process *p)
{
	verbose(e, V_7, "INFO Process %p player %d: live=%d, carry=%d, pc=%d\n",
			p, p->numero, p->live, p->carry, p->pc);
	verbose(e, V_7, "INFO Process reg 1 a 16: 0:%d 1:%d 2:%d 3:%d 4:%d 5:%d" \
			"6:%d 7:%d 8:%d 9:%d 10:%d 11:%d 12:%d 13:%d 14:%d 15:%d\n",
			p->reg[0].v, p->reg[1].v, p->reg[2].v, p->reg[3].v, p->reg[4].v,
			p->reg[5].v, p->reg[6].v, p->reg[7].v, p->reg[8].v, p->reg[9].v,
			p->reg[10].v, p->reg[11].v, p->reg[12].v, p->reg[13].v,
			p->reg[14].v, p->reg[15].v);
}

int				game(t_env *e)
{
	t_process	*p;
	t_graphi	*info;

	verbose(e, V_7, "Start game\n");
	if (e->visu == 1 && !(info = ft_init_ncurses()))
		return (FALSE);
	while (game_has_process(e) && game_not_end(e))
	{
		verbose(e, V_3, "New Cycle %d : total %d : next cycle_to_die %d\n",
				e->cycle, e->cycle_totale, e->cycle_to_die);
		print_process(e);
		(e->visu == 1) ? ft_put_arena(info, e, 1) : 0;
		game_rules(e);
		while ((p = game_iter_process(e)))
		{
			print_info_process(e, p);
			verbose(e, V_5, "process find p = %p pc=%d\n", p, p->pc);
			e->current_process = p;
			op_decod(e);
			print_info_process(e, p);
		}
	}
	(e->visu == 1) ? print_winner_in_window(e, info) : 0;
	verbose(e, V_7, "End game\n");
	return (TRUE);
}
